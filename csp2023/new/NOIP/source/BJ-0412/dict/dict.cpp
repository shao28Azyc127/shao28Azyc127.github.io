#include <bits/stdc++.h>
using namespace std;
char c[3010];
int n,m,x[3010][3010],f[3010],y[3010][3010],l[3010];
bool flag;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[j];
            f[j]=y[i][j]=c[j];

        }
        sort(f+1,f+1+m);
        for(int j=1;j<=m;j++)
            x[i][j]=f[j];
    }
    for(int i=1;i<=n;i++){
        flag=0;
        for(int j=1;j<=n;j++){
            if(j==i)
                continue;
            int k=1;
            while(x[i][k]==y[j][k])
                k++;
            if(x[i][k]>y[j][k]){
                cout<<0;
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<1;
    }
}
