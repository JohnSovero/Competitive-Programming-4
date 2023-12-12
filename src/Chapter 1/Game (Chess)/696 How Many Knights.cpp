#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    while(cin>>m>>n){
        int ans;
        if(m == 0 && n == 0)
            break;
        if(m == 1 || n == 1){
            ans = m * n;
        }
        else if(min(m,n) == 2){
            ans = 4 * (max(m,n) / 4) + (2 * min(2, max(m,n) % 4));
        }
        else{
            ans = ceil((m*n)/2.0);
        }
        cout<<ans<<" knights may be placed on a "<<m<<" row "<<n<<" column board.\n";
    }
    return 0;
}
//2 283


// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1

//if 
//0 1 0
//1 1 1

//5 6 - 9 10

//2 - 9 -> 10
// 1 1 0 0 1 1 0 0 1
// 1 1 0 0 1 1 0 0 1

//2 - 8 -> 8
// 1 1 0 0 1 1 0 0
// 1 1 0 0 1 1 0 0

//2 - 7 -> 8
// 1 1 0 0 1 1 0
// 1 1 0 0 1 1 0

//2 - 6 -> 8
// 1 1 0 0 1 1
// 1 1 0 0 1 1

//2 - 5 -> 6
// 1 1 0 0 1
// 1 1 0 0 1

// 1 1 0 0
// 1 1 0 0