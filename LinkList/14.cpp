//A, B 两个单链表递增有序，从 A，B 中找出公共元素并存放于 A 链表中
//跟上个题大体一样,但这个题需要操作A链表,在不等的情况下直接free掉不等的节点就行
#include"public.cpp"
void findCommon(LinkList&A,LinkList&B){
    //这里需要用到删除,所以用p.next作为循环条件
    LNode*p1=A;
    LNode*p2=B;
    LNode*t=A;//设置尾指针,记录在A中所记录的最后一个相同元素的位置
    while(p1->next&&p2->next){
        if(p1->next->data>p2->next->data){
            //说明p2.next这个节点已经没啥用了直接删除
            LNode*tmp=p2->next;
            p2->next=p2->next->next;
            free(tmp);
        }else if(p1->next->data<p2->next->data){
            //说明p1.next这个节点没用了直接删除
            LNode*tmp=p1->next;
            p1->next=p1->next->next;
            free(tmp);
        }else{
            //相等情况
            t=p1->next;
            p1=p1->next;
            //释放B中节点
            LNode*tmp=p2->next;
            p2->next=p2->next->next;
            free(tmp);
        }
    }
    //A/B中后面可能还有元素,这些剩下元素非相同元素,需要清除
    while(p1->next){
        LNode*tmp=p1->next;
        p1=p1->next;
        free(tmp);
    }
    while(p2->next){
        LNode*tmp=p2->next;
        p2=p2->next;
        free(tmp);
    }
    t->next=NULL;//尾指针最后置NULL
}
int main(){
    LinkList l1=initHead();
    insertNum(l1,4);
    insertNum(l1,3);
    insertNum(l1,1);
    insertNum(l1,1);
    LinkList l2=initHead();
    insertNum(l2,3);
    insertNum(l2,1);
    cout<<"before: ";
    Print(l1);Print(l2);
    findCommon(l1,l2);
    cout<<"after: ";
    Print(l1);
    return 0;
}