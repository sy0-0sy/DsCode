//设有一个带头结点的循环单链表，其结点值为正整数，设计算法反复找出链表内最小值并不断输出，并将结点从链表中删除，直到链表为空，再删除表头结点
#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;
LinkList initList()
{
    LinkList l = new LNode;
    l->next = l;
    return l;
}
void Print(LinkList l){
    LNode*p=l;
    while(p->next!=l){
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insertNum(LinkList &l, int x)
{
    LNode *p = l;
    LNode *newNode = new LNode;
    newNode->data = x;
    if (!p->next)
    {
        newNode->next = p;
        p->next = newNode;
    }
    else
    {
        newNode->next = p->next;
        p->next = newNode;
    }
}
void delMin(LinkList &l){
    while (l->next != l){
        //先假设第一个节点就是最小节点,在遍历比较记录最小节点
        LNode *pre = l;
        LNode *p = l;
        LNode *minNode = l->next;
        while (p->next != l){
            if (p->next->data < minNode->data){
                pre = p;
                minNode = p->next;
            }
            p = p->next;
        }
        //一轮下来找到当前的minNode
        cout << minNode->data << " ";
        // del的时候判定下minNode是不是尾巴 尾巴要特殊处理
        if (minNode->next == l){
            pre->next = l;
            free(minNode);
        }
        else{
            pre->next = minNode->next;
            free(minNode);
        }
    }
    free(l);
    puts("");
}
int main(){
    LinkList l=initList();
    insertNum(l,9);
    insertNum(l,1);
    insertNum(l,2);
    insertNum(l,3);
    Print(l);
    delMin(l);
    return 0;
}