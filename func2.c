#include "monty.h"

/**
 * f_queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void f_queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * f_stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void f_stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * f_add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void f_add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	f_pop(doubly, cline);
}

/**
 * f_nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void f_nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * f_sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void f_sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	f_pop(doubly, cline);
}
