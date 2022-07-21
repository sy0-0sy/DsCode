//8、两个递增有序表合并成一个递增有序表
//双指针算法,需要用到额外的list空间
#include"sqlist.cpp"
Sqlist list2;
Sqlist list3;
void init2(){
    list2.length=4;
    for(int i=0;i<4;i++)list2.data[i]=10+i;
}
void listMerge(){
    int i=0;int j=0;int k=0;
    while(i<list.length && j<list2.length){
        if(list2.data[j]<=list.data[i])list3.data[k++]=list2.data[j++];
        else list3.data[k++]=list.data[i++];
    }
    //扫尾
    while(i<list.length)list3.data[k++]=list.data[i++];
    while(j<list2.length)list3.data[k++]=list2.data[j++];
    list3.length=k;
}
// int main(){
//     initTest();
//     init2();
//     cout<<"before: ";
//     Print();
//     for(int i=0;i<list2.length;i++)cout<<list2.data[i]<<" ";
//     cout<<endl;
//     listMerge();
//     cout<<"after merge: ";
//     for(int i=0;i<list3.length;i++)cout<<list3.data[i]<<" ";
//     cout<<endl;
//     return 0;
// }