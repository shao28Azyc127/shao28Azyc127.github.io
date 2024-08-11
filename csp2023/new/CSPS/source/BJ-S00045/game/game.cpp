#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s;
bool check(string cspj) {
    if(cspj=="") return true;
    string csps;
    int len=cspj.length(),j=0;
    while(j<len) {
        if(cspj[j]!=cspj[j+1]) csps+=cspj[j++];
        else j+=2;
    }
    if(csps.length()==len) return false;
    return check(csps);
}
signed main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            string t="";
            for(int k=i;k<=j;k++) t+=s[k];
            if(check(t)) ans++;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
