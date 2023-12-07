#include <bits/stdc++.h>
using namespace std;

char s[5][41];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 5; ++i){  
        scanf("%s", &s[i]);
    }
    for(int i = 0; i < 4*n; i+=4){
        if(s[3][i+1] == '*') 
            printf("%d", 1);
        else if(s[3][i] == '*') 
            printf("%d", 2);
        else 
            printf("%d", 3);
    }
    printf("\n");
    return 0;
}