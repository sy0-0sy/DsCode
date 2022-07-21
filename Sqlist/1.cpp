#include "sqlist.cpp"
//1、顺序表递增有序，插入元素 x，仍递增有序
void fun(int x){
    //特判下如果x大于等于最后一个最大的元素 直接插到屁股上
    if(x>=list.data[list.length-1])insertNum(list.length,x);
    else{
        //采用二分查找 快速定位需要插入的位置
    int l=0;int r=list.length-1;
    while(l<r){
        int mid=l+r>>1;
        if(list.data[mid]>=x)r=mid;
        else l=mid+1;
    }
        //找的是第一个大于等于x的数
        insertNum(l,x);
    }
    
}
int main (int argc,char *argv[]){
    initTest();
    fun(stoi(argv[1]));
    Print();
    return 0;
}