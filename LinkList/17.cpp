//用单链表保存 m 个整数，并且|data|≤n，要求设计时间复杂度尽可能高效 的算法，对于 data 绝对值相等的点，仅保留第一次出现的点
//空间换时间,开辟一个bool数组记录 |i|是否已经出现
#include"public.cpp"
int myabs(int x){return (x>=0)?x:-x;}//对x取绝对值
void fun(LinkList&l,int n){
    bool*st=new bool[n+1];
    for(int i=0;i<=n;i++)st[i]=false;//初始为false
    LNode*p=l;
    while(p->next){
         //如果|i|第一次出现;标记为已出现,p往后移动
        if(!st[myabs(p->next->data)]){
            st[myabs(p->next->data)]=true;
            p=p->next;
        }
        else{
            //表示已经出现过了,直接删除该元素
            LNode*tmp=p->next;
            p->next=p->next->next;
            free(tmp);
        }          
    }
}
int main(){
    LinkList head=initHead();
    insertNum(head,0);
    insertNum(head,2);
    insertNum(head,-1);
    insertNum(head,0);
    insertNum(head,1);
    insertNum(head,-2);
    insertNum(head,-3);
    cout<<"before: ";
    Print(head);
    fun(head,20);
    cout<<"after: ";
    Print(head);
    return 0;
}
