//4、判断一个表达式中括号是否配对(假设只包含圆括号)
/*
● 遇到左括号就入栈
● 遇到右括号就消耗一个左括号(要相互匹配)
  ○ 如果说处理完所右括号,栈还是非空的 说明有多余的左括号
  ○ 如果还没处理完括号,栈就空了,说明还有多余的右括号
*/
#include<iostream>
using namespace std;
#define MaxSize 10
char S[MaxSize];//模拟栈
int top=-1;//栈顶指针
char str[MaxSize];
bool check(char*str){
    for(int i=0;str[i];i++){
        if(str[i]=='(')S[++top]=str[i];
        else{
            if(top==-1)return false;//栈空说明有多余右括号
            else top--;//弹出一个左括号
        }
    }
    if(top==-1)return true;//栈还是非空的 说明有多余的左括号
    else return false;
}
int main(){
    cin>>str;
    if(check(str))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}