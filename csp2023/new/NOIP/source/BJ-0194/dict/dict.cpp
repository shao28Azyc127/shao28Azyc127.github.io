#include<bits/stdc++.h>
using namespace std;
const int N=4010;
int n,m,a[N][N];
string s[N],m1,m2;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];s[i]=' '+s[i];
        for(int j=1;j<=m;j++)a[i][j]=s[i][j]-'a'+1;
        sort(a[i]+1,a[i]+m+1);
        reverse(a[i]+1,a[i]+m+1);
        for(int j=1;j<=m;j++)s[i][j]=a[i][j]+'a'-1;
        if(m1=="")m1=s[i];
        else if(s[i]<m1)m2=m1,m1=s[i];
        else if(m2==""||s[i]<m2)m2=s[i];
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(s[i]==m1){
            for(int j=1;j<=m/2;j++)swap(s[i][j],s[i][m-j+1]);
            if(s[i]<m2)cout<<1;
            else cout<<0;
        }else{
            for(int j=1;j<=m/2;j++)swap(s[i][j],s[i][m-j+1]);
            if(s[i]<m1)cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
