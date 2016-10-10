#include <iostream>
using namespace std;
/**
 * 链表归并排序
 * 要求时间复杂度为O（nlogn）则考虑二分（分治法）
 * 可以考虑归并法;归并法就是一分为二然后归并
 */
class ListNode{

public:
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }

    int val;
};

class Solution{
public:
    /*快慢指针获取链表的中间指针*/
    ListNode *findMiddle(ListNode *head){
        ListNode* charser = head;
        ListNode *runner = head->next;
        while (runner != NULL && runner->next != NULL) {
            charser = charser->next;
            runner = runner->next->next;
        }
        return charser;
    }

    /*归并两个链表*/
    ListNode *mergeTwoLinkList(ListNode *l1, ListNode *l2)
    {
        /*如果一开始l1就是空的话那么直接就是l2啦*/
        if (l1 == NULL) {
            return l2;
        }
        /*如果一开始l2就是空的话那么直接就是l1啦*/
        if (l2 == NULL) {
            return l1;
        }
        ListNode *dummy = new ListNode(0); //  新建一个节点
        ListNode *head = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                head->next = l2;
                l2 = l2->next;
            } else {
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next; // 更新头节点
        }
        /*以下两种情况是当其中一个链表遍历完成了的情况下处理*/
        if (l1 == NULL) { // 如果l1遍历完那么就把l2全部放那改到后面
            head->next = l2;
        }
        if (l2 == NULL) { // 如果l2遍历完就把l1全部放到后面
            head->next = l1;
        }
        return dummy->next; // 返回dummy的下一个节点就是不要dummy那个节点因为那个节点是多余的不需要的
    }

    /**
     * 归并排序链表
     * @param head 链表的头节点
     * @return 返回归并好的链表的头节点
     */
    ListNode *sortLinkedList(ListNode *head){
        //递归循环退出的条件
        if (head == NULL || head->next == NULL) {
            // 如果头节点就是空或者头节点的下一个节点是空那么直接返回头节点不需要排序因为只有一个或者没有节点自然不用排
            return head;
        }
        ListNode* middle = findMiddle(head); // 得到中间节点的指针
        ListNode *right = sortLinkedList(middle->next); // 递归排序右边的
        middle->next = NULL; //??
        ListNode *left = sortLinkedList(head); // 递归排序左边
        return mergeTwoLinkList(left, right);
    }
};
int main()
{

}