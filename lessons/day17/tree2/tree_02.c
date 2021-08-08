
#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
  int left;
  int data;
  int right;
} treenode;

treenode b_tree[15];

void create_btree(int *nodelist, int len){
  int i; 
  int level; // 树的阶层数
  int position; // 左树 -1，右树 +1

  b_tree[0].data = nodelist[0]; // 以第一个元素为根节点
  for (i=1;i<len;i++) {
    b_tree[i].data = nodelist[i]; // 将元素值存入节点
    level = 0; // 从树根开始
    position = 0; // 设置 position 值
    while(position == 0) { // 寻找节点位置
      // 判断是左子树 还是 右子树
      if(nodelist[i] > b_tree[level].data) {
        // 右树是否有下一阶层
        if (b_tree[level].right!=-1) level=b_tree[level].right;
        else position = -1; // 设置为右树
      } else {
        // 左树是否有下一阶级
        if (b_tree[level].left!=-1) level=b_tree[level].left;
        else position = 1;// 设为左树
      }
    }
    if (position == 1) b_tree[level].left = i; // 连接左子树
    else b_tree[level].right = i; // 连接右子树
  }
}

int main() {
  int i,index;
  int data; // 读入输入值所使用的暂存变量
  int nodelist[16]; // 声明存储输入数据的数组

  printf("\n Please input the elements of binary tree(Exit for 0): \n");

  index=1;

  // 读取数值存到数值中
  scanf("%d", &data); // 读取输入值存到变量 data

  while (data != 0) { // 读取尚未结束
    nodelist[index] = data;
    index = index+1;
    scanf("%d", &data);
  }

  for (i=0;i<15;i++) {
    b_tree[i].data = 0;
    b_tree[i].left = -1;
    b_tree[i].right = -1;
  }

  create_btree(nodelist, index);

  printf("\n The binary tree content: \n");
  printf("   left    data   right   \n");
  printf("==========================\n");
  for (i=1;i<15;i++) 
  printf("%2d: [%2d] [%2d] [%2d] \n", i, b_tree[i].left,b_tree[i].data,b_tree[i].right);
  

  
  return 0;
}
