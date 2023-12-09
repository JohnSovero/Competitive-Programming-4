#include <bits/stdc++.h>
using namespace std;

int main(){
    int l;
    char word[3];
    while(scanf("%d", &l), l){
        char c = 'x';
        int sign = 1;
        for(int i = 0; i < l-1; ++i){
            scanf("%s", &word);
            if(word[0] == 'N') continue;

            if(c == 'x') {
                if(word[0] == '-'){
                    sign = sign * -1;
                }
                c = word[1];
            }
            else if(word[1] == 'y' && c == 'y'){
                if(word[0] == '+') 
                    sign = sign * -1;        
                c = 'x';
            }
            else if(word[1] == 'z' && c == 'z'){
                if(word[0] == '+') 
                    sign = sign * -1;
                c = 'x';
            }
            else if(word[1] == 'y' && c == 'z'){
                c = 'z';
            }
            else if(word[1] == 'z' && c == 'y'){
                c = 'y';
            }
        }
        printf("%c%c\n", sign == 1? '+' : '-', c);
    }
    return 0;
}