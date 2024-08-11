#include<bits/stdc++.h>
using namespace std;
const int MAXN=3010;
int n,m;
char s[MAXN*2][MAXN];
int a[MAXN*2];
bool cmp(int i,int j){
    for(int k=1;k<=m;k++)
        if(s[i][k]!=s[j][k])return s[i][k]<s[j][k];
    return i>j;
}
bool v[MAXN],b[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i]+1;
        sort(s[i]+1,s[i]+m+1);
        for(int j=1;j<=m;j++)s[i+n][j]=s[i][m-j+1];
        a[i]=i,a[i+n]=i+n;
    }
    sort(a+1,a+2*n+1,cmp);
    int f=0;
    for(int i=1;i<=2*n;i++){
        if(a[i]<=n&&(f==0||(f==1&&b[a[i]])))v[a[i]]=1;
        else if(a[i]>n)f++,b[a[i]-n]=1;
    }
    for(int i=1;i<=n;i++)cout<<v[i];
    return 0;
}
