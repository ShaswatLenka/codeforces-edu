#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;
int par[MAXN],rnk[MAXN],N, max_set[MAXN], min_set[MAXN], cnt[MAXN];

bool rm[MAXN];

int getPar(int x){
    if(par[x]==x)return x;
    par[x]=getPar(par[x]);
    return par[x];
}

void unitePar(int x,int y){
    int p1=getPar(x),p2=getPar(y);
    if(rnk[p1]>rnk[p2]){
        par[p2]=p1;//p1 becomes the leader
        rnk[p1]=rnk[p2]+1;
        if(max_set[p1] < max_set[p2]) max_set[p1] = max_set[p2];
        if(min_set[p1] > min_set[p2]) min_set [p1] = min_set[p2];
        cnt[p1] += cnt[p2];
    }
    else{
        par[p1]=p2; //p2 becomes the leader
        rnk[p2]=max(rnk[p2],rnk[p1]+1);
        if(max_set[p2] < max_set[p1]) max_set[p2] = max_set[p1];
        if(min_set[p2] > min_set[p1]) min_set[p2] = min_set[p1];
        if (p2 != p1){
            cnt[p2] += cnt[p1];
        }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,u,v;
    string s;
    cin>>n>>m;
    while(m--){
        cin >>s;
        if (s == "union"){
            cin>>u>>v;
            if(par[u] == 0) {
                par[u] = u;
                max_set[u] = u;
                min_set[u] = u;
                cnt[u] = 1;
            }
             if(par[v] == 0) {
                par[v] = v;
                max_set[v] = v;
                min_set[v] = v;
                cnt[v] = 1;
            }
             unitePar(u,v);
        }else{
            cin>>v;
            if(par[v] == 0){
                par[v] = v;
                max_set[v] = v;
                min_set[v] = v;
                cnt[v] = 1;
            }
                    cout<<min_set[getPar(v)]<<" "<<max_set[getPar(v)]<<" "<<cnt[getPar(v)]<<"\n";
        }
    }
    return 0;
}


