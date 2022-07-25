//将一个单链表{a1,b1,a2,b2……an,bn}拆分成{ a1,a2……an }和{ bn,bn-1,……b1 }
//跟上一题基本类似,不同点在于 bi是倒着排,前面我们使用的是尾插法,这里使用头插法就行
#include"public.cpp"
//使用%2来判定奇数偶.可以让奇数位置的元素留在原链表,将偶数位置的元素插入新链表
void splitList(LinkList&A,LinkList&B){
    int flag=1;//第一个元素是奇数 1%2=1;
    LNode*p=A;
    LNode*t;//辅助指针
    while(p->next){
        if(flag%2==0){
            //如果是偶数
            t=p->next;//保存这个值,后面头插法要用到
            //对A的操作 AB操作不能反,需要先用到p.next.next这个值
            p->next=p->next->next; 
            //对B操作
            t->next=B->next;//头插法
            B->next=t;                   
        }
        else if(p->next)p=p->next;
        flag++;
    }
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