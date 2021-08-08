#include <stdlib.h>


struct tree {
  struct tree *left;
  int data;
  struct tree *right;
};

typedef struct tree treenode;

treenode *b_tree;

void insert_node(int node) {
  treenode newnode;
  treenode currentnode;
  treenode parentnode;

  // newnode = (treenode*) malloc(sizeof(treenode));
  
}

