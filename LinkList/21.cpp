//判断单链表是否有环
//只可能在末尾有环不可能在中间有环,因为如果中间有环则说明有节点有两个指针,这是不可能的
//设置快慢指针,慢指针每次走一步,快指针每次走两步,如果没有环是不会相遇的,如果有环,早晚会相遇
#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
bool fun(LinkList l){
    LNode*fast=l;
    LNode*slow=l;
    while(fast&&fast->next){
        //当fast不能往后走的时候就停止
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}