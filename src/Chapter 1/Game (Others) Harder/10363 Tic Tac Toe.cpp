#include <bits/stdc++.h>
using namespace std;
//29
char grid[3][3];

bool winColumn(int j) {
    return (grid[0][j] == grid[1][j] && grid[0][j] == grid[2][j]);
}

bool winRow(int i) {
    return (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]);
}
//double diagonal
bool winDiag(bool lr) {
    return lr ? (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) : (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]);
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int x = 0, o = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                cin>>grid[i][j];
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'O') o++;
            }
        }
        unordered_set<char> st;
        for (int i = 0; i < 3; ++i) {
            if (winRow(i)) st.insert(grid[i][0]);
            if (winColumn(i)) st.insert(grid[0][i]);
        }
        if (winDiag(true)) st.insert(grid[1][1]);
        if (winDiag(false)) st.insert(grid[1][1]);

        bool valid = false;
        //can win o
        if(x == o && st.count('X') == 0)  valid = true;
        //can win x
        else if(x == o + 1 && st.count('O') == 0) valid = true;

        cout << (valid ? "yes\n" : "no\n");
    }
    return 0;
}
//starts with x in an occupied grid