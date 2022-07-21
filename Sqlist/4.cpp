//4、将（a1,a2,a3……am,b1,b2,……bn）转换成( b1,b2,……bn,a1,a2,a3,……am )
#include"sqlist.cpp"
//先convert全部,再分别convert ai bi
void convert(){
    int i=0;int j=9;//a1~a5 b1 ~ b5
    while(i<j){
        swap(list.data[i++],list.data[j--]);
    }
    i=0;j=4;
     while(i<j){
        swap(list.data[i++],list.data[j--]);
    }
    i=5;j=9;
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
