#include <bits/stdc++.h>
using namespace std;

int ans [1000001];
int snakes [1000001];
int ladders [1000001];

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        fill(ans, ans + 1000001, 1);
        memset(snakes, -1, sizeof snakes);
        memset(ladders, -1, sizeof ladders);
        int p, s, c;
        cin>>p>>s>>c;
        for(int i = 1; i <= s; ++i){
            int snake, ladder;
            cin>>snake>>ladder;    
            snakes[snake] = ladder;
            ladders[ladder] = snake;
        }
        bool ok = true;
        for(int i = 1; i <= c; ++i){
            int x;
            cin>>x;
            if(!ok){
                continue;
            }
            if(p){
                int pos = (i - 1) % p + 1;
                ans[pos] += x;
                if(snakes[ans[pos]] != -1){
                    ans[pos] = snakes[ans[pos]];
                }
                if(ans[pos] >= 100){
                    ans[pos] = 100;
                    ok = false;
                }
            }
        }
        for(int i = 1; i <= p; ++i){
            cout<<"Position of player "<<i<<" is "<<ans[i]<<".\n";
        }
    }
    return 0;
}
//0 2 4
//7 50
//56 2
//6
//1
//6
//1

//if square is in bottom of a ladder, move to top of the ladder
//if square contain the mouth of a snake, move to tail of the snake
//100 doesnt contain snake or ladder
//win if you reached 100