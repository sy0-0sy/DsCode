//3、将顺序表中的元素逆置
#include"sqlist.cpp"
void convert(){
    int i=0;int j=list.length-1;
    while(i<j){
        swap(list.data[i++],list.data[j--]);
    }
}
int main(){
    initTest();
    cout<<"before: ";
    Print();
    convert();
    cout<<"after: ";
    Print();
    return 0;
}