#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=3005;
char c;
int cnt[N][26];
int a[N][N];
int mx[N],mn[N];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            cnt[i][c-'a']++;
        }
        mn[i]=1e9;
        for(int j=0;j<26;j++){
            if(cnt[i][j]>0){
                mx[i]=max(mx[i],j);
                mn[i]=min(mn[i],j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(mn[i]>=mx[j]){
                flag=0;
                break;
            }
            else if(mn[i]==mx[j]){
                if(cnt[i][mn[i]]<=cnt[j][mx[j]]){
                    flag=0;
                    break;
                } 
            }
        }
        cout<<flag;
    }
    cout<<endl;
    return 0;
}