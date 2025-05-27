#include<stdlib.h>
#include<stdio.h>
#include "fonPro.h"
/*
struct StackNode{
	int data;
	struct StackNode *next;
};


struct StackNode *newNode(int data){
	
	struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
	
	node->data = data;
	node->next = NULL;
	
	return node;
}


int isEmpty(struct StackNode *head){
	
	return !head;
}

int pop(struct StackNode **head){
	
	
	if(isEmpty(*head))
		return -1;
			
	struct StackNode *temp = *head;
	
	int popped = temp->data;
	
	*head = (*head)->next;
	free(temp);
	
	return popped;	
}

void push(struct StackNode **head,int data){
	
	struct StackNode *node = newNode(data);
	
	node->next = *head;
	*head = node;
	
	printf("eklendi %d push\n ",node->data);
	
}


int peek(struct StackNode *head){return head->data;}

void printStack(struct StackNode *head){
	
	struct StackNode *current = head;
	
	while(current != NULL){
		printf("%d\n",current->data);
		current=current->next;
	}
	
}
*/
int main(){
	
	struct StackNode *head=NULL;
	
	push(&head,10);
	push(&head,20);
	push(&head,30);
	pop(&head);
	printStack(head);
	
	return 0;
}













