#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
using namespace std;
struct _{int f,t,i;}E[200009];
int N,i,n,n2,A=0;
string S,S2;
inline void spt(string &dest,string s,int fr,int lt){
    dest.resize(s.size());
    int T=0;
    for(int q=0;q<lt;q++){dest[T++]=s[fr++];}
    dest.erase(T);
}
inline bool vrf(string s){
    string sbk=s;
    int g=1,sz=s.size();
    while(g && sz){
        g=0;
        for(int q=0;q<s.size()-1;q++){
                //cout << " "<<s<<"  "<<s[q]<<s[q+1]<<"\n";
                if(s[q]==s[q+1]){
                    //cout << "Yes\n";
                    sz-=2;
                    //cout << " "<<sz<<endl;
                    s.erase(q,2);g=1;
                    //cout << "aft "<<s<<endl;
                    break;
        }}
    }
    if(sz){return 0;}
    //cout << " "<<sbk<<"\n";
    A=A+1;
    return 1;
}
int main(){
    ios::sync_with_stdio(1);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> N;
    cin >> S;
    for(int l=2;l<=N;l++){
        for(int q=0;q<=N-l;q++){
            spt(S2,S,q,l);
            //cout << "run "<<S2<<"\n";
            vrf(S2);
        }
    }
    printf("%d",A);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
