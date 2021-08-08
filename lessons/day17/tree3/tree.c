#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

static void *create_node(int val) {
	node_t *new=(node_t *)malloc(sizeof(node_t));
	new->data=val;
	new->r=NULL;
	new->l=NULL;
	return (void *)new;
}

//将new指向的节点插入到tree这棵树中
tree_t insert_node(tree_t root,node_t *new) {
	//向空树插入一个节点
	if(root==NULL)	return new;
	//不是空树的情况
	//找位置，将节点插入的位置
	node_t *cur,*par;
	cur=root;
	while(cur!=NULL){
		par=cur;
		(cur->data>new->data)?(cur=cur->l):(cur=cur->r);
	}	
	(par->data>new->data)?(par->l=new):(par->r=new);
	return root;
}


tree_t create_tree(tree_t root,int *data,int len) {
	int i;
	node_t *n;
	for(i=0;i<len;i++) {
		n=(node_t *)create_node(data[i]);
		root=insert_node(root,n);
	}
	return root;
}

void print_tree(tree_t node) {
	if(node != NULL) {
		print_tree(node->l);
		print_tree(node->r);
		printf("%d\n", node->data);
	}
}

tree_t find_node(tree_t p, int val) {
	node_t *current_p = p;
	while(current_p!=NULL){
		if(current_p->data == val) return p;
		current_p = val > current_p->data ? current_p->r : current_p->l;
	}
	return NULL;
}

tree_t del_node(tree_t root,int val) {
	if(root == NULL) return NULL;
	if(val > root->data) root->l = del_node(root->l, val);
	else if (val < root->data) root->r = del_node(root->r, val);
	// 找到了要删除的节点
	else {
		// 1. 如果没有子节点，则直接删除
		if (root->l == NULL && root->r == NULL) {
			free(root);
			root = NULL;
		}
		// 2. 如果有左子树 则找到左子树的最右节点，替换掉当前的值，并删除左子树最右节点。
		else if (root->l) {
			node_t * tmp;
			for(tmp = root->l;tmp->r;tmp = tmp->r);
			root->data = tmp->data;
			free(tmp);
			tmp = NULL;
		}
		// 3. 如果没有左子树，且有右子树 则找到右子树的最左节点，替换掉当前的值，并删除右子树最左节点。
		else if (root->r) {
			node_t * tmp;
			for(tmp = root->r;tmp->l;tmp = tmp->l);
			root->data = tmp->data;
			free(tmp);
			tmp = NULL;
		}
	}
	return root;
}