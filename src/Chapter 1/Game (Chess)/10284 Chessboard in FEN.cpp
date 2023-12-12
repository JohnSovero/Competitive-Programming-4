#include <bits/stdc++.h>
using namespace std;

int dir[4][2] =  {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int diag[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int ndir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

char board[8][8];
int mat[8][8];
int mx, my, L, R;

bool isInRange(int x, int y){
    return (x >= 0 && x<=7 && y >= 0 && y <=7);
}
void bMove(int y, int x){
    for(int i = 0; i < 4; ++i){
        mx = x;
        my = y;
        do{
            mat[my][mx] = 1;
            mx += diag[i][0];
            my += diag[i][1];
        }while(isInRange(mx, my) && board[my][mx] == ' ');
    }
}

void rMove(int y, int x){
    for(int i = 0; i < 4; ++i){
        mx = x, my = y;
        do{
            mat[my][mx] = 1;
            mx += dir[i][0];
            my += dir[i][1]; 
        }while(isInRange(mx, my) && board[my][mx] == ' ');
    }
}

void pMove(int y, int x){
    if(board[y][x] == 'p'){
        L = 0, R = 2;
    }
    else{
        L = 2, R = 4;
    }
    for(int i = L; i < R; ++i){
        mx = x + diag[i][0];
        my = y + diag[i][1];
        if(isInRange(mx, my)){
            mat[my][mx] = 1;
        }
    }
}
void nMove(int y, int x){
    for(int i = 0; i < 8; ++i){
        mx = x + ndir[i][0];
        my = y + ndir[i][1];
        if(isInRange(mx, my)){
            mat[my][mx] = 1;
        }
    }
}

void qMove(int y, int x){
    for(int i = 0; i < 4; ++i){
        mx = x, my = y;
        do{
            mat[my][mx] = 1;
            mx += dir[i][0];
            my += dir[i][1]; 
        }while(isInRange(mx, my) && board[my][mx] == ' ');
        mx = x, my = y;
        do{
            mat[my][mx] = 1;
            mx += diag[i][0];
            my += diag[i][1]; 
        }while(isInRange(mx, my) && board[my][mx] == ' ');
    }
}

void kMove(int y, int x){
    for(int i = 0; i < 4; ++i){
        mx = x + dir[i][0];
        my = y + dir[i][1];
        if(isInRange(mx, my)){
            mat[my][mx] = 1;
        }
        mx = x + diag[i][0];
        my = y + diag[i][1];
        if(isInRange(mx, my)){
            mat[my][mx] = 1;
        }
    }
}

int main(){
    string s;
    while(cin>>s){
        memset(board, ' ', sizeof board);
        memset(mat, 0, sizeof mat);
        int col = 0, row = 0;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            col = (col + 8) % 8;
            if(c == '/'){
                row++;
                continue;
            }
            else if(isdigit(c)){
                int limit = c - '0';
                for(int j = 0; j < limit; ++j){
                    board[row][col++] = ' ';
                }
            }
            else if(tolower(c) != 'p'){
                mat[row][col] = 1;
                board[row][col++] = tolower(c);
            }
            else{
                mat[row][col] = 1;
                board[row][col++] = c;
            }
        }
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                char c = board[i][j];
                if(c == 'k'){
                   kMove(i, j);
                }
                else if(c == 'q'){
                    qMove(i, j);
                }
                else if(c == 'n'){
                    nMove(i, j);
                }
                else if(c == 'p' || c == 'P'){
                    pMove(i, j);
                }
                else if(c == 'r'){
                    rMove(i, j);
                }
                else if(c == 'b'){
                    bMove(i, j);
                }
            }   
        }
        int ans = 0;
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(mat[i][j] == 0)
                    ans++;
            }   
        }
        cout<<ans<<'\n';
    }
    return 0;
}