//https://www.acwing.com/problem/content/850/
//有向图的拓扑序列
//利用队列来辅助我们完成
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt[N],ne[N],e[N],g[N],Q[N],idx,s,r;
void add(int a,int b){
    e[idx]=b;ne[idx]=g[a];g[a]=idx++;cnt[b]++;
}
void topSort(int n){
    for(int i=1;i<=n;i++){
        if(cnt[i]==0)Q[++r]=i;
    }
    while(s!=r){
        int index=g[Q[++s]];
        for(int i=index;i!=-1;i=ne[i]){
            if(--cnt[e[i]]==0)Q[++r]=e[i];
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    memset(g,-1,sizeof g);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        add(a,b);
    }
    topSort(n);
    //如果有n个元素入队说明有topsort
    if(n==r)for(int i=1;i<=n;i++)cout<<Q[i]<<" ";
    else cout<<"-1";
    puts("");
    return 0;
}