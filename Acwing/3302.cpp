//https://www.acwing.com/problem/content/submission/code_detail/15035594/
//表达式求值
#include<iostream>
#include<map>
using namespace std;
const int N=1e5+10;
int stack1[N];
char stack2[N];
char input[N];
int tt1,tt2,x;
char op1,op2;
map<char,int> myMap={ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };//判定优先级
void eval(char op){
    int num1,num2,res;
    //先弹出的是右操作数
    num2=stack1[--tt1];
    num1=stack1[--tt1];
    if(op=='+')res=num1+num2;
    if(op=='-')res=num1-num2;
    if(op=='*')res=num1*num2;
    if(op=='/')res=num1/num2;
    stack1[tt1++]=res;
}
void fun(){
    for(int i=0;input[i];i++){
        if(isdigit(input[i])){ //转化为数字
             x=0;int j=i;
            while(input[j] && isdigit(input[j])){
                x=x*10+input[j]-'0';
                j++;
            }
            i=j-1;
            stack1[tt1++]=x;//操作数入栈
        }else if(input[i]=='(') stack2[tt2++]=input[i];
        else if(input[i]==')'){
            while(tt2 && stack2[tt2-1]!='('){
                op1=stack2[--tt2];
                eval(op1);
            }
            --tt2;//弹出')''
        }
        else{
            if(tt2 && stack2[tt2-1]!='('){
                while(myMap[stack2[tt2-1]] >= myMap[input[i]])eval(stack2[--tt2]);
            }
            stack2[tt2++]=input[i];
        }
    }
    while(tt2)eval(stack2[--tt2]);
    
}

int main(){
    cin>>input;
    fun();
    cout<<stack1[tt1-1]<<endl;
    return 0;
}