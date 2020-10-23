#include<bits/stdc++.h>
using namespace std;
double C;
bool good(double x){
    return x*x + sqrt(x) > C;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>C;

    double l = 0;
    double r = 1e8;

    for (int i = 0; i < 1000; i++) {
        double m = (l+r)/2;
        if(good(m)) r = m;
        else l = m;
    }
    cout<<setprecision(20)<<r<<"\n";

return 0;
}
