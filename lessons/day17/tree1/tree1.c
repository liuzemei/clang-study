
#include <stdio.h>

// 建立二叉树

void create_btree(int *b_tree, int *nodelist, int len) {
  int i;
  int level; // 树的阶层
  b_tree[1] = nodelist[1]; // 以第一个元素为根节点

  for (i=2;i<len;i++) {
    level = 1; // 从阶层 1 开始建立
    while(b_tree[level] != 0) { // 判断是否有子树存在
      // 如果list里的数据小于子树节点 就放到子树的左节点 否则放到子树的右节点
      level = nodelist[i]<b_tree[level] ? level * 2 : level * 2 + 1;
    }
    b_tree[level] = nodelist[i]; // 将元素值存入节点
  }
}

int main() {
  int i,index; // 
  int data; // 读入输入值所使用的的暂存变量
  int b_tree[16]; // 声明二叉树数组
  int nodelist[16]; // 声明存储输入数据的数组

  index=1;

  // 读取数值存到数组中
  scanf("%d", &data);  // 读取输入值存到变量data中
  while (data!=0) { // 读取尚未结束
    nodelist[index] = data;
    index=index+1;
    scanf("%d", &data);
  }

  // 清除二叉树数组的内容
  for (i=1;i<16;i++) b_tree[i] =0;
  
  // 建立二叉树
  create_btree(b_tree,nodelist,index);

  // 输出二叉树的内容
  printf("\n The binary tree is:\n");
  for (i=1;i<16;i++) printf("%2d:[%d] \n",i,b_tree[i]);
}
