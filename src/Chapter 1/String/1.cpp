#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    string vowels = "aeiou";
    for(char c : vowels){
        if(ch == c)
            return 1;
    }
    return 0;
}

int main(){
    string T = "", s, p = "love";
    bool first = true, found = false;
    //1
    while(getline(cin, s)){        
        if(s.substr(0, 7) == ".......")
            break;
        if(!first)
            T += " ";
        T += s;
        first = false;
    }
    cout<<"Processing: "<<T<<endl;
    //2
    for(int i = 0; i < T.size() - p.size() + 1; ++i){
        //cout<<i<<" "<<i+3<<" "<<T.substr(i, 4)<<endl;
        if(T.substr(i, p.size()) == p){
            found = true;
            cout<<i<<" ";
        }
    }
    if(!found)
        cout<<"-1";
    cout<<"\n";
    //3
    int vowels = 0, consonants = 0, digits = 0;
    for(int i = 0; i < T.size(); ++i){
        T[i] = tolower(T[i]);
        if     (isVowel(T[i])) vowels++;
        else if(isdigit(T[i])) digits++;
        else if(isalpha(T[i])) consonants++;
    }
    cout<<digits<<" "<<vowels<<" "<<consonants<<endl;
    //4
    cout<<"Tolower: "<<T<<endl;
    vector<string> tokens;
    map<string, int> freq;
    istringstream iss(T);
    string token;
    while(getline(iss, token, ' ')){
        tokens.push_back(token);
        if(freq.find(token) == freq.end())
            freq[token] = 1;
        else
            freq[token]++;
    }
    sort(tokens.begin(), tokens.end());
    cout<<"Smallest lexicographically: "<<tokens[0]<<'\n';
    //Solution with c
    /*char* cstr = new char[T.size() + 1];
    trcpy(cstr, T.c_str());
    char* token = strtok(cstr, " ");
    while (token != NULL) {
        tokens.push_back(std::string(token));
        token = strtok(NULL, " ");
    }
    delete[] cstr;*/
    sort(tokens.begin(), tokens.end());
    cout<<"Smallest lexicographically: "<<tokens[0].c_str()<<'\n';
    //5
    cout<<"Frecuencia de "<<p<<": "<<freq[p]<<endl;
    //6
    string lastLine;
    while(getline(cin, lastLine)){
        //Keep reading lines until the end
    }
    cout<<"Length of the last line: "<< lastLine.size()<<endl;
    return 0;
}