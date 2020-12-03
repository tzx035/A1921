#include <stdio.h>
#include "malloc.h"
#include "assert.h"


typedef struct tag_link
{
	int data;
	struct tag_link* next;
}Link;

typedef struct tag_Stack
{
	Link* head;
	int size;
} Stack;
void StackInit(Stack* stack )
{
	stack->head=NULL;
	stack->size=0;
}

void StackPush(Stack* stack,int data)
{
	Link* link = (Link*)malloc(sizeof(Link));
	assert(link != NULL);
	link->next=stack->head;
	link->data=data;
	stack->head=link;
	stack->size++;
}
int StackEmpty(Stack* stack)
{
	return stack->size==0;
}
int StackPop(Stack* stack, int* data)
{
	Link* link=stack->head;
	if (StackEmpty(stack))
	{
		return 0;
	}
	
	*data = stack->head->data;
	stack->head=stack->head->next;
	free(link);
	stack->size--;
	return 1;
}

void StackClear(Stack* stack)
{
	int i;
	while(!StackEmpty(stack))
	{
		StackPop(stack,&i);
	}
}

int main()
{
	int i=0;
	Stack stack;
	StackInit(&stack);
	for (i=0;i<5;i++)
	{
		StackPush(&stack,i);
	}
	while(!StackEmpty(&stack))
	{
		StackPop(&stack,&i);
		printf("%d\n",i);
	}

	return 0;

} 
