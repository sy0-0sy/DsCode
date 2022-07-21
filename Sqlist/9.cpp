//9、求两个递增序列(等长)合并后的中位数(两种方法)
#include"8.cpp"
//方法1 是否等长都可以做,就是先合并两个序列然后找中位数就行
//需要注意的是 中位数的索引是 (A.len+B.len-1)/2
//比如 1 2 / 3 4 合并后为 1 2 3 4 其中位数为2 索引为1 则 为(2+2-1)/2 =1
void find1(){
    initTest();
    init2();
    cout<<"before: ";
    Print();
    for(int i=0;i<list2.length;i++)cout<<list2.data[i]<<" ";
    cout<<endl;
    listMerge();
    cout<<"after merge: ";
    for(int i=0;i<list3.length;i++)cout<<list3.data[i]<<" ";
    cout<<endl;
    cout<<"中位数为: "<<list3.data[list.length+list2.length-1>>1]<<endl;
}
//方法2必须要求等长了 偏数学证明,暂时跳过
void fun2(){
    //give up
}
int main(){
    find1();
    return 0;
}