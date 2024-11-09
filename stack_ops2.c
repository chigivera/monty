#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Add the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - Do nothing
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * is_number - Check if a string is a valid number
 * @str: string to check
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
    if (!str)
        return (0);

    if (*str == '-')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}