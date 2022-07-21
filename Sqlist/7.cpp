//7、从有序表中删除所有值重复的元素
//暴力做法 遍历,因为是有序表,如果前一个元素和后一个元素相等则删除
#include"sqlist.cpp"
void delR(){
    int j=0;//保存当前最后一个不重复元素的index
    for(int i=1;i<list.length;i++){
        if(list.data[j]!=list.data[i])list.data[++j]=list.data[i];
    }
    list.length=j+1;//数组小标从0开始,总数的加1
}
int main(){
    initTest();
    cout<<"before: ";
    Print();
    delR();
    cout<<"after: ";
    Print();
    return 0;
}