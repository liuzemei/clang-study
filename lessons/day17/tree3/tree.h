#ifndef TREE_H_
#define TREE_H_
typedef struct node{
	int data;
	struct node *l,*r;
}node_t;
typedef node_t *tree_t;
tree_t create_tree(tree_t root,int *data,int len);
tree_t del_node(tree_t root,int val);
void print_tree(tree_t node);
#endif
