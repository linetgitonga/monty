#include "monty.h"
/**
 * 
* free_stack -it does frees a doubly linked list
* @head: head of the stack
* Author:Linet Gitonga
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
