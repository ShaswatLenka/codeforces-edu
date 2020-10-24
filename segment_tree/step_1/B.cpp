#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000

struct segtree{
    int size;
    vector<int> mins;

    void init(int n){
        size = 1;
        while(size < n) size *=2;
        mins.assign(2*size, INF);
    }

    void build(vector<int> &arr, int x, int lx, int rx){
        //if at bottom, check whether the number belongs to the input array
        if (rx - lx == 1){
            if(lx < (int)arr.size()){
                mins[x] = arr[lx]; 
            } 
            return;
        } 

        //not at bottom, make recursive calls
        int m = (lx + rx)/2;
        build(arr, 2*x + 1, lx, m);
        build(arr, 2*x + 2, m, rx);
        mins[x] = min(mins[2*x + 1], mins[2*x + 2]);
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, size); 
    }

    void set(int i, int v, int x, int lx, int rx){
        //if at leaf node, assign mins[x] = v and return from recursion
        if(rx - lx == 1){
            mins[x] = v;
            return;
        }
        //if not at leaf node, decide whether to go left or to the right
        int m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        }else{
            set(i, v, 2*x + 2, m, rx); 
        }
        mins[x] = min(mins[2*x + 1], mins[2*x + 2]);
    }

    void set(int i, int v){
        set(i, v, 0, 0, size); 
    }

    int calc(int l, int r, int x, int lx, int rx){
        if(l >= rx || r <= lx) return INF;
        if(lx >= l && rx <=r) return mins[x];
        int m = (lx+rx)/2;
        int s1 = calc(l, r, 2*x + 1, lx, m);
        int s2 = calc(l, r, 2*x + 2, m, rx);
        return min(s1, s2);
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

};


void solve(){
    int n, m; cin>>n>>m;

    segtree st;
    st.init(n);

    vector<int> arr(n);
    for(int i=0; i<n; i++){
         cin>>arr[i];
    }

    st.build(arr);

    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        }else{
            int l, r;
            cin>>l>>r;
            cout<<st.calc(l,r)<<"\n";
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
}
