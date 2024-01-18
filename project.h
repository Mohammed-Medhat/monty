#ifndef PROJECT_H
#define PROJECT_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int data;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack_head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_files(char *file);
int parse_lines(char *buffer, int line_number, int format);
void read_files(FILE *);
int len_characters(FILE *);
void find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int data);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line_number);
void push_to_stack(stack_t **stack, unsigned int line_number);
void push_to_queue(stack_t **queue, unsigned int line_number);

void call_function(op_func func, char *opcode, char *value, int line_number, int format);

void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);

/*Math operations with nodes*/
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply_nodes(stack_t **stack, unsigned int line_number);
void modulus_nodes(stack_t **stack, unsigned int line_number);

/*String operations*/
void print_character(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);

/*Error handling*/
void error_handler(int error, ...);
void more_error_handler(int error, ...);
void string_error_handler(int error, ...);
void rotate_right(stack_t **stack, unsigned int line_number);

#endif
