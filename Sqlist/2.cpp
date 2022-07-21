//用顺序表最后一个元素覆盖整个顺序表中最小元素，并返回该最小元素
#include"sqlist.cpp"
int minNum=0x3f3f3f3f;
int findMin(){
    int index=-1;
    for(int i=0;i<list.length;i++){
        if(list.data[i]<minNum){
            minNum=list.data[i];
            index=i;
        }
    }
    list.data[index]=list.data[list.length-1];
    list.length--;
    return minNum;
}
int main(){
     initTest();
    cout<<"The min number is "<<findMin()<<endl;
    Print();
    return 0;
}
