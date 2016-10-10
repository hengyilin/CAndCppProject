#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
} LinkListNode;

class LinkListQuickSort{
public :
    /*分割*/
    LinkListNode* partiction(LinkListNode* head, LinkListNode* tail) {
        LinkListNode* temp1 = head;
        LinkListNode* temp2 = temp1->next;
        while (temp2 != tail) {

        }
    }
};
