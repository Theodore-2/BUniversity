


struct StackNode{
	int data;
	struct StackNode *next;
}

struct StackNode *NewNode(int data);
int isEmpty(struct StackNode *head);
void push(struct StackNode **head, int data);
int pop(struct StackNode **head);
int peek(struct StackNode *head);
void printS(struct StackNode **head);
