//https://open.kattis.com/problems/isithalloween
#include <bits/stdc++.h>
using namespace std;

int main(){
    char m [100];
    int d;
    scanf("%s%d", m, &d);
    if(strcmp(m, "OCT") == 0 && d == 31 || strcmp(m, "DEC") == 0 && d == 25){
        printf("yup");
    }
    else{
        printf("nope");
    }
    return 0;
}