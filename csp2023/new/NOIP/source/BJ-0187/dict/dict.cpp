#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

string s[MAXN],t[MAXN];
bool flag[MAXN];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,cnt=0; cin>>n>>m;
    string minn1="",minn2="";
    for(int i=1;i<=m+1;i++) minn1+='z',minn2+='z';
    for(int i=1;i<=n;i++){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
        t[i]=s[i];
        reverse(s[i].begin(),s[i].end());
        if(s[i]<minn1){
            minn2=minn1;
            minn1=s[i];
        }else if(s[i]<minn2){
            minn2=s[i];
        }
    }
    if(n==1) return cout<<1,0;
    for(int i=1;i<=n;i++){
        if(t[i]==s[i] && s[i]==minn1) cout<<(t[i]<minn2);
        else cout<<(t[i]<minn1);
    }
    cout<<'\n';
    return 0;
}
