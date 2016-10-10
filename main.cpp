#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
} BinaryTree;

void createBinaryTree(BinaryTree *node)
{
    int val;
    cin >> val;
    if (val != -1) {
        node = (BinaryTree *) malloc(sizeof(BinaryTree));
        if (node == NULL) {
            cout << "出错啦" << endl;
        } else {
            cout << node;
            node -> data = val;
            createBinaryTree(node->lchild);
            createBinaryTree(node->rchild);
        }
    } else {
        return ;
    }
}

void preOrder(BinaryTree *node)
{
    if (node != NULL) {
        cout << node -> data;
        preOrder(node->lchild);
        preOrder(node->rchild);
    }
}
int main1() {
    BinaryTree * binaryTree;
    cout << "开始输入二叉树" << endl;
    createBinaryTree(binaryTree);
    cout << "开始遍历二叉树" << endl;
    preOrder(binaryTree);
    return 0;
}