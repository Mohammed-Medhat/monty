#include "project.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "swap");

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = *stack;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->data + (*stack)->prev->data;
    (*stack)->data = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "sub");

    (*stack) = (*stack)->next;
    result = (*stack)->data - (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * divide - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void divide(stack_t **stack, unsigned int line_number)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "div");

    if ((*stack)->data == 0)
        more_err(9, line_number);

    (*stack) = (*stack)->next;
    result = (*stack)->data / (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

