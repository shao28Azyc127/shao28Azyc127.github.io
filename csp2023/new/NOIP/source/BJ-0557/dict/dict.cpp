#include <bits/stdc++.h>

using namespace std;
int n,m;
char a[3001];
int Hash[3001][26];
int cnt[3001][26];
int Min[26];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[j];
            Hash[i][a[j]-'a']++;
        }
        cnt[i][0]=Hash[i][0];
        for(int j=1;j<26;j++){
            cnt[i][j]=cnt[i][j-1]+Hash[i][j];
        }
    }
    for(int i=0;i<=25;i++){
        Min[i]=1e9+7;
        for(int j=1;j<=n;j++){
            Min[i]=min(Min[i],cnt[j][25]-cnt[j][i]+Hash[j][i]);
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=0;j<=25;j++){
            while(cnt[i][j]==0) j++;
            if(cnt[i][j]<=Min[j]){
                flag=true;
                break;
            }
        }
        if(flag) cout<<1;
        else cout<<0;
    }
    return 0;
}
