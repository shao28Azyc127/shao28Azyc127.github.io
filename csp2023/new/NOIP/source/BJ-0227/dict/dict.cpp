#include<bits/stdc++.h>
using namespace std;
int n,m,f[3004],a[3001][3004],b[3001][3004];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            f[j]=c-'a';
        }
        sort(f+1,f+1+m);
        for(int j=1;j<=m;j++){
            a[i][j]=f[j];
            b[i][j]=f[m+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        int ans=1;
        for(int ii=1;ii<=n;ii++){
            if(ii==i)continue;
            int inda=0;
            for(int j=1;j<=m;j++){
                if(a[i][j]<b[ii][j])break;
                if(a[i][j]>b[ii][j]){
                    inda=1;
                    break;
                }
            }
            if(inda){
                ans=0;
                break;
            }
        }
        cout<<ans;
    }
    return 0;
}
