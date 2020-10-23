#include<bits/stdc++.h>
using namespace std;

int main(){
    set<pair<char, int> > s;
    s.insert(make_pair('a',1));
    s.insert(make_pair('b',2));
    s.insert(make_pair('a',3));
    s.insert(make_pair('b',4));
    s.insert(make_pair('c',5));
    s.insert(make_pair('b',6));
    s.insert(make_pair('a',7));
    
    //auto del_it = s.find(make_pair('b', 2));
    s.erase(make_pair('b',2));

    for(auto it = s.begin(); it!=s.end(); it++){
        cout<<it->first<<" "; 
    }


    return 0;
}
