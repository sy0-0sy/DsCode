#include <iostream>
using namespace std;
#define maxsize 100
typedef struct
{
  int data[maxsize];
  int length;
} Sqlist;
Sqlist list;
void Print(){
    for(int i=0;i<list.length;i++)cout<<list.data[i]<<" ";
    cout<<endl; 
}
//自己编写测试数据
void initTest(){
    for(int i=0;i<5;i++)list.data[i]=i;
    for(int i=5;i<10;i++)list.data[i]=i;
    list.length=10;
   // list.data[2]=1;list.data[5]=4;list.data[8]=9;
}
//在下标为index的位置插入元素x
void insertNum(int index,int x){
    if(list.length>=maxsize)return;
    for(int i=list.length-1;i>=index;i--){
        list.data[i+1]=list.data[i];
    }
    list.data[index]=x;
    list.length++;
}
//删除下标为index的元素
int delNum(int index){
    int temp=list.data[index];
    for(int i=index;i<list.length-1;i++){
        list.data[i]=list.data[i+1];
    }
    list.length--;
    return temp;
}
