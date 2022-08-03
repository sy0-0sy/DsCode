//https://www.acwing.com/problem/content/3379/
//双重关键字排序问题
#include<iostream>
using namespace std;
const int N=110;
int nums[N];
int s[N];
void bubbleSort(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j]>s[j+1]||(s[j]==s[j+1]&&nums[j]>nums[j+1])){
                swap(s[j],s[j+1]);swap(nums[j],nums[j+1]);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>nums[i]>>s[i];
    bubbleSort(n);
    for(int i=0;i<n;i++)cout<<nums[i]<<" "<<s[i]<<endl;
    return 0;
}