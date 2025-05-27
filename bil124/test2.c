#include<stdio.h>
#include<stdlib.h>

struct Node{
	
	int data;
	struct Node *next;
};

void insertTop(struct Node **head,int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	
	newNode->next = *head;
	
	*head = newNode;
	
}


void insertEnd(struct Node **head,int data){
	
	struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	
	newNode->next = NULL;
	
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	//sıçtın
	struct Node *current = *head;	//here
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newNode;
	
}


void printList(struct Node *head){
	
	struct Node *current = head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next; 
	}
	
}


int main(){
	
	struct Node *head=NULL;
	
	insertTop(&head,10);
	insertEnd(&head,20);
	insertEnd(&head,30);
	insertEnd(&head,40);

	printList(head);
		
	return 0;
}







