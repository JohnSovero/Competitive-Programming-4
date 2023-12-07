#include <bits/stdc++.h>
using namespace std;

int arr[100];
char word[6];
int t, pos;

int main(){
    scanf("%d", &t);
    while(t--){
        int n, ans = 0; 
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){  
            scanf("%s", &word);
            if(!strcmp(word, "LEFT")){
                ans--;
                arr[i] = -1;
            }
            else if(!strcmp(word, "RIGHT")){
                ans++;
                arr[i] = 1;
            }
            else{
                scanf("%s %d", &word, &pos);
                arr[i] = arr[pos];
                ans+= arr[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}