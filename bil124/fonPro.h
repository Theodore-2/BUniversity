#include "functions.c"



int peek(struct StackNode *head);
void printStack(struct StackNode *head);
void push(struct StackNode **head,int data);
int pop(struct StackNode **head);
int isEmpty(struct StackNode *head);
struct StackNode *newNode(int data);
