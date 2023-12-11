#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t = 1; t <= T; ++t){
        int value [52];
        char value2 [52];
        char type [52];
        for(int i = 0; i < 52; ++i){
            string s;
            cin>>s;
            int x = s[0] - '0';
            type[i] = s[1];
            if(x >= 2 && x <= 9){
                value[i] = x;
            }
            else{
                value[i] = 10;
            }
            value2[i] = s[0];
        }
        int pos = 26;
        int y = 0;
        for(int i = 0; i < 3; ++i){
            int x = value[pos];
            if(x >= 2 && x <= 9){
                pos--;
                pos -= (10 - x);
            }
            else{
                pos--;
            }
            y += x;
        }
        int diff = 26 - pos;
        int ans = 0;
        if(y > pos){
            ans += (pos + diff + (y - pos - 1));
        }
        cout<<"Case "<<t<<": "<<value2[ans]<<type[ans]<<'\n';
    }
    return 0;
}