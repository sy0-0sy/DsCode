//从链表中删除给定值在 s 到 t 之间（不包含 s 和 t）的所有元素
//简单遍历就行
#include"public.cpp"
bool check(int x,int s,int t){
    if(x>s && x<t)return true;
    return false;
}
void delNums(LinkList&head,int s,int t){
    LNode*p=head;
    while(p->next){
        if(check(p->next->data,s,t))deleNum(p);
        else p=p->next;
    }
}
int main(){
    LinkList head=initHead();
    insertNum(head,1);
    insertNum(head,2);
    insertNum(head,6);
    insertNum(head,8);
    insertNum(head,2);
    cout<<"before: ";
    Print(head);
    cout<<"after: ";
    delNums(head,1,4);
    Print(head);
    return 0;
}