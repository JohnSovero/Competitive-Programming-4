#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, r;
    scanf("%d%d", &l, &r);
    if(l == 0 && r == 0){
        printf("Not a moose");
    }
    else if(l == r){
        printf("Even %d", l + r);
    }
    else{
        printf("Odd %d", max(l, r) * 2);
    }
    return 0;
}