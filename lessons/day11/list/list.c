#include "list.h"
void show_node(node_t *n){
  if (n != NULL) {
    printf("data=%d\n", n->data);
  }
  return;
}

void *create_node(){
  node_t *n;
  n = malloc(sizeof(node_t));
  if (n == NULL)
  {
    printf("malloc failed...\n");
    return NULL;
  }
  return n;
}

void destory_node(node_t *n){
  if (n != NULL)
  {
    free(n);
    n = NULL;
  }
  return;
}

void init_node(node_t *n, int v){
  if(n!=NULL){
    n->data = v;
    n->next = NULL;
  }
  return;
}