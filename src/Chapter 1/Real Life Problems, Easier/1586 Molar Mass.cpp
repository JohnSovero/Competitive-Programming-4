#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}

//24 min

void solve();

double getWeight(char c){
    if(c == 'C') return 12.01;
    if(c == 'H') return 1.008;
    if(c == 'O') return 16.00;
    if(c == 'N') return 14.01;
    return 0.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin>>t;
    cout<<fixed<<setprecision(3);
    rep(i, 0, t) 
        solve();
    return 0;
}

void solve(){
    string f;
    cin>>f;
    double ans = 0;
    rep(i,0,f.size()){
        char c = f[i];
        int n = 0;
        double w = getWeight(c);
        rep(j, i+1, f.size()){
            if(isdigit(f[j])){
                n*= 10;
                n+= (f[j] - '0');
            } 
            else{
                i = j-1;
                break;
            }
        }
        if(n == 0) n = 1;
        ans += (w * n);
    }
    cout<<ans<<'\n';
}