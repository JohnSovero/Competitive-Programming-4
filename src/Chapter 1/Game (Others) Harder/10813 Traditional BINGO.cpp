#include <bits/stdc++.h>
using namespace std;

int bingo[5][5];

bool win(){
    bool ok = false;
    for(int i = 0; i < 5; ++i){
        int c = 0;
        for(int j = 0; j < 5; ++j){
            if(bingo[i][j] == -1) ++c;
        }
        if(c == 5) ok = true;
    }
    for(int i = 0; i < 5; ++i){
        int c = 0;
        for(int j = 0; j < 5; ++j){
            if(bingo[j][i] == -1) ++c;
        }
        if(c == 5) ok = true;
    }
    int c = 0;
    for(int i = 0; i < 5; ++i){
        if(bingo[i][i] == -1) ++c;
    }
    if(c == 5) ok = true;
    c = 0;
    for(int i = 0; i < 5; ++i){
        if(bingo[i][4-i] == -1) ++c;
    }
    if(c == 5) ok = true;
    return ok;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        memset(bingo, 0, sizeof(bingo));
        bingo[2][2] = -1;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                if(i == 2 && j == 2) {
                    continue;
                }
                cin>>bingo[i][j];
            }
        }
          
        bool ok = false;
        bool first = false;
        for(int i = 0; i < 75; ++i){
            int x;
            cin>>x;
            int c = (x-1) / 15;
            for(int r = 0; r < 5; ++r){
                if(bingo[r][c] == x){
                    bingo[r][c] = -1;
                }
            }
            if(!first){
                ok = win();
            }
            if(ok && !first){
                cout<<"BINGO after "<<i+1<<" numbers announced\n";
                first = true;
            }
        }
    }
    return 0;
}
//5 rows and 5 columns, center is free
//when apeears a row, column or diagonal exists BINGO