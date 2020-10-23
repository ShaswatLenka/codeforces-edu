/*
 * copies at time t -> (t/x + (t-1)/y )
 * worst case - (t/10 + (t-1)/10) >= 2*10^8 -> 10^10 + 1  
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int x,y;

bool good(ll t){
    int min_time = min(x,y);
    int max_time = max(x,y);
    ll nc = t/min_time + (t-min_time)/max_time;
    return nc >= n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//#endif

    cin>>n>>x>>y;

    ll l, r;
    l = 0;
    r = n*x*y;  
    while(r > l+1){
        ll m = (l+r)/2;
        if(good(m) ) r = m;
        else l = m;
    }
    cout << r;

    return 0;
}

