/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://www.acwing.com/problem/content/3760/ 评测网站
class Solution {
public:
    //把链表平均分成两段如果是奇数则前半段向上取整
    //逆置后半段,然后交替合并到前半段
    void rearrangedList(ListNode* head) {
        //求长度
        int length=0;
        ListNode*p,*p1,*p2,*tmp,*tmp2;
        p=p1=p2=head;
        while(p){
            length++;
            p=p->next;
        }
        if(length<=1)return;//小于等于1特判下
        for(int i=0;i<(length+1)/2-1;i++)p1=p1->next;
        p2=p1->next;tmp=p2->next;
        p1->next=p2->next=NULL;p1=head;
        //逆置后半段
        while(tmp){
           tmp2=tmp->next;
           tmp->next=p2;
           p2=tmp;tmp=tmp2;
        }
        while(p2){
            //p2比较短,p2会先到null
            tmp=p2->next;
            tmp2=p1->next;
            p2->next=tmp2;
            p1->next=p2;
            p1=tmp2;p2=tmp;
        }
        
    }
};