#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main(){
    int a, c;
    while(scanf("%d %d", &a, &c), a){
        int ans = 0;
        scanf("%d", &arr[0]);
        //Count the height
        ans += a - arr[0];
        for(int i = 1; i < c; ++i){
            scanf("%d", &arr[i]);
            //Verify if exists a descent and sum the pieces
            if(arr[i-1] - arr[i] > 0){
                ans += arr[i-1] - arr[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}