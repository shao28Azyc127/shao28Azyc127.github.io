#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[3005];
char c[3005][3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cin>>b[i];
   //     b[i]=a[i];
    }
   // cout<<b[1].lengh();
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            c[i][j]=a[i][j];
        }
        sort(c[i],c[i]+m);
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        string hh;
        for(int j=0;j<m;j++)hh+=c[i][j];
        //cout<<hh<<endl;
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            if(a[j]<=hh)flag=0;
        }
        cout<<flag;
    }
}
