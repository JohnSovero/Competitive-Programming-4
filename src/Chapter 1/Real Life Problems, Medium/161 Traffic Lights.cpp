#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define all(v) v.begin(), v.end()
#define print(x) cout<<#x<<" : "<<x<<'\n'
template<class T> void So(vector<T> &v) {sort(v.begin(), v.end());}

int x,y,z;

void solve(){
    vector<int> duration(100);
    duration[0] = x;
    duration[1] = y;
    int n = 2;
    while(z != 0){
        duration[n] = z;
        cin>>z;
        n++;
    }
    duration.resize(n);
    vector<int> time(n, 0);
    int initial = INT_MAX;
    rep(i,0,n){
        initial = min(initial, duration[i]);
    }
    int seg = 0;
    rep(t,initial,18001){
        int flat = 1;
        rep(j,0,n){
            //if second is not in range, then update this range
            while(time[j] + duration[j] - 5 <= t){
                time[j] += 2*duration[j];
            }
            //is second is not in new range, then fail, and update second tho the part lower of this range
            if(!(time[j] <= t && t < time[j] + duration[j] - 5)){
                t = time[j] - 1;
                flat = 0;
                break;
            }
        }
        if(flat){
            seg = t;
            break;
        }
    }
    if(seg == 0){
        cout<<"Signals fail to synchronise in 5 hours\n";
    }
    else{
        int h = (seg/3600);
        int m = (seg%3600)/60;
        int s = (seg%3600)%60;
        cout<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    while(cin>>x>>y>>z, x||y||z){
        solve();
    }
    return 0;
}
//2x - 3x -5

//14 5  19 -> 14 5 19 -> 
//14 19 38 -> 52 57 76 ->

//15 5  20 -> 15 5 20 ->
//15 20 40 -> 55 60 80 -> 

//38 - 52
//40 - 55
//40 - 50
//37 - 40
//37 - 41
//37 - 39

//25 5  30 -> 25  5  30  -> 25  5   30  -> 25  5   30  -> 25  5   30  -> 25  5   35  -> 30  5   35  ->   
//25 30 60 -> 85  90 120 -> 145 150 180 -> 205 210 240 -> 265 270 300 -> 325 330 365 -> 405 410 440 ->

//20 5  25 -> 20  5  25  -> 20  5   25  -> 20  5   25  -> 20  5   25  -> 20  5   25  -> 20  5   25  ->  
//20 25 50 -> 70  75 100 -> 120 125 150 -> 170 175 200 -> 220 225 250 -> 270 275 300 -> 320 325 350 ->

//30 5  35 -> 30  5  35  -> 30  5   35  -> 30  5   35  -> 30  5   35  -> 30  5   35  -> 30  5   35  ->
//30 35 70 -> 100 95 140 -> 170 175 210 -> 240 245 280 -> 310 315 350 -> 380 385 420 -> 450 455 490 ->