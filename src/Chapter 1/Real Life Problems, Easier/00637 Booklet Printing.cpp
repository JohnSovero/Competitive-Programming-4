#include <bits/stdc++.h>
using namespace std;

int n;

void solve(){
    cout<<"Printing order for "<<n<<" pages:\n";
    if (n == 1) {
        cout << "Sheet 1, front: Blank, 1\n";
        return;
    }
    //take the multiple of 4
    int pages = (n+3) / 4;
    int rest = pages * 4 - n;
    for(int p = 1; p <= pages*2; ++p){
        if(p & 1){
            cout<<"Sheet "<<(p+1)/2<<", front: "<<((rest > 0)? "Blank": to_string(n--))<<", "<<p<<"\n";
        }
        else{
            cout<<"Sheet "<<(p+1)/2<<", back : "<<p<<", "<<((rest <= 0)? to_string(n--) : "Blank")<<"\n";
        }
        rest--;
    }
}

int main(){
    while(cin>>n, n){
        solve();
    }
    return 0;
}