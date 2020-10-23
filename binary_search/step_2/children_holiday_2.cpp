#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli m,n;
vector<lli> v(n);
vector<lli> ti_vec(n);
vector<lli> zi_vec(n);

bool good(lli x){
    lli sum = 0;
    for (lli i = 0; i < n; i++) {
        lli div = x/v[i];
        lli div_bal = zi_vec[i] * div;
        if(x - div*v[i] >= zi_vec[i]*ti_vec[i]){
            sum += zi_vec[i];
        }else{
            sum += (x - div*v[i])/ti_vec[i]; 
        }
        sum += zi_vec[i]*div;
    }
    return sum >= m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin>>m>>n;
    for (lli i = 0; i < n; i++) {
        lli ti,zi,yi;
        cin>>ti>>zi>>yi;
        ti_vec.push_back(ti);
        zi_vec.push_back(zi);
        v.push_back(zi*ti + yi);
    }
    //special case: m=0;
    if(m == 0){
        cout<<0<<"\n";
        for (lli i = 0; i < n; i++) {
            cout<<0<<" ";
        }
        return 0;
    }
    lli r = 1e9;
    lli l = 0;
    while(r > l+1){
        lli  mid = (l+r)/2;
        if(good(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r<<"\n";

    //print individual baloons inflated
    lli sum = 0;
    for (lli i = 0; i < n; i++) {
        lli div = r/v[i];
        lli div_bal = zi_vec[i] * div;
        if(r - div*v[i] >= zi_vec[i]*ti_vec[i]){
            div_bal += zi_vec[i];
            sum += div_bal;
        }else{
            div_bal += (r - div*v[i])/ti_vec[i]; 
            sum += div_bal;
        }
        if(sum >= m && sum - div_bal < m) {
            cout<< div_bal - (sum - m) <<" ";
            continue;
        }
        if(sum - div_bal >= m){
            cout<<0<<" ";
            continue;
        }
        cout<<div_bal<<" ";
    }

return 0;
}
