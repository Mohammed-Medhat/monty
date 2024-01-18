#include "project.h"

/**
 * push_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_number: Integer representing the line number of the opcode.
 */
void push_to_stack(stack_t **new_node, unsigned int line_number)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);

    if (stack_head == NULL)
    {
        stack_head = *new_node;
        return;
    }

    tmp = stack_head;
    stack_head = *new_node;
    stack_head->next = tmp;
    tmp->prev = stack_head;
}

/**
 * print_stack - Prints all elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    (void)line_number;

    if (stack == NULL)
        exit(EXIT_FAILURE);

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

/**
 * pop_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
        more_error_handler(7, line_number);

    tmp = *stack;
    *stack = tmp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(tmp);
}

/**
 * print_top - Prints the data of the top node in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
        more_error_handler(6, line_number);

    printf("%d\n", (*stack)->data);
}
