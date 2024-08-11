#include<bits/stdc++.h>
using namespace std;

int n,m;

char str[3005][3005];

int check[3005],minn[3005],maxx[3005];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>str[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int d=-1,x=50;
        for(int j=1;j<=m;j++){
            int k=str[i][j]-'a'+1;
            d=max(k,d);
            x=min(k,x);
        }
        minn[i]=x;
        maxx[i]=d;
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        int cnt;
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(minn[i]>=maxx[j]) flag=0;
        }
        cout<<flag;
    }
    return 0;
}
