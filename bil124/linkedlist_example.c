#include<stdio.h>
#include<stdlib.h>


struct Node{
	int data;
	struct Node *next;
};


void insertBeginning(struct Node **head, int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	
	newNode->next = *head;
	
	*head = newNode;
	
}

void insertEnd(struct Node **head, int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode -> data= data;
	
	newNode->next = NULL;
	
	if (*head==NULL){
		*head=newNode;
		return;
	}
	
	struct Node *current= *head;
	while (current->next !=NULL){
		current = current->next;
	}


	current->next = newNode;

}


void printList(struct Node *head){
	
	struct Node *current = head;
	
	while(current !=NULL){
		printf("%d ->",current->data);
		current = current->next;
	}
	printf("NULL\n");
	
	
}


int main(){
	
	struct Node *head = NULL;
	
	insertBeginning(&head,10);
	insertEnd(&head,20);
	insertEnd(&head,30);
	insertEnd(&head,40);
	insertEnd(&head,50);	
	
	printf("Linked list: ");
	printList(head);
	
	
	return 0;
}












