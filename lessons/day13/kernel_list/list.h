#ifndef KERNEL_LIST_H_
#define KERNEL_LIST_H_
struct list_head {
    struct list_head *next, *prev;
};

static inline void INIT_LIST_HEAD(struct list_head *list) {
  list->next = list;
  list->prev = list;
}

static inline int list_empty(const struct list_head *head){
  return head->next == head;
}

static inline void __list_add(struct list_head *new_node, struct list_head *prev, struct list_head *next){
  next->prev = new_node;
  new_node->next = next;
  new_node->prev = prev;
  prev->next = new_node;
}

static inline void list_add(struct list_head *new_node, struct list_head *head){
  __list_add(new_node, head, head->next);
}

static inline void list_add_tail(struct list_head *new_node, struct list_head *tail){
  __list_add(new_node, tail->prev, tail);
}

static inline void __list_del(struct list_head *prev, struct list_head *next){
  next->prev = prev;
  prev->next = next;
}

static inline void list_dev(struct list_head *entry){
  __list_del(entry->prev, entry->next);
  entry->prev = NULL;
  entry->next = NULL;
}

#endif
