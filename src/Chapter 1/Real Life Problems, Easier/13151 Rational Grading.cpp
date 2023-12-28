#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define all(v) v.begin(), v.end()
#define print(x) cout<<#x<<" : "<<x<<'\n'
template<class T> void So(vector<T> &v) {sort(v.begin(), v.end());}

string X;
int N;  

void solve();

int getValue(){
    if(X[1] == 'x') return stoi(X,0,16);
    else if(X[0]=='0') return stoi(X,0,8);
    else return stoi(X);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    while(cin>>X>>N, X != "0" && N){
        solve();
    }
    return 0;
}

void solve(){
    int val = getValue();
    int ans = 0;
    rep(n,0,N){
        string ins;
        int r;
        cin>>ins>>r;
        if(ins == "i"){
            if(val == r) ans++;
            if(val != r) val = r;
        }
        else if(ins == "++i"){
            ++val;
            if(val == r) ans++;
            if(val != r) val = r;
        }
        else if(ins == "i++"){
            if(val == r) ans++;
            if(val != r) val = r;
            val++;
        }
        else if(ins == "i--"){
            if(val == r) ans++;
            if(val != r) val = r;
            val--;
        }
        else if(ins == "--i"){
            --val;
            if(val == r) ans++;
            if(val != r) val = r;
        }
    }
    cout<<ans<<'\n';
}