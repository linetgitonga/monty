#include "monty.h"
/**
 * f_pstr - should prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * Authir :Linet Gitonag
 * @counter: line_number
 * Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
