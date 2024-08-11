#include<bits/stdc++.h>
using namespace std;
#define int long long
int ct[3010][30];
int mx[3010],mn[3010];
int n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mx[i]=0;
        mn[i]='z'+1;
        for(char x:s)
            ct[i][x-'a']++,mx[i]=max(mx[i],(int)x-'a'),mn[i]=min(mn[i],(int)x-'a');
    }
    for(int i=1;i<=n;i++){
        bool p=1;
        //cout<<mn[i]<<" "<<mx[i]<<" "<<ct[i]['n'-'a']<<endl;
        for(int j=1;j<=n;j++)
            if(j!=i){
                if(mx[j]<=mn[i])p=0;
            }
        cout<<p;
    }
    cout.flush();
    return 0;
}
