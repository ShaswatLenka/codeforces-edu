//credits: paksha

//In this task, you need to write a regular segment tree for the sum.
#include <bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<long long int> sums; //array to store the sums
    //increase size to closest power of 2
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0LL); //initialize the sums array
   
    }
    void build(vector<int> &a, int x, int lx, int rx){
        //if we are at the leaf nodes
        //we need to also see that the element belongs to a[] as we
        //had added extra elements at the end to make it a perfect
        //binary tree
        if(rx - lx == 1){
            if(lx < (int)a.size() ){
                sums[x] = a[lx];
            }
            return;
        }
        //if we are not at the bottom, we need to make the recursive 
        //calls again as usual
        int m = (lx + rx)/2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }
    void build(vector<int> &a){
        build(a, 0, 0, size);   
    }
    void set(int i, int v, int x, int lx, int rx){
        //if we are at the leaf node:
        //assign sum[x] = v and return from recursion
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        //if we are not at the bottom level, we need to decide
        //whether we should go to the left subtree of the right 
        int  m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        }else{
            set(i, v, 2*x + 2, m, rx);
        }
        sums[x] = sums[2*x + 1] + sums[2*x +2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        
        if(l >= rx || r <= lx) return 0;
        if(lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x +1, lx, m); //left subtree
        long long s2 = sum(l, r, 2*x +2, m, rx); //right subtree
        return s1 + s2;
    }

    long long sum(int l, int r){
        return sum(l, r, 0, 0, size);    
    }

};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;

    //initialize segment tree:
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    st.build(a);
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i,v;
            cin>>i>>v;
            st.set(i, v);
        }else{
            int l, r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<"\n";
        }
    
    }

    return 0;
}
