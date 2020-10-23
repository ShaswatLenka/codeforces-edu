#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
int par[MAXN],rnk[MAXN],N;
bool rm[MAXN];
int getPar(int x){
    if(par[x]==x)return x;
    par[x]=getPar(par[x]);
    return par[x];
}

void unitePar(int x,int y){
    int p1=getPar(x),p2=getPar(y);
    if(rnk[p1]>rnk[p2]){
        par[p2]=p1;
        rnk[p1]=rnk[p2]+1;
    }
    else{
        par[p1]=p2;
        rnk[p2]=max(rnk[p2],rnk[p1]+1);
    }
}

void disunion(int nroot){
    int p;
    for(int i=0;i<N;++i)getPar(i);
    for(int i=0;i<N;++i){
        p=getPar(i);
        if(rm[p]&&!rm[i]){
            par[p]=i;
            par[i]=i;
        }
    }
    for(int i=0;i<N;++i)getPar(i);
    for(int i=0;i<N;++i){
        if(rm[i]){
            par[i]=nroot;
            rm[i]=0;
        }
    }
    memset(rnk,0,sizeof(rnk));
    for(int i=0;i<N;++i){
        p=getPar(i);
        if(p!=i)rnk[p]=1;
    }
}

int main(){
    int m,n,u,v;
    string s;
    cin>>n>>m;
    while(m--){
        cin >>s>>u>>v;
        if(par[u] == 0) par[u] = u;
        if(par[v] == 0) par[v] = v;
        if(s == "union"){
            unitePar(u, v);
        }else{
            if (getPar(u) == getPar(v)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";

            }
        }
    }

    return 0;
}

