#include <stdio.h>
typedef struct {
  node_t *head;
} list_t;

typedef struct {
  int h;
  node_t *next;
} node_t;

typedef enum {False, True} bool_t;

bool_t is_empty(list_t *);

bool_t push(node_t *, list_t *);

node_t* pop(list_t *h);


