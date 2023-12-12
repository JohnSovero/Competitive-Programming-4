#include <bits/stdc++.h>
using namespace std;

int arr[64];
int dy[5] = {-1, 1, 0, 0};
int dx[5] = {0, 0, -1, 1};

int main(){
    int k, q, pos;
    while(cin>>k>>q>>pos){
        memset(arr, 0, sizeof arr);
        //pos king
        arr[k] = -1;
        //pos queen
        arr[q] = -2;
        //fill king
        for(int i = 0; i < 4; ++i){
            int mov = k + dx[i] + dy[i] * 8;
            //validate be in the same column or row
            if(mov >= 0 && k / 8 == mov/8 || mov >= 0 && (mov % 8) == (k % 8) && mov <= 63){
                arr[mov] = 1;
            }
        }
        //fill queen
        for(int i = 0; i < 4; ++i){
            for(int j = 1; j <= 7; ++j){
                int mov = q + dx[i]*j + dy[i] *j*8;
                //validate be in the same column or row
                if(mov >= 0 && q / 8 == mov/8 || mov >= 0 && (mov % 8) == (q % 8) && mov <= 63){
                    if(arr[mov] == -1){
                        break;
                    }
                    arr[mov] += 2;
                }
            }
        }
        if(k == q){
            cout<<"Illegal state\n";
        }
        else if(arr[pos] <= 1){
            cout<<"Illegal move\n";
        }
        else if(arr[pos] == 3){
            cout<<"Move not allowed\n";
        }
        //possibles cases when king can't move
        else if((k == 0 && pos == 9) || (k == 7 && pos == 14) || (k == 56 && pos == 49) || (k == 63 && pos == 54)){
            cout<<"Stop\n";
        }
        else{
            cout<<"Continue\n";
        }  
    }
    return 0;
}
//represent like an array
//king move 1 pos in verticial, horizontal
//queen move all pos in vertical and horizontal
//0 - 63
//- 8 +1 /8 == row