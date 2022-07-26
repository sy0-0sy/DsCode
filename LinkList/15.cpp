//两个序列分别为 A、B，将其存放到链表中，判断 B 是否是 A 的连续子序列
//思路是依次比较,每次失败后从A中上次开始比较的第一个元素的下一个元素与B的第一个元素重新比较
#include"public.cpp"
bool isSeq(LinkList A,LinkList B){
    LNode*p1=A->next;
    LNode*p2=B->next;
    LNode*p3=A->next;//p3记录上一次A中开始比较的第一个元素
    while(p1&&p2){
        if(p1->data==p2->data){
            //如果元素相等,都往后走一格比较下一个元素
            p1=p1->next;
            p2=p2->next;
        }else{
            //如果不等 将A中第一个比较元素的位置往后移动一格 重置B
            p2=B->next;
            p1=p3->next;
            p3=p3->next;
        }
    }
    //如果p2也就是p中还有未比较元素A就结束了,说明没有连续子序列
    if(p2)return false;
    return true;
}
int main(){
    LinkList l1=initHead();
    insertNum(l1,4);
    insertNum(l1,3);
    insertNum(l1,1);
    insertNum(l1,1);
    LinkList l2=initHead();
    insertNum(l2,4);
    insertNum(l2,3);
    cout<<"before: ";
    Print(l1);Print(l2);
    if(isSeq(l1,l2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}