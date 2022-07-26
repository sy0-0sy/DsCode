//A, B 两个单链表递增有序，从 A，B 中找出公共元素产生单链表 C，要求不 破环 A，B 结点
//算法比较简单,双指针依次往后面走进行比较,需要注意的是不破坏AB节点意思是要自己重新创建节点
#include"public.cpp"
void findCommon(LinkList A,LinkList B,LinkList&C){
    LNode*p1=A->next;
    LNode*p2=B->next;
    LNode*p3=C;//对C使用尾插法,故设置尾指针
    while(p1&&p2){
        if(p1->data<p2->data)p1=p1->next;//p1太小了,为了找到相等的元素p1往后移动
        else if(p1->data>p2->data)p2=p2->next;
        else {
            //找到相等的元素了
            LNode*newNode=(LNode*)malloc(sizeof(LNode));
            newNode->data=p1->data;
            newNode->next=NULL;
            p3->next=newNode;
            p3=newNode;
            p1=p1->next;p2=p2->next;//都往后走一格
        }
    }
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
    LinkList C=initHead();
    cout<<"before: ";
    Print(l1);Print(l2);
    findCommon(l1,l2,C);
    cout<<"after: ";
    Print(C);
    return 0;
}