//https://www.acwing.com/problem/content/62/
//输入两个链表，找出它们的第一个公共结点 当不存在公共节点时，返回空节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //交叉着走,总会在一个地方相遇 因为走过的长度是一样的
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode*p1=headA;
        ListNode*p2=headB;
        while(p1!=p2){
            if(!p1)p1=headB;
            else p1=p1->next;
             if(!p2)p2=headA;
            else p2=p2->next;
        }
        return p1;
    }
};
