/*
Derlemek icin:
gcc -pthread semaphore.c -o semrun
*/

#include <stdio.h>          /* printf()                 */
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <errno.h>          /* errno, ECHILD            */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait().. */
#include <fcntl.h>          /* O_CREAT, O_EXEC          */
#include <unistd.h>         /* fork(), sleep() */
#include <sys/wait.h>       /* waitpid() */

int main (int argc, char **argv){
    int i;                        /*      loop variables          */
    key_t shmkey;                 /*      shared memory key       */
    int shmid;                    /*      shared memory id        */
    sem_t *sem;                   /*      synch semaphore         *//*shared */
    pid_t pid;                    /*      fork pid                */
    int *p;                       /*      shared variable         *//*shared */
    unsigned int n;               /*      fork count              */
    unsigned int value;           /*      semaphore value         */

    /* initialize a shared variable in shared memory */
    shmkey = ftok ("/dev/null", 5);       /* valid directory name and a number */
    printf ("shmkey for p = %d\n", shmkey);
    shmid = shmget (shmkey, sizeof (int), 0644 | IPC_CREAT);
    if (shmid < 0){                           /* shared memory error check */
        perror ("shmget\n");
        exit (1);
    }

    p = (int *) shmat (shmid, NULL, 0);   /* attach p to shared memory */
    *p = 0;
    printf ("p=%d is allocated in shared memory.\n\n", *p);

    /********************************************************/

    n = 5; // Fork count

    value = 1; // Semaphore initial value

    /* initialize semaphores for shared processes */
    sem = sem_open ("pSem", O_CREAT | O_EXCL, 0644, value); 
    /* name of semaphore is "pSem", semaphore is reached using this name */
    sem_unlink ("pSem");      
    /* unlink prevents the semaphore existing forever */
    /* if a crash occurs during the execution         */
    printf ("semaphore initialized.\n\n");

    /******************************************************/
    /******** PARENT PROCESS ENTERS CRITICAL SECTION FIRST ********/
    /******************************************************/
    
    pid = fork();   /* first fork for parent */

    if (pid != 0){  /* parent process */

        /* parent enters critical section 5 times BEFORE creating rest of children */
        for (int j = 0; j < 5; j++) {
            sem_wait(sem);                /* P operation */
            sleep(1);                     /* simulate work */
            printf("Parent is in Critical section\n");
            *p -= 1;                      /* decrement *p by 1 */
            printf("Parent: new value of *p = %d\n", *p);
            sem_post(sem);                /* V operation */
        }

        /* fork remaining child processes (excluding first) */
        for (i = 1; i < n; i++){
            pid = fork();
            if (pid < 0)              /* check for error      */
                printf ("Fork error.\n");
            else if (pid == 0)
                break;                  /* child processes */
        }

        /* wait for all children to exit */
        while ((pid = waitpid(-1, NULL, 0)) > 0) {
            if (errno == ECHILD)
                break;
        }

        printf ("\nParent: All children have exited.\n");

        /* shared memory detach */
        shmdt(p);
        shmctl(shmid, IPC_RMID, 0);

        /* cleanup semaphores */
        sem_destroy(sem);
        exit(0);
    }

    /******************************************************/
    /******************   CHILD PROCESS   *****************/
    /******************************************************/
    else{
        sem_wait (sem);           /* P operation */
        printf ("  Child(%d) is in critical section.*p=%d.\n", i, *p);
        *p += 1;                  /* increment *p by 1 */
        sleep (1);
        printf ("  Child(%d) new value of *p=%d.\n", i, *p);
        sem_post (sem);           /* V operation */
        exit (0);
    }
}
