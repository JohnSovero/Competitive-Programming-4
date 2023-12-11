#include <bits/stdc++.h>
using namespace std;

void print(string &s){
    for(int i = s.size() - 1; i >= 0; --i){
        cout<<s[i];
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin.ignore();
        string s1, s2, s3 = "", s4="";
        bool ok = false;
        cin>>s1>>s2;
        int total = s1.size() + s2.size();
        int j = 0, k  = 0;
        for(int i = 1; i <= 1000 && !ok; ++i){
            s3 += s1[j];
            s4 += s2[k];
            if(s1[j] == s2[k]){
                int x = rand() / 141 % 2;
                //John
                if(x){
                    s4 += s3;
                    s3 = "";
                    cout<<"Snap! for John: ";
                    print(s4);
                }
                //Jane
                else{
                    s3 += s4;
                    s4 = "";
                    cout<<"Snap! for Jane: ";
                    print(s3);
                }
            }
            j++;
            k++;
            if(s1.size() == 0){
                cout<<"John wins.\n";
                ok = true;
                break;
            }
            else if(s2.size() == 0){
                cout<<"Jane wins.\n";
                ok = true;
                break;
            }
            if(j >= s1.size()){
                j = 0;
                s1 = s3;
                s3 = "";
                if(s1.size() == 0){
                    cout<<"John wins.\n";
                    ok = true;
                    break;
                }
            }
            if(k >= s2.size()){
                k = 0;
                s2 = s4;
                s4 = "";
                if(s2.size() == 0){
                    cout<<"Jane wins.\n";
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            cout<<"Keeps going and going ...\n";
        }
        if(t) 
            cout<<'\n';
    }   
    return 0;
}