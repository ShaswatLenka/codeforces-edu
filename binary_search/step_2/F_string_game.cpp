/*
 *
 * Author: ribbit
 * Date Created: 13th Oct 2020
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

string p;
set<pair<char,int> > s;

bool good(){//(s)hortened (s)tring

    /*test*/
    cout<<"{ ";
    for(auto it=s.begin(); it!=s.end(); it++){
        cout<<"("<<it->first<<","<<it->second<<")";
    }cout<<" }"<<endl;

    bool flag = true;
    int  prev_index = -2; //some number less than -1(lowest value of l)
    for(int i = 0; i < p.length(); i++){
        char to_find = p[i];
        int l = -1;
        int r = s.size();
        set<pair<char, int> >::iterator sit = s.begin();

        //find closest to right
        while(r > l+1){
            int m = (l+r)/2;
            advance(sit, m);
            if(sit->first >= to_find && sit->second > prev_index) r = m;
            else l = m;
            sit = s.begin();
        }
        
        /*TEST*/
        cout<<to_find<<" "<<r<<" "<<l<<endl;

        //check if the index of current letter is less than the prev
        advance(sit, r);
        int curr_index = sit->second;
        
        /*TEST*/
        cout<<curr_index<<" "<<prev_index<<endl;

        if(r == s.size() || curr_index <  prev_index){
            flag = false;
            break;
        }else{
            prev_index = curr_index; 
        }
    } 
    cout<<flag<<endl;
    return flag;
}


void solve(){
    string t;
    cin>>t>>p;
    int del[t.length()]; 
    bool flag = true;
    int ctr=0;
    for(int i=0; i<t.length(); i++){
        cin>>del[i]; 
    }
    
    //save the letters and their indices in a set of pairs
    for(int i = 0; i < t.length(); i++){
        s.insert(make_pair(t[i], i));
    }
    
    for(int i = 0; i < t.length(); i++){
        cout<<t[del[i]-1]<<" "<<del[i]-1<<endl;

        //remove the pair according to the letter deleted
        auto del_it = s.find(make_pair(t[del[i]-1], del[i]-1));
        s.erase(del_it);

        if(good()){
            ctr++;
            cout<<"CTR: "<<ctr<<endl;
        }else{
            break;
        }
    }
    cout<<"reached end"<<endl;
    cout<<ctr;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
