#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char c;
        int m, n, ans;
        //rows and columns
        cin>>c>>m>>n;
        if(c == 'r'){
            ans = min(m, n);
        }
        else if(c == 'k'){
            ans = ceil((m*n)/2.0);
        }
        else if(c == 'Q'){
            ans = min(m, n);   
        }
        else if(c == 'K'){
            ans = round(m/2.0) * round(n/2.0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}