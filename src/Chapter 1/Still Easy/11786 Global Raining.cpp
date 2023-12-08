#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int ans = 0;
        char word [10000];
        stack<int> st;
        scanf("%s", &word);
        for(int i = 0; i < 10000 && word[i] != '\0'; ++i){
            if(word[i] == '\\'){
                st.push(i);
            }
            else if(word[i] == '/' && !st.empty()){
                ans += i - st.top();
                st.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
//to have water we need -> \/, \_, \_/, \___/, 