#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,buk[26];
string s[N];
string t[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++)buk[s[i][j]-'a']++;
        s[i].clear();
        for(int j=0;j<26;j++){
            while(buk[j]){
                s[i].push_back('a'+j);
                buk[j]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=0;j--)t[i].push_back(s[i][j]);
    }
    sort(t+1,t+1+n);string g;
    for(int j=m-1;j>=0;j--)g.push_back(t[1][j]);
    //for(int i=1;i<=n;i++)cout<<t[i]<<endl;
    for(int i=1;i<=n;i++){
        int res=0;
        if(s[i]!=g){
            res=(s[i]<t[1]);
        }else if(n>1)res=(s[i]<t[2]);
        else res=1;
        cout<<res;
    }
    cout<<endl;
    return 0;
}