#include <iostream>
#include <set>
using namespace std;
set<int> beg[2000005];
set<int> en[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            beg[i].insert(i+1);
            en[i+1].insert(i);
        }
    }
    bool c=1;
    while(c){
        c=0;
        for(int i=1;i<n-1;i++){
            for(int j:beg[i]){
                if(s[i-1]==s[j+1]&&!beg[i-1].count(j+1)){
                    beg[i-1].insert(j+1);
                    en[j+1].insert(i-1);
                    c=1;
                }
            }
        }
        for(int i=3;i<n-2;i++){
            for(int j:beg[i]){
                for(int k:en[i-1]){
                    if(!beg[k].count(j)){
                        beg[k].insert(j);
                        en[j].insert(k);
                        c=1;
                    }
                }
            }
        }
    }
    int p=0;
    for(int i=0;i<n;i++){
        p+=beg[i].size();
    }
    cout<<p;
    return 0;
}