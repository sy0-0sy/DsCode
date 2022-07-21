#include<iostream>
using namespace std;
//static stack & queue,用来模拟链栈/队列 默认认为不会满
const int N=50;
int S[N];
int Q[N];
int top=-1;//栈顶指针初始化
int ss=-1,tt=-1;//队首对尾指针初始化
bool isStackEmpty(){
    return top==-1;
}
bool isQueueEmpty(){
    return ss==tt;
}
void inQueue(int x){
    Q[++tt]=x;
}
int outQueue(){
    return Q[++ss];
}

int pop(){
    return S[top--];
}
void push(int x){
    S[++top]=x;
}