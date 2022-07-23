//逆置链表,带头结点(不用额外空间)
//双指针算法.设置两个指针依次移动 依次交换cur和next的位置即可
#include"public.cpp"
void convert(LinkList&head){
    if(!head->next || !head->next->next)return;//空表或者只有一个元素直接return
    LNode*p1,*p2,*p3;//定义两个指针,p1指向当前,p2指向next的位置,p3作为tmp指针
    p1=head->next;//指向第一个元素
    p2=head->next->next;//指向第2个元素
    p1->next=NULL;//第一个元素最后是链表尾巴,next置空
    while(p2){
        p3=p2->next;//保存p2下一个节点的信息
        p2->next=p1;//p2下一个指向p1,反向指
        p1=p2;//往前移动一格
        p2=p3;//往前移动一格
        
    }
    head->next=p1;//最后p1停下来的位置是逆置后第一个元素的位置
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
    convert(head);
    Print(head);
    return 0;
}