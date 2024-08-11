#include<bits/stdc++.h>
using namespace std;
const int MXN=3e3+10,MXM=3e3+10;
int n,m;
int cnt[MXN][30];
char s[MXN][MXM];
bool cmp1(const char l,const char r){
    return l<r;
}
bool cmp2(const char l,const char r){
    return l>r;
}
bool cmp3(const int l,const int r){
    for(int i=0,j=25;i<26;i++){
        if(!cnt[l][i]) continue;
        while(!cnt[r][j]) j--;
        if(i==j&&cnt[l][i]==cnt[r][j]) j--;
        else if(i<j) return 1;
        else if(i>j) return 0;
        else if(cnt[i]<cnt[j]) return 0;
        else if(cnt[i]>cnt[j]) return 1;
    }
    return 0;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            cnt[i][s[i][j]-'a']++;
        }
    }
    for(int i=1,f;i<=n;i++){
        f=1;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(!cmp3(i,j)){
                f=0;
                break;
            }
        }
        cout<<f;
    }
    cout<<'\n';
    return 0;
}
