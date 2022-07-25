//给定一个单链表(带头结点)，按递增排序输出的单链表中各结点的数据元素，并释放节点所占空间(不使用额外空间)
#include"public.cpp"
//类似冒泡排序依次比较大小,满足条件的话交换前后两个节点的数据域,那么第一轮下来最后一个元素的数据就是最小元素,输出.然后free
void sortList(LinkList&head){
    //如果只有一个元素或者是空表不用排序
    if(!head->next){free(head);return;}
    if(!head->next->next){
        cout<<head->next->data<<endl;
        free(head->next);free(head);
        return;
    }
    while(head->next->next){//循环到只剩下一个元素
        LNode*p1=head->next;LNode*p2=head->next->next;//一前一后两个指针
        LNode*pre=NULL;//保存p1的前驱
        while(p2){
            if(p1->data<p2->data)swap(p1->data,p2->data);
            pre=p1;
            p1=p2;
            p2=p2->next;
        }
        //一轮下来p1现在指向最后一个元素也就是最小元素
        cout<<p1->data<<" ";
        //删除最后一个节点也就是p1,需要将p1的前驱的next置空
        pre->next=NULL;
        free(p1);
    }
    cout<<head->next->data<<endl;
    free(head->next);free(head);
}
//方法2 类似前两个题 每次去找链表中最小的元素 输出然后删除
void sortList2(LinkList&head){
    while(head->next){
        LNode*minNode=head->next;
        LNode*pre=head;
        LNode*p=head;
        while (p->next){
            if(p->next->data<minNode->data){
                pre=p;
                minNode=p->next;
            }
            p=p->next;
        }
        cout<<minNode->data<<" ";
        pre->next=minNode->next;
        free(minNode);
    }
    cout<<endl;
    free(head);
}
int main(){
    LinkList head=initHead();
    // insertNum(head,0);
    // insertNum(head,2);
    // insertNum(head,1);
    insertNum(head,8);
    insertNum(head,-5);
    cout<<"before: ";
    Print(head);
    cout<<"after: ";
    sortList2(head);
    return 0;
}