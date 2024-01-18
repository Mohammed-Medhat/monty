#include "project.h"

stack_t *stack_head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_files(argv[1]);
    free_nodes();
    return (0);
}

/**
 * create_node - Creates a node.
 * @data: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *create_node(int data)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        error_handler(4);
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *tmp;

    if (stack_head == NULL)
        return;

    while (stack_head != NULL)
    {
        tmp = stack_head;
        stack_head = stack_head->next;
        free(tmp);
    }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void push_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}
