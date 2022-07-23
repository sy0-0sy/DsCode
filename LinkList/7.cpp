//试编写在不带头结点的单链表中删除最小值点的高效算法（已知最小值唯一）
//不带头结点如果删除的是头,需要特判下
#include"public.cpp"
int minNum=0x3f3f3f;//初始化min为+inf
int delMin(LinkList&head){
    LNode*tmp=NULL;
    LNode*p=head;
    LNode*pre=NULL;
    while(p){
        if(p->data<minNum){
            minNum=p->data;
            tmp=pre;//记录前一个节点,删除函数需要传入前一个节点,如果是head则传入NULL
        }
        pre=p;
        p=p->next;
    }
   return delNoneHead(tmp,head);
}
int main(){
    LinkList head=initNoneHeadList();
    insertToNoneHeadList(head,5);
    insertToNoneHeadList(head,1);
    insertToNoneHeadList(head,2);
    cout<<"before: ";
    Print2(head);
    cout<<"删除的最小元素为: "<<delMin(head)<<endl;
    cout<<"after: ";
    Print2(head);
    return 0;
}