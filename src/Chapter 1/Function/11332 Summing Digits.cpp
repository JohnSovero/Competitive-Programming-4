#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n <= 0)
        return 0;
    return n % 10 + sum(n / 10);
}
int main(){
    int n;
    while(scanf("%d", &n), n){
        while(n >= 10)
            n = sum(n);
        printf("%d\n", n);
    }
    return 0;
}