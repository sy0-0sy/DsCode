//判断带头结点的循环双链表是否对称
//找到头和尾巴一直往中间走,然后比较,直到相遇
#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode*next;
    LNode*pre;
}LNode,*LinkList;
LinkList initList(){
    //带头结点的双链表,初始化头
    LinkList l=new LNode;
    l->next=NULL;
    l->pre=NULL;
    return l;
}
void insertNum(LinkList&l,int x){
    LNode*p=l;
    LNode*node=new LNode;
    node->data=x;
    //使用头插法
    //如果是插入的第一个元素特判下
    if(!p->next){
        node->next=l;
        node->pre=l;
        p->next=node;
        p->pre=node;
    }else{
    //如果不是插入的第一个元素,则还需要修改p.next.pre
     node->next=l->next;
     node->pre=l;
     l->next->pre=node;
     l->next=node;
    }
   
}
void Print(LinkList l){
    LNode*p=l;
    while(p->next!=l){
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
bool isSymmetry(LinkList l){
    LNode*p1=l->pre;//tail
    LNode*p2=l->next;//head
    while(p1!=p2 && p2->next!=p1){
        //对应奇数和偶数的判定条件
        if(p1->data!=p2->data)return false;
        p1=p1->pre;
        p2=p2->next;
    }
    return true;
}
int main(){
    LinkList l=initList();
    insertNum(l,3);
    insertNum(l,1);
    insertNum(l,1);
    insertNum(l,3);
    Print(l);
    if(isSymmetry(l))cout<<"Yes";
    else cout<<"No";
    puts("");
    return 0;
}