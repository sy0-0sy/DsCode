//https://www.acwing.com/problem/content/3378
//成绩排序问题 核心在于是一个稳定的排序算法
#include<iostream>
using namespace std;
const int N=1010;
char na[N][15];
int s[N];

//需要一个稳定的算法
void bubbleSort(int flag,int n){
         for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(s[j]>s[j+1]&&flag==1 || s[j]<s[j+1]&&flag==0 ){
                    swap(s[j],s[j+1]);
                    swap(na[j],na[j+1]);
                }
            }
    }
}
int main(){
    int flag,n;
    cin>>n>>flag;
    for(int i=0;i<n;i++)cin>>na[i]>>s[i];
    bubbleSort(flag,n);
    for(int i=0;i<n;i++)cout<<na[i]<<" "<<s[i]<<endl;
    return 0;
}