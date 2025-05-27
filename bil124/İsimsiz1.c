#include<stdio.h>
#include<stdlib.h>

struct StackNode{
	int data;
	struct StackNode *next;
};

struct StackNode *NewNode(int data){
	
	struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
	
	node->data =data;
	node->next = NULL;
	
	return node;
}

int isEmpty(struct StackNode *head){
	return !head;
}

void push(struct StackNode **head,int data){
	
	struct StackNode *node = NewNode(data);
	
	node->next = *head;
	*head = node;
	
}

int pop(struct StackNode **head){
	
	struct StackNode *temp= *head;
	int popped= temp->data;
	
	*head=(*head)->next;
	free(temp);
	
	return popped;
}

int peek(struct StackNode *head){return head->data;}

void printStack(struct StackNode **head){
	
	if(isEmpty(*head))
		return -1;
		
	struct StackNode *current = *head;
	
	while(current!=NULL){
		printf("%d\n",current->data);
		current=current->next;
	}
}

int main(){
	
	struct StackNode *head;
	
	push(&head,10);
	push(&head,20);
	peek(&head);
	pop(&head);
	push(&head,30);
	
	
	return 0;
}



