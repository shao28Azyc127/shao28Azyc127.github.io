#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

string sub(string s,int L,int R) {
    string t;
    forr(i,L,R) t += s[i];
    return t;
}
bool pd(string s) {
    //if(s.size()<2 && (s.size()==2 && s[0]!=s[1]) ) return 0;
    while(s.size()>0) {

        int l=s.size();
        forr(i,0,l-2) {
            if(s[i]==s[i+1]) {
                s=s.substr(0,i)+s.substr(i+2);
                //s=sub(s,0,i-1)+sub(s,i+2,l-1);
            }
        }
        int l2=s.size();
        if(l==l2) return 0;
    }
    return 1;
}

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long l=0,ans=0; string s;
    cin>>l>>s; l=s.size();
    forr(i,1,l) { // wei
        for(int j=0;j+i<=l-1;j++) {
            string t=sub(s,j,j+i);
            if( pd(t)) ++ans;
            cout<<t<<' '<<pd(t)<<endl;

        }
    } cout<<ans;


    return 0;
}

