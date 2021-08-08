#include <stdio.h>
#include "tree.h"

int main(void){
	//定义数组，将一些数值存放到数组里
	int node_list[]={6,9,7,4,5,2,1,8,12};
	//定义一颗空树
	tree_t root=NULL;
	int i = 0;
	root = create_tree(root, node_list, 9);
  root = del_node(root,4);
	print_tree(root);
	return 0;
}
