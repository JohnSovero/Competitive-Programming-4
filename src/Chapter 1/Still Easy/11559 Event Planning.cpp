#include <bits/stdc++.h>
using namespace std;

int hotels[18][13];
int budget[18];

int main(){
    int n, b, h, w;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
        for(int i = 0; i < h; ++i){
            scanf("%d", &budget[i]);
            for(int j = 0; j < w; ++j){
                //TODO validate the answer in this for
                scanf("%d", &hotels[i][j]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(hotels[i][j] >= n){
                    ans = min(ans, budget[i] * n);
                };
            }
        }
        if(ans <= b){
            printf("%d\n", ans);
        }
        else{
            puts("stay home");
        }
    }
    return 0;
}