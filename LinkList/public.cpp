#include <iostream>
using namespace std;

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
//生成一个带头结点的链表
LinkList initHead(){
    LinkList p=(LinkList)malloc(sizeof(LNode));
    p->next=NULL;
    return p;
}
//插入(头插法)
void insertNum(LinkList&head,int x){
   LNode* p=(LinkList)malloc(sizeof(LNode));
    p->next=head->next;
    p->data=x;
    head->next=p;
}
//删除元素(删除的是给定节点后面那个元素)
int deleNum(LinkList&p){
    LNode*tmp=p->next;
    p->next=tmp->next;
    int x=tmp->data;
    free(tmp);
    return x;
}
//遍历打印链表(带头结点)
void Print(LinkList head){
    LNode*p=head;
    while(p->next){
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//遍历打印链表(不带头结点)
void Print2(LinkList head){
    LNode*p=head;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
LinkList initNoneHeadList(){
    LinkList head=NULL;
    return head;
}
void insertToNoneHeadList(LinkList&head,int x){
     LinkList p=(LinkList)malloc(sizeof(LNode));
     p->data=x;
     if(!head)head=p;
     else{
        //头插法
        p->next=head;
        head=p;
     }
}
int delNoneHead(LinkList&p,LinkList&head){
    //删除p的下一个节点,规定如果传入NULL则是代表删除头指针(head没有前驱)
    if(!p){
        int x=head->data;
        free(head);
        head=NULL;
        return x;
    }
    else{
        LNode*tmp=p->next;
        int x=tmp->data;
        p->next=tmp->next;
        free(tmp);
        return x;
    }
}