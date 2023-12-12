#include <bits/stdc++.h>
#define push_back pb;
using namespace std;

int arr[53];

int main(){
    int a;
    while(cin>>a, a){
        vector<int> v(3, 0), v2(2, 0);
        memset(arr, 0, sizeof arr);
        v[0] = a;
        arr[a]++;
        for(int i = 1; i < 5; ++i){
            int x;
            cin>>x;
            if(i <= 2){
                v[i] = x;
            }
            else{
                v2[i-3] = x;
            }
            arr[x]++;
        }
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        int cnt = 0;
        for(int i = 0; i < 2; ++i){
            int x = v2[i];
            bool next = true;
            for(int j = 0; j < 3; ++j){
                if(x < v[j] && v[j] != 0){
                    v[j] = 0;
                    next = false;
                    break;
                }
            }
            if(next){
                for(int j = 0; j < 3; ++j){
                    if(x > v[j] && v[j] != 0){
                        v[j] = 0;
                        cnt++;
                        break;
                    }
                }
            }
        }
        int n, ans = -1;
        if(cnt == 1){
            for(int i: v){
                if(i != 0)
                    n = i;
            }
            for(int p = n + 1; p <= 52; ++p){
                if(arr[p] == 0){
                    ans = p;
                    break;
                }
            }
        }
        else{
            for(int p = 1; p <= 52; ++p){
                if(arr[p] == 0){
                    ans = p;
                    break;
                }
            }
        } 
        cout<<ans<<'\n';
    }
    return 0;
}
//28 29 51 
//50 52

//start with lowest value and find the next greater number that wins the another player,
//if there are not any value, find the lowest number 