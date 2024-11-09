#include "monty.h"

/**
 * push - Push an element onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    stack_t *new;

    if (!arg || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = atoi(arg);
    new->prev = NULL;

    if (queue_mode)
    {
        new->next = NULL;
        if (*stack)
        {
            stack_t *temp = *stack;
            while (temp->next)
                temp = temp->next;
            temp->next = new;
            new->prev = temp;
        }
        else
            *stack = new;
    }
    else
    {
        new->next = *stack;
        if (*stack)
            (*stack)->prev = new;
        *stack = new;
    }
}

/**
 * pall - Print all elements in the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * pint - Print the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}