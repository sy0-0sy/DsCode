//https://www.acwing.com/problem/content/3376/
//将一个长度最多为 30 位数字的十进制非负整数转换为二进制数输出。
//进制转换问题,将10进制转二进制 原理是短除法 
#include<bits/stdc++.h>
using namespace std;
//30位需要用高精度 longlong也就18位
vector<int> a;
int S[100];//mock stack
int tt=-1;//
vector<int> div(vector<int> a,int n){
    //高精度模拟乘法
    int tmp=0;//存余数,初始为0
    vector<int> c;
    for(int i=0;i<a.size();i++){
        tmp = tmp*10+a[i];//被除数是前面那个数的余数*10 然后加上后面这个数
        c.push_back(tmp/n);
        tmp %= n;
    }
    //清除高位0 比如 11/2= 05 ... 1 需要清除高位0
    while(c.size() && c.front()==0)c.erase(c.begin());
    return c;
}
int main(){
    string str;
    while(cin>>str){
        if(str=="0")S[++tt]=0;
        else{
            for(int i=0;str[i];i++)a.push_back(str[i]-'0');//这里选择正向存放
            while(a.size()){
                S[++tt]=a[a.size()-1]%2;//个位取模入栈
                a=div(a,2);
            }
        }
        while(tt!=-1){
            cout<<S[tt--];
        }
        puts("");
        
    }
    return 0;
}