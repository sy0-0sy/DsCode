//2、判断单链表(带头结点)的全部 n 个字符是否中心对称
//比如 1 2 1 就是中心对称 1 2 2 1 也是
//思想就是将前一半的元素先入栈,(length/2)然后弹栈与后一半元素比较(分长度为奇数偶数情况)
#include"public.cpp"
typedef struct Node{
    int x;
    Node*next;
}*LinkList;
LinkList list;
void insertNum(int x){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->next=list->next;
    newNode->x=x;
    //头插法
    list->next=newNode;
}
void initList(int n){
    list=(Node*)malloc(sizeof(Node));
    list->next=NULL;
    list->x=-1;
    insertNum(1); insertNum(2); insertNum(5);insertNum(2); insertNum(1);
    Node*p=list;
    while(p->next!=NULL){
        p=p->next;
        cout<<p->x<<" ";
    }
    cout<<endl;
}
bool isSymmetry(LinkList l){
    //确定链表长度
    Node * p=l;int cnt=0;
    while(p->next){p=p->next;cnt++;}
    p=l;
    for(int i=0;i<cnt/2;i++){
        p=p->next;
        push(p->x);
    }
    if(cnt%2)p=p->next;//如果是奇数 让p再往前走一格,因为奇数中间那个数不用对比
    while(!isStackEmpty()){
        p=p->next;
        if(pop()!=p->x)return false;
    }
    return true;
}
int main(){
    initList(5);
    if(isSymmetry(list))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}