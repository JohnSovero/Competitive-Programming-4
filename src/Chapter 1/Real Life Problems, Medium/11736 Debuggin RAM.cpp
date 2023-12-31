#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define all(v) v.begin(), v.end()
#define print(x) cout<<#x<<" : "<<x<<'\n'
template<class T> void So(vector<T> &v) {sort(v.begin(), v.end());}

int bytes[256];
unsigned int val[256];

int32_t main(){
    int bits, n, q;
    while(cin>>bits>>n){
        string s;
        memset(val,0,sizeof(val));
        map<string,int> index;
        rep(i,1,n+1){
            cin>>s>>bytes[i];
            index[s] = i;
        }
        rep(i,1,n+1){
            string binary = "";
            rep(j,0,bytes[i]){
                cin>>s;
                binary += s;
            }
            rep(j,0,binary.size()){
                val[i] = (val[i]<<1) + binary[j] - '0';
            }
        }
        cin>>q;
        rep(i,0,q){
            cin>>s;
            cout<<s<<"=";
            if(index.count(s)){
                int x = index[s];
                cout<<val[x];
            }
            cout<<'\n';
        }
    }
    return 0;
}