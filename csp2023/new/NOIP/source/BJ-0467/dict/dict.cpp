#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m;
int a[N][N];
string s;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++)
            a[i][j]=s[j-1]-'a'+1;
        sort(a[i]+1,a[i]+m+1);
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(a[j][m]<=a[i][1]){flag=0;break;}
        }
        printf("%d",flag);
    }puts("");
    return 0;
}
