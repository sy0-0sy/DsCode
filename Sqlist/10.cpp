//10、设计一个时间上尽可能高效的算法，找出数组中未出现的最小正整数
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=110;
int arr[N];
bool flag[N];
void initArr(int n){
    srand((unsigned)time(NULL)); 
    for(int i=0;i<n;i++){
        arr[i]=rand()%10-5;
    }
    //for(int i=0;i<n;i++)arr[i]=-(i+1);
    cout<<"init arr: ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
//需要开辟额外空间,空间换时间
//arr[i]<=n的原因是 大于n的元素不用考虑
//最极端的情况是比如长度为3, 元素为 1 2 3,则最小没出现的是4,元素为 299 824 24 最小元素也就是 1 不需要存其他大于3的元素
int find(int n){
    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i]<=n)flag[arr[i]-1]=true;
    }
    int i;
    for(i=0;i<n;i++){
        if(!flag[i])break;
    }
    return i+1;
}
int main(){
    initArr(20);
    cout<<"The result: "<<find(20)<<endl;
    return 0;
}