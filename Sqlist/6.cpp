//6、从顺序表中删除给定值在 s 到 t 之间（包含 s 和 t）的所有元素
#include"sqlist.cpp"
//思路与5大同小异,碰到s到t之外的数记录然后删除,记录个数k最后修改length为k
void delStoT1(int s,int t){
    int k=0;
    for(int i=0;i<list.length;i++){
         if(list.data[i]<s || list.data[i]>t)list.data[k++]=list.data[i];
    }
    list.length=k;
}
//记录s和t之内的元素个数k,碰到非s和t的数,将其前移k个元素,最后length-=k
void delStoT2(int s,int t){
    int k=0;
    for(int i=0;i<list.length;i++){
         if(list.data[i]<s || list.data[i]>t)list.data[i-k]=list.data[i];
         else k++;
    }
    list.length-=k;
}
int main(int argc,char *argv[]){
    initTest();
    cout<<"before: ";
    Print();
   delStoT2(stoi(argv[1]),stoi(argv[2]));
    cout<<"after: ";
    Print();
    return 0;
}