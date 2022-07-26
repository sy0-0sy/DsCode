//查找单链表中倒数第 k 个结点，若成功，则输出该节点的 data，并返回 1， 否则返回 0
//遍历得到链表长度length,倒数第k个也就是正数第length-k+1个
#include"public.cpp"
int findK(LinkList l,int k){
    int cnt=0;
    LNode*p=l->next;
    while(p){
        p=p->next;
        cnt++;
    }
    int num=cnt-k+1;
    if(num<1)return 0;//位置不合法
    p=l;//重置p到链表头结点,往后走length-k+1个位置
    for(int i=0;i<num;i++)p=p->next;
    cout<<"The data is: "<<p->data<<endl;
    return 1;
}
int main(){
    LinkList head=initHead();
    insertNum(head,0);
    insertNum(head,2);
    insertNum(head,1);
    insertNum(head,8);
    insertNum(head,-5);
    cout<<"before: ";
    Print(head);
    findK(head,3);
    return 0;
}