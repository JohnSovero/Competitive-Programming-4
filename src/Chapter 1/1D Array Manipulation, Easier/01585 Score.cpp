#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char word [80];
        int ans = 0, j = 1;
        scanf("%s", &word);
        for(int i = 0; i < 80 && word[i] != '\0'; ++i){
            if(word[i] == 'O'){
                ans += j;
                j++;
            } 
            else j = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}