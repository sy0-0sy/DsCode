//两个递增有序的单链表，设计算法成一个非递减有序的链表
//两个递增有序的单链表，设计算法成一个非递增有序的链表
#include"public.cpp"
//双指针算法
//相当于把l1和l2从头结点断开成两个不带头结点的新链表,然后依次比较往原来l1的表头使用尾插法就行
//单调非减
void mergeList(LinkList&l1,LinkList&l2){
    //合并到l1
    LNode*p1=l1->next;LNode*p2=l2->next;
    LNode*t=l1;//记录尾巴
    while(p1&&p2){
        if(p1->data<=p2->data){
            t->next=p1;
            t=p1;
            p1=p1->next;
        }else{
            t->next=p2;
            t=p2;
            p2=p2->next;
        }
    }
    //循环完后要进行扫尾操作
    if(p1)t->next=p1;      
    if(p2)t->next=p2; 
}
int main(){
    LinkList l1=initHead();
    insertNum(l1,4);
    insertNum(l1,3);
    insertNum(l1,2);
    insertNum(l1,1);
    insertNum(l1,1);
    LinkList l2=initHead();
    insertNum(l2,9);
    insertNum(l2,8);
    insertNum(l2,3);
    insertNum(l2,2);
    cout<<"before: ";
    Print(l1);Print(l2);
    mergeList(l1,l2);
    cout<<"after: ";
    Print(l1);
    return 0;
}