#include <bits/stdc++.h>
using namespace std;

int calculate(char n[26]){
    int sum = 0, temp;
    for(int i = 0; i < 26 && n[i] != '\0'; ++i){
        char c = tolower(n[i]);
        if(c >= 'a' && c <= 'z'){
            sum += c - 'a' + 1;
        }    
    }
    while(sum >= 10){
        temp = 0;
        while(sum > 0){
            temp += sum % 10;
            sum /= 10;
        }        
        sum = temp;
    }
    return sum;
}
int main(){    
    char n1[26], n2[26];
    int fi, se;
    while(gets(n1) && gets(n2)){
        fi = calculate(n1);
        se = calculate(n2);
        printf("%.2f %%\n", min(fi, se) * 100.0 / max(fi, se));
    }
    return 0;
}