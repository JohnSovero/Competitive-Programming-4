#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

vector<int> a(5);
vector<int> initialHand(5);
vector<pair<int, char>> initialSuits(5);
char x;

vector<char> suits = {'S', 'H', 'D', 'C'};

char int2card(int x) {
    switch (x) {
        case 0: return 'A';
        case 9: return 'T';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
        default: return '0' + x + 1;
    }
}

void card2Number(int p){
    if(x == 'T') a[p] = 9;
    else if(x == 'J') a[p] = 10;
    else if(x == 'Q') a[p] = 11;
    else if(x == 'K') a[p] = 12;
    else if(x == 'A') a[p] = 0;
    else a[p] = x - '0' - 1;
}

int card2Number2(int p){
    if(x == 'T') return 9;
    else if(x == 'J') return 10;
    else if(x == 'Q') return 11;
    else if(x == 'K') return 12;
    else if(x == 'A') return 0;
    else return x - '0' - 1;
}

double calcScore() {
    // Straight (run of 5)
    for(int i = 0; i < 5; ++i) {
        int cnt = 1;
        for(int j = 1; j < 5; ++j) {
            if((a[i] + j) % 13 == a[(i + j) % 5]) {
                cnt++;
            }
        }
        if(cnt == 5) return 100.0;
    }
    // Invite-the-Neighbours (run of 4)
    for(int i = 0; i < 5; ++i) {
        int cnt = 1;
        for(int j = 1; j < 5; ++j) {
            if((a[i] + cnt) % 13 == a[(i + j) % 5]) {
                cnt++;
            }
        }
        if(cnt == 4) return 10.0;
    }

    // Bed-and-Breakfast (run of 3 + run of 2)
    for(int i = 0; i < 5; ++i) {
        vector<bool> used(5, 0);
        used[i] = 1;
        int cnt = 1;
        for(int j = 1; j < 5; ++j) {
            if((a[i] + cnt) % 13 == a[(i + j) % 5]) {
                cnt++;
                used[(i + j) % 5] = 1;
            }
        }
        if(cnt == 3) {
            for(int k = 0; k < 5; ++k) {
                for(int l = 0; l < 5; ++l) {
                    if(used[k] == 0 && used[l] == 0 && k != l){
                        if((a[k] + 1) % 13 == a[l % 5] ) {
                            return 5.0;
                        }
                    }  
                }   
            }
            return 3.0;
        }
    }

    // Double Dutch (run of 2 + run of 2)
    for(int i = 0; i < 5; ++i) {
        for(int j = 1; j < 5; ++j) {
            if((a[i] + 1) % 13 == a[(i + j) % 5]) {
                for(int k = 0; k < 5; ++k) {
                    for(int l = 0; l < 5; ++l) {
                        if(k != i && k != ((i+j)%5) && l != i && l != ((i+j)%5) && k != l){
                            if((a[k] + 1) % 13 == a[l % 5] ) {
                                return 1.0;
                            }
                        }
                        
                    }   
                }
            }
        }
    }
    return 0;
}

int main(){
    string c;
    while(cin>>c, c != "#"){
        x = c[0];
        card2Number(0);
        initialSuits[0] = {card2Number2(c[0]), c[1]};
        for(int i = 1; i <= 4; ++i){
            cin>>c;
            x = c[0];
            initialSuits[i] = {card2Number2(c[0]), c[1]};
            card2Number(i);
        }
        sort(all(initialSuits));
        sort(all(a));
        for(int i = 0; i < 5; ++i){
            initialHand[i] = a[i];
        }
        double initialScore = calcScore() - 1;
        double bestScore = initialScore;
        int exchange = 0;
        for(int k = 0; k < 5; ++k){
            double score = 0;
            vector<int> taken(13, 0);
            for(int e = 0; e < 5; ++e){
                taken[initialHand[e]]++;
            }
            for(int i = 0; i < 4; ++i){
                for(int j = 0; j < 13; ++j){
                    if(taken[j] == 4) continue;
                    a[k] = j;
                    sort(all(a));
                    score += (calcScore()/47.0);
                    taken[j]++;
                    for(int p = 0; p < 5; ++p){
                        a[p] = initialHand[p];
                    }
                }
            }
            score -= 2;
            if(score > bestScore){
                bestScore = score;
                exchange = k;
            }
        }
        if(bestScore > initialScore){
            cout<<"Exchange "<<int2card(initialHand[exchange])<<initialSuits[exchange].second<<"\n";
        }
        else{
            cout<<"Stay\n";
        }
    } 
    return 0;
}
//TODO create a map to convert the cards to numbers, use only one array that contains the numbers and an auxiliar to verify if exits a card
//spades, hearts, diamonds, clubs -> s, h, d, c
//numbers -> A, 2, 3 ... T, J, Q, K
//it doesnt matter the suits

//first pay 1 dollar and gives you 5 cards
//you can stay or exchange one of your cards
//if you exchange yo pay another dollar

//An array from 0 to 51 for diamonds, then clubs, hearts, spades 
//sort values and verify how much is the run (for )  .
