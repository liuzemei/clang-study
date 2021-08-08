#include "stack.h"

bool_t is_empty(list_t *list){
  return list->head == NULL ? True : False;
}

bool_t push(node_t *new, list_t *list){
  if(list == NULL) return False;
  node_t *cur = list->head;
  while(True){
    if(cur->next == NULL){
      cur->next = new;
      return True;
    }
    cur = cur->next;
  }
  return False;
}

node_t* pop(list_t *list){
  if(is_empty(list) == True) return NULL;
  node_t *cur = list->head;
  node_t *next = cur->next;
  if(next == NULL){
    
  }
  
  while(True){
    if(next == NULL) {
      cur->next = NULL;
      return next;
    }
  }



  
}