// For a given connected undirected weighted graph find a spanning tree with minimum weight.
// Krushkal's algorithm
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int n,m;
vector<vector<pair<int,int> > > graph;
int arr[MAXN], rnk[MAXN];
set<pair<int, pair<int, int> > > s; 

void addEdge(int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void printGraph(){
    for(int i = 1; i < graph.size(); i++){
        cout<<"vertex "<< i <<"-> \n";
        for(auto j = graph[i].begin(); j != graph[i].end(); j++){
            cout<<"\t ( "<<j->first<<": w = "<<j->second<<" )"<<"\n";
        }
    }
}

//DSU -> get function
int get(int x){
    return arr[x] = (arr[x] == x ? x : get(arr[x]) ); 
}

//DSU -> union function
void Union(int x, int y){
    int p1 = get(x);
    int p2 = get(y);
    if(rnk[p1] > rnk[p2]){
        arr[p2] = p1;
        rnk[p1] = rnk[p2] + 1;
    }else{
        arr[p1] = p2;
        rnk[p2] = max(rnk[p2], rnk[p1] + 1);
    }
}

//minimum spanning tree
void mst(){
       long long weight = 0;
       for(auto it=s.begin(); it != s.end(); it++){
             int u = get(it->second.first);
             int v = get(it->second.second);
             if(u == v){
                 continue;
             }else{
                Union(u, v);
                weight += it->first;
             }
       }
       cout<<weight;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    memset(arr, 0, sizeof(arr));
    memset(rnk, 0, sizeof(rnk));
       
    cin>>n>>m;
   // graph.resize(n+1, {});
    for(int i = 0; i < m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            // addEdge(u, v, w);
            if(arr[u] == 0) arr[u] = u;
            if(arr[v] == 0) arr[v] = v;
            s.insert(make_pair(w, make_pair(u, v)));
    }
    //set<pair<int, pair<int, int> > >::iterator it = s.begin();
    //while(it != s.end()){
    //    cout<<it->first<<" "<<"\n";
    //    cout<<it->second.first<<" "<<it->second.second<<"\n";
    //    it++;
    //}

    mst();
return 0;
}
