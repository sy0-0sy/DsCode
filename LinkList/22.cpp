//将一个无序链表排列成递增有序
#include"public.cpp"
void fun(LinkList&L){
    LNode*p;
    LNode*r=L;
    LNode*pre;
    while(r->next){
        p=r;
        pre=p;
        LNode*minNode=r->next;
        while(p->next){
            if(p->next->data<minNode->data){
                minNode=p->next;
                pre=p;
            }
            p=p->next;
        }
         pre->next=minNode->next;
         minNode->next=r->next;
         r->next=minNode;
         r=r->next;
    }
   
}
int main(){
    LinkList head=initHead();
    insertNum(head,1);
    insertNum(head,7);
    insertNum(head,-2);
    insertNum(head,44);
    insertNum(head,5);
    cout<<"before: ";
    Print(head);
    cout<<"after: ";
    fun(head);
    Print(head);
    return 0;
}