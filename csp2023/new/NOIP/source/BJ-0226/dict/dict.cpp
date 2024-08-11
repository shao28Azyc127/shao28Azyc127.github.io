#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,m,a[maxn],cnt[30];
string s[maxn],mn[maxn],mx[maxn];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<m;j++){
            cnt[s[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            for(int k=1;k<=cnt[j];k++){
                mn[i]+='a'+j;
            }
        }
        for(int j=25;j>=0;j--){
            for(int k=1;k<=cnt[j];k++){
                mx[i]+='a'+j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mn[i]>=mx[j]){
                flag=0;
                break;
            }
        }
        a[i]=flag;
        cout<<a[i];
    }
    return 0;
}
