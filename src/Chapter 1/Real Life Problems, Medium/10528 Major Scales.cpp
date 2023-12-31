#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define all(v) v.begin(), v.end()
#define print(x) cout<<#x<<" : "<<x<<'\n'
template<class T> void So(vector<T> &v) {sort(v.begin(), v.end());}

string notes[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

int getValue(string s){
    rep(i,0,12){
        if(s==notes[i]) return i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int major[12] = {1,0,1,0,1,1,0,1,0,1,0,1};

    string line;
    while(getline(cin, line) && line!="END"){
        stringstream ss(line);
        vector<int> available(12,0);
        while(ss>>line){
            int value = getValue(line);
            available[value] = 1;
        }
        int n = 0;
        rep(i,0,12){
            bool ok = true;
            rep(j,0,12){
                if(available[(i+j)%12]){
                    if(!major[j]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                if(n++) 
                    cout<<" ";
                cout<<notes[i];
            }
        }
        cout<<'\n';
    }
    return 0;
}
