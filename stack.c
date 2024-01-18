#include "project.h"

/**
 * multiply_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void multiply_nodes(stack_t **stack, unsigned int line_number)
{
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_error_handler(8, line_number, "mul");

    (*stack) = (*stack)->next;
    product = (*stack)->data * (*stack)->prev->data;
    (*stack)->data = product;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * modulus_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void modulus_nodes(stack_t **stack, unsigned int line_number)
{
    int result;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_error_handler(8, line_number, "mod");

    if ((*stack)->data == 0)
        more_error_handler(9, line_number);

    (*stack) = (*stack)->next;
    result = (*stack)->data % (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
