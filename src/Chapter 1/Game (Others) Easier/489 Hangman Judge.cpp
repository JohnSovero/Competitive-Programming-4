#include <bits/stdc++.h>
using namespace std;

int main(){
    int r;
    while(cin>>r, r != -1){
        string sol, guesses;
        cin>>sol>>guesses;
        set<char> st, st2;
        for(int i = 0; i < sol.size(); ++i){
            st.insert(sol[i]);
        }
        int n = st.size();
        int good = 0, wrong = 0;
        string ans = "";
        cout<<"Round "<<r<<'\n';
        for(int i = 0; i < guesses.size(); ++i){
            char c = guesses[i];
            if(st.count(c)){
                good++;
                st.erase(c);
            }
            else if(!st2.count(c)){
                wrong++;
                st2.insert(c);
            }
            if(good == n){
                ans = "You win.\n";
                break;
            }
            else if(wrong == 7){
                ans = "You lose.\n";
                break;
            }
        }
        if(ans == ""){
            cout<<"You chickened out.\n";
        }
        else{
            cout<<ans;
        }
    }
    return 0;
}