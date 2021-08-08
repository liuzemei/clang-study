#ifndef LIST_H_
#define LIST_H_
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

typedef struct node node_t;
typedef node_t *list_t;


void show_node(node_t *);
void *create_node();
void destroy_node(node_t *n);
void init_node(node_t *n, int v);

extern int count;

#endif
