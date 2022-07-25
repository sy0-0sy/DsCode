//将一个带头节点的单链表 A 分解成两个带头节点的单链表 A 和 B，使 A 中含 奇数位置元素，B 中含偶数位置元素，且相对位置不变
#include"public.cpp"
//使用%2来判定奇数偶.可以让奇数位置的元素留在原链表,将偶数位置的元素插入新链表
void splitList(LinkList&A,LinkList&B){
    int flag=1;//第一个元素是奇数 1%2=1;
    LNode*p=A;
    LNode*t=B;//对B使用尾插法,设置一个尾指针
    while(p->next){
        if(flag%2==0){
            //如果是偶数
            t->next=p->next;
            t=p->next;
            p->next=p->next->next;//A中p指向下下个元素    
        }
        else if(p->next)p=p->next;
        flag++;
    }
    //最后要将B中最后一个元素的next设置为NULL
    t->next=NULL;
}
int main(){
    LinkList A=initHead();
    LinkList B=initHead();
    insertNum(A,6);
    insertNum(A,5);
    insertNum(A,4);
    insertNum(A,3);
    insertNum(A,2);
    insertNum(A,1);
    cout<<"before: ";
    Print(A);
    cout<<"after: "<<endl;
    splitList(A,B);
    cout<<"A: ";Print(A);
    cout<<"B: ";Print(B);
    return 0;
}