//删除带头节点单链表中第一个值为 x 的结点
//与1大致相同,删除第一个x节点后 退出循环就行
#include"public.cpp"
void fun(int x,LinkList&head){
    LNode* p =head;
    while(p->next){
        if(p->next->data==x){deleNum(p);break;}
        else p=p->next;//不是就继续遍历
    }
}
int main(){
    LinkList head=initHead();
    //insertNum(head,2);
    insertNum(head,1);
    //insertNum(head,3);
    //insertNum(head,2);
   // insertNum(head,1);
    cout<<"before: ";
    Print(head);
    cout<<"after: ";
    fun(1,head);
    Print(head);
    return 0;
}