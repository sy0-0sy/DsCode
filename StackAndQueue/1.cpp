//1、Q 是一个队列，S 是一个空栈，编写算法使得队列中元素逆置
#include"public.cpp"
void initQ(){
    for(int i=0;i<5;i++){
        inQueue(i);
    }
    cout<<"the number in Q: ";
    for(int i=0;i<5;i++)cout<<Q[i]<<" ";
    cout<<endl;
}
void convert(){
    //思路很简单,将队列中的元素依次出队到栈中,在弹栈即可
    while(!isQueueEmpty()){
        push(outQueue());//入栈
    }
    while(!isStackEmpty()){
        cout<<pop()<<" ";//弹栈
    }
    cout<<endl;
}
int main(){
    initQ();
    convert();
    return 0;
}
