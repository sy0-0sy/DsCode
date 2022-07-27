//有两个循环单链表，链表头指针分别为 h1,h2,试编写函数将 h2 链表接到 h1 之后，要求链接后仍保持循环链表形式(不带头结点)
#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode*next;
}LNode,*LinkList;
void insertNum(LinkList&l,int x){
    //第一次插入要特判
    LNode*newNode=new LNode;
    newNode->data=x;
    LNode*p=l;
    if(!l){
        l=newNode;
        l->next=l;
    }else{
        //尾插法,先找尾巴
        while(p->next!=l)p=p->next;
        newNode->next=l;
        p->next=newNode;
    }
}
void Print(LinkList l){
    LNode*p=l;
    while(p->next!=l){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data<<" ";
    cout<<endl;
}
void mergeList(LinkList&h1,LinkList&h2){
    //先找h1的尾巴,再找h2的尾巴
    LNode*p1=h1;
    LNode*p2=h2;
    while(p1->next!=h1)p1=p1->next;
    while(p2->next!=h2)p2=p2->next;
    //h2直接链到h1后面就行
    p1->next=h2;
    p2->next=h1;
}
int main(){
    LinkList h1=NULL;
    LinkList h2=NULL;
    for(int i=1;i<=5;i++){
        insertNum(h1,i);
        insertNum(h2,i+5);
    }
    Print(h1);Print(h2);
    mergeList(h1,h2);
    Print(h1);
    return 0;
}