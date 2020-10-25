
//credits: paksha

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct item{
  int m, c;   
};

struct segtree{
    int size;
    vector<item> seg_arr;
    
    //initialize segment tree
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        seg_arr.resize(2*size);
    }
    // function to combine the two child pairs
    item merge(item a, item b){
        if(a.m < b.m) return a;
        if(a.m > b.m) return b;
        return {a.m, a.c + b.c};
    }
    
    void build(vector<int> &arr, int x, int lx, int rx){
       //if at leaf, check the leaf is in between lx and rx
        if(rx - lx == 1){
            if(lx < arr.size()){
                seg_arr[x] = {arr[lx], 1}; 
            } 
            return;
        }
        //if not, go to the mid of lx and rx
        int m = (lx + rx)/2;
        build(arr, 2*x + 1, lx, m); //go left
        build(arr, 2*x + 2, m, rx); //go right
        seg_arr[x] = merge(seg_arr[2*x + 1], seg_arr[2*x + 2]);
    }

    void build(vector<int> &a){
        build(a, 0, 0, size); 
    }
    
    item single(int v){
        return {v, 1}; 
    }

    void set(int i, int v, int x, int lx, int rx){
        //if at leaf node, assign seg_arr[x] = v and return
        if(rx - lx == 1){
            seg_arr[x] = single(v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        }else{
            set(i, v, 2*x + 2, m, rx); 
        }

        seg_arr[x] = merge(seg_arr[2*x + 1], seg_arr[2*x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size); 
    }
    
    item NEUTRAL_ELEMENT = {INF, 0};

    item calc(int l, int r, int x, int lx, int rx){
        if(l >= rx || r <= lx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return seg_arr[x];
        int m = (lx + rx)/2;
        item s1 = calc(l, r, 2*x + 1, lx, m);
        item s2 = calc(l, r, 2*x + 2, m, rx);
        return merge(s1,s2);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size); 
    }

};

void solve(){
    int n, m; cin>>n>>m;
    vector<int> arr(n);
    segtree st;
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    st.init(n);
    st.build(arr);
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin>>i>>v;
            st.set(i,v);
        }else{
            int l, r;
            cin>>l>>r;
            auto res = st.calc(l, r);
            cout<<res.m<<" "<<res.c<<"\n";
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
