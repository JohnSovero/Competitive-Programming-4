#include <bits/stdc++.h>
using namespace std;

char s1[110], s2[110];

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int ones = 0, ones2 = 0, q = 0, a = 0, b = 0;
        scanf("%s %s", s1, s2);
        for(int i = 0; i < strlen(s1); ++i){
            if(s1[i] == '1') a++;
            if(s2[i] == '1') b++;
            if(s1[i] == '?'){
                q++;
            }
            else if(s1[i] != s2[i]){
                if(s1[i] == '1') ones++;
                if(s2[i] == '1') ones2++;
            }
        }
        printf("%d %d\n", ones, ones2);
        printf("Case %d: ", t);
        if(a > b){
            puts("-1");
        }   
        else{
            printf("%d\n", q + max(ones, ones2));
        }
    }
    return 0;
}
//11??
//0010

//01??0
//10101