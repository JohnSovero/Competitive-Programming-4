#include <bits/stdc++.h>
using namespace std;

string guess, number, gue, num;
int good, wrong, n, ans;

void bt(int pos){
    if(pos == n){
        gue = guess;
        num = number;
        int equal = 0, stay = 0;
        for(int i = 0; i < n; ++i){
            if(num[i] == gue[i]){
                equal++;
                num[i] = gue[i] = ' ';
            }
        }
        for(int i = 0; i < n; ++i){
            if(num[i] != ' '){
                for(int j = 0; j < n; ++j){
                    if(gue[j] != ' '){
                        if(num[i] == gue[j] && i != j){
                            stay++;
                            num[i] = gue[j] = ' ';
                        }
                    }
                }
            }
        }
        if(good == equal && wrong == stay){
            ans++;
        }
        return;
    }
    //generate
    else{
        for(int i = 1; i <= 9; ++i){
            number[pos] = i + '0';
            bt(pos + 1);
        }
    }
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cin>>guess>>good>>wrong;
        ans = 0;
        n = guess.size();
        number.resize(n, ' ');
        bt(0);
        cout<<ans<<'\n';
    }
    return 0;
}