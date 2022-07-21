//11、若一个整数序列中有过半相同元素，则称其为主元素，设计算法找出数组 A( a0,a1……an-1 )的主元素。（其中 0<ai<n）若存在主元素则输出，否则返回-1
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=110;
int arr[N];
int flag[N];
void initArr(int n){
    srand((unsigned)time(NULL)); 
    // for(int i=0;i<n;i++){
    //     arr[i]=rand()%10-5;
    // }
    for(int i=0;i<n;i++)arr[i]=1;
    arr[1]=2;arr[2]=2;
    cout<<"init arr: ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
//思路与上题大同小异,时间换空间
int find(int n){
    int i;
    for(i=0;i<n;i++)flag[arr[i]]++;
    for(i=0;i<n;i++){
        if(flag[i]>n/2)return i;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    initArr(n);
    cout<<"The result: "<<find(n)<<endl;
    return 0;
}
