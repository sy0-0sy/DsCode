//5、假设一个序列为 HSSHHHS，运用栈的知识，编写算法将 S 全部提到 H 之前， 即为 SSSHHHH
//比较简单,遇到H直接入栈,遇到S加入新的字符串最后再把H弹出来加到新字符串
#include<iostream>
using namespace std;
const int N=10;
char str1[N];
char str2[N];//辅助空间
char S[N];
int top=-1;
int main(){
    cin>>str1;
    int p=0;//辅助空间指针
    for(int i=0;str1[i];i++){
        if(str1[i]=='H')S[++top]=str1[i];
        else str2[p++]=str1[i];
    }
    while(top!=-1)str2[p++]=S[top--];
    str2[p+1]=0;
    puts(str2);
    return 0;  
}