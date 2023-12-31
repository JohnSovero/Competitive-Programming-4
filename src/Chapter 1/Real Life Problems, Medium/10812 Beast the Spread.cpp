#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define all(v) v.begin(), v.end()
#define print(x) cout<<#x<<" : "<<x<<'\n'
template<class T> void So(vector<T> &v) {sort(v.begin(), v.end());}

void solve(){
    int s, d;
    cin>>s>>d;
    int a = (s+d)/2;
    int b = s - a;
    if(a>=0 && b>= 0 && abs(a-b) == d){
        cout<<max(a,b)<<" "<<min(a,b)<<'\n';
    }
    else{
        cout<<"impossible\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    rep(t,0,T){
        solve();
    }
}
//s d
//a+b = s
//abs(a-b) = d
//a-b = d
//b-a = d

//a = (s+d)/2
//b = (s-d)/2