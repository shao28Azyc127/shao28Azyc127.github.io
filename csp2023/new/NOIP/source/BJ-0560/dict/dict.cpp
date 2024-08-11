#include<bits/stdc++.h>
using namespace std;
const int Nm=3007;
int a[Nm][Nm];
int c[Nm];
int n,m;
bool ju(int x){
    for(int j=1;j<=n;j++){
        if(j==x) continue;
        for(int k=1;k<=m;k++){
           if(a[j][m+1-k]>a[x][k]) break;
           if(a[j][m+1-k]<a[x][k]) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n!=1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char b;
                cin>>b;
                c[j]=int(b-'a');
            }
            sort(c+1,c+m+1);
            for(int j=1;j<=m;j++){
                a[i][j]=c[j];
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ju(i);
        }
    }
    else cout<<1;
    return 0;
}
