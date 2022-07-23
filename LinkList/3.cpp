//从尾到头反向输出单链表每个结点的值
//利用递归回溯达到反向目的,带头结点需要注意不要输出头结点的data,传参数传head.next,不带头结点传头指针就行
#include"public.cpp"
void convertPrint(LinkList head){
    if(head->next)convertPrint(head->next);
    cout<<head->data<<" ";
}
int main(){
    LinkList head=initHead();
    insertNum(head,1);
    insertNum(head,2);
    insertNum(head,3);
    insertNum(head,4);
    insertNum(head,5);
    cout<<"before: ";
    Print(head);
    cout<<"after: ";
    convertPrint(head->next);
    cout<<endl;
    return 0;
}