#include <bits/stdc++.h>
using namespace std;

int A[100001],  B[100001];

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b), a, b){
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        int x, cnt = 0, cnt2 = 0;
        for(int i = 0; i < a; ++i){
            scanf("%d", &x);
            A[x]++;
        }
        for(int i = 0; i < b; ++i){
            scanf("%d", &x);
            if(A[x] == 0 && B[x] == 0){
                cnt2++;
            }
            B[x]++;
        }
        for(int i = 0; i <= 100000; ++i){
            if(A[i] > 0 && B[i] == 0){
                cnt++;
            }
        }
        printf("%d\n", min(cnt, cnt2));
    }   
    return 0;
}