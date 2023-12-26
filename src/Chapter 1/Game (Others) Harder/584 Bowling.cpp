#include <bits/stdc++.h>
using namespace std;

int arr[21];

int main(){
    string s;
    while(getline(cin, s), s != "Game Over"){
        istringstream ss(s);
        int pos = 0, ans = 0, cnt = 0;
        while(ss>>s){
            if(s == "X"){
                arr[pos] = 10;
                cnt++;
            }
            else if(s == "/"){
                arr[pos] = 10 - arr[pos-1];
            }
            else{
                arr[pos] = stoi(s);
            }
            pos++;
        }
        for(int frame = 0, roll = 0; frame < 10; ++frame){
            if(arr[roll] == 10){
                ans += arr[roll] + arr[roll+1] + arr[roll+2];
                ++roll;
            }
            else if(arr[roll] + arr[roll+1] == 10){
                ans += 10 + arr[roll+2];
                roll+=2;
            }
            else{
                ans += arr[roll] + arr[roll+1];
                roll+=2;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//10 frames
//first attempt -> strike
//second attemp -> spare
//score sum of the scores for each frame
//total number of pins + strikes + spares
//strike = 10 + next 2 rolls
//spare = 10 + next rolls

//strike in the final frame -> 2 more attempts
//spare in the final frame -> 1 more attempt