//带头结点的单链表中删除最小值点的高效算法（已知最小值唯一）
//记录最小节点的前一个节点(因为del是删除p节点的后一个元素) 时间复杂度O(n),因为遍历链表需要O(n)
#include"public.cpp"
int minNum=0x3f3f3f;//初始化min为+inf
int delMin(LinkList&head){
    LNode*tmp=NULL;
    LNode*p=head;
    while(p->next){
        if(p->next->data<minNum){
            minNum=p->next->data;
            tmp=p;//记录前一个节点
        }
        p=p->next;
    }
    return deleNum(tmp);//删除该元素即可
}
int main(){
    LinkList head=initHead();
    insertNum(head,1);
    insertNum(head,2);
    insertNum(head,-8);
    insertNum(head,-9);
    insertNum(head,2);
    cout<<"before: ";
    Print(head);
    cout<<"删除的最小元素为: "<<delMin(head)<<endl;
    cout<<"after: ";
    Print(head);
    return 0;
}