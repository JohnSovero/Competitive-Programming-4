#include <bits/stdc++.h>
using namespace std;

char mat[101][101];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int rows, cols, tc = 1;

bool isInRange(int y, int x){
    return (x >= 0 && x < cols && y >= 0 && y < rows);
}

int main(){
    cin>>rows>>cols, rows, cols;
    while(rows, cols){
        memset(mat, ' ', sizeof mat);
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                char x;
                cin>>x;
                mat[r][c] = x;
            }
        }
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(mat[r][c] == '.'){
                    int cnt = 0;
                    for(int d = 0; d < 8; ++d){
                        int my = r + dir[d][0];
                        int mx = c + dir[d][1];
                        if(isInRange(my, mx)){
                            if(mat[my][mx] == '*'){
                                cnt++;
                            }
                        }
                    }
                    mat[r][c] = cnt + '0';
                }
            }
        }
        cout<<"Field #"<<tc++<<":\n";
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                cout<<mat[r][c];
            }
            cout<<'\n';
        }
        cin>>rows>>cols;
        if(rows != 0 && cols != 0){
            cout<<'\n';
        }
    }
    return 0;
}