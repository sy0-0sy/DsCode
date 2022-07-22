//3、两个栈 s1,s2 都采用顺序存储，并共享一个存储区[0,...,maxsize-1]。采用栈顶 相向，迎面增长的存储方式，设计 s1,s2 入栈和出栈的操作。
#include<iostream>
using namespace std;
#define MaxSize 5
typedef struct{
    int data[MaxSize];
    int top1;
    int top2;
}sqStack;
sqStack S;
void initS(){
    S.top1=-1;
    S.top2=MaxSize;
}
void push(int x,bool s){
    //s为true代表push到s1 false表示push到s2
    if(s){
       //看看是否满
       if(S.top1+1!=S.top2){
            S.data[++S.top1]=x;
       }
    }else{
        //看看是否满
       if(S.top1+1!=S.top2){
            S.data[--S.top2]=x;
       }
    }
}
int pop(bool s){
    if(s){
        if(S.top1!=-1){S.data[S.top1]=0;return S.data[S.top1--];}
    }else{
        if(S.top2!=MaxSize){S.data[S.top2]=0;return S.data[S.top2++];}
    }
    return -1;//error code
}
int main(){
    initS();
    bool s=true;
    for(int i=0;i<MaxSize;i++,s=!s){
        push(i+1,s);
        for(int i=0;i<MaxSize;i++){
            cout<<S.data[i]<<" ";
        }
    cout<<endl;
    }
    cout<<"============================"<<endl;
    s=true;
    for(int i=0;i<MaxSize;i++,s=!s){
        pop(s);
        for(int i=0;i<MaxSize;i++){
            cout<<S.data[i]<<" ";
        }
    cout<<endl;
    }
    return 0;
}