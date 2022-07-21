//删除顺序表中所有值为 x 的元素(两种方法)
#include"sqlist.cpp"
void delAll1(int x){
    //遇到不是x的数就将其前移,并用k记录不是x数的个数,然后设置length为k即可
    int k=0;
    for(int i=0;i<list.length;i++){
        if(list.data[i]!=x)list.data[k++]=list.data[i];
    }
    list.length=k;
}
void delAll2(int x){
    //遇到是x的数记录个数k,代表后面的非x元素能往前移动k个单位,最后设置length为length-k即可
    int k=0;
    for(int i=0;i<list.length;i++){
        if(list.data[i]==x)k++;
        else{
            list.data[i-k]=list.data[i];
        }
    }
    list.length-=k;
}
int main(int argc,char *argv[]){
    initTest();
    cout<<"before: ";
    Print();
    delAll2(stoi(argv[1]));
    cout<<"after: ";
    Print();
    return 0;
}