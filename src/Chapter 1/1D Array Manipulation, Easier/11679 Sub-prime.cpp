#include <bits/stdc++.h>
using namespace std;

int main(){
    int b, n, owe, owed, amount;
    while(scanf("%d %d", &b, &n), b){
        int banks[20];
        for(int i = 0; i < b; ++i){
            scanf("%d", &banks[i]);
        }
        //pay the debenture
        while(n--){
            scanf("%d %d %d", &owe, &owed, &amount);
            banks[owe - 1] -= amount;
            banks[owed - 1] += amount;
        }
        //verify is any bank can pay the amount
        bool can = 1;
        for(int i = 0; i < b; ++i){
            if(banks[i] < 0) {
                can = 0;
                break;
            }
        }
        if(can) 
            cout<<"S\n";
        else 
            cout<<"N\n";
    }
    return 0;
}
//number of banks, number of debentures
//monetary reserves of each B
//debtor bank, creditor bank, debenture value