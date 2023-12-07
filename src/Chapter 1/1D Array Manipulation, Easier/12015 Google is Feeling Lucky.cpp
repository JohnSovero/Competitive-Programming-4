#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        char url[10][100];
        int highest[10];
        int high = INT_MIN;
        for(int i = 0; i < 10; ++i){
            scanf("%s %d", &url[i], &highest[i]);
            high = max(high, highest[i]);
        }
        printf("Case #%d:\n", t);
        for(int i = 0; i < 10; ++i){
            if(highest[i] == high){
                printf("%s\n", url[i]);
            }
        }

    }
    return 0;
}