#include <bits/stdc++.h>
using namespace std;
#define MAX 2000001
int N;
int  p[MAX], rnk[MAX], energy_arr[MAX];

int getParent(int x){
    return p[x] = (p[x] == x ? x : getParent(p[x]));
}

void Get(int x){
    cout<<energy_arr[x]<<"\n";
}

void Add(int x, int E ){
    int team = getParent(x);
    for(int i=1; i<=N; i++){
        if(p[i] == team || getParent(p[i]) == team)
            energy_arr[i] += E;
    }
}

void Union(int x, int y){ // x will be in the team of y
    int u = getParent(x);
    int v = getParent(y);
    if(u == v){
        return;
    }
    if(rnk[u] > rnk[v]){
        p[v] = u;
        rnk[u] = rnk[v] + 1;
    }else{
        p[u] = v;
        rnk[v] = max(rnk[v], rnk[u] + 1);
    }   
    
}

void solve(){
    int m;
    cin>>N>>m;
    memset(rnk, 1, sizeof(rnk)); 
    while(m--){
        string s; int X, Y;
        cin >> s;
        if(s == "join"){
            cin>>X >>Y;
            if(p[X] == 0) {
                p[X] = X;
                Add(X,0);
            }
            if(p[Y] == 0){
                p[Y] = Y;
                Add(Y,0);
            }
            Union(X, Y);
            continue;
        }
        if(s == "add"){
            cin>>X>>Y;
            if(p[X] == 0){
                 p[X] = X;
                 Add(X,0);
            }
            Add(X, Y);
            continue;
        }
        if(s == "get"){
            cin>>X;
            if(p[X] == 0) {
                p[X] = X;
                Add(X,0);
            }
            Get(X);
            continue;
        }

    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
return 0;
}
