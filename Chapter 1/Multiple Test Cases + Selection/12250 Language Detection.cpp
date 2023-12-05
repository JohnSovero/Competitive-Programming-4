#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[100];
    int i = 1;
    while(scanf("%s", s), strcmp(s, "#")){
        if (!strcmp(s, "HELLO"))
            printf("Case %d: ENGLISH\n", i);
        else if (!strcmp(s, "HOLA"))
            printf("Case %d: SPANISH\n", i);
        else if (!strcmp(s, "HALLO"))
            printf("Case %d: GERMAN\n", i);
        else if (!strcmp(s, "BONJOUR"))
            printf("Case %d: FRENCH\n", i);
        else if (!strcmp(s, "CIAO"))
            printf("Case %d: ITALIAN\n", i);
        else if (!strcmp(s, "ZDRAVSTVUJTE"))
            printf("Case %d: RUSSIAN\n", i);
        else
            printf("Case %d: UNKNOWN\n", i);
        i++;
    }
    return 0;
}