//删除递增链表中重复的元素(带头结点)
#include"public.cpp"
void deleR(LinkList&h){
    if(!h->next||!h->next->next)return;//只有一个元素或者空表直接return
    int cur;//设置一个游标记录当前元素,如果下个元素与cur相同说明是重复元素,删除,如果不是则更新cur
    LNode*p=h;
    LNode*t;
    cur=p->next->data;//初始化为第一个元素
    p=p->next;//往前走一格,从第二个元素开始
    while(p->next){
        if(p->next->data==cur){
            t=p->next;
            p->next=p->next->next;
            free(t);
        }else{
            p=p->next;
            cur=p->data;
        } 
    }
}
int main(){
    LinkList head=initHead();
    insertNum(head,4);
    insertNum(head,3);
    insertNum(head,2);
    insertNum(head,1);
    insertNum(head,1);
    cout<<"before: ";
    Print(head);
    deleR(head);
    cout<<"after: ";
    Print(head);
    return 0;
}