#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N][N],ans,d[N];
bool check(){

    for(int i=1;i<=n;i++){
        int cnt=0,f1=0,f2=0,g1=0;
        for(int j=1;j<=5;j++)
            if(d[j]!=a[i][j]){
                cnt++;
                if(cnt>2)return 0;
                if(cnt==1){
                    f1=d[j]-a[i][j];
                    if(f1<0)f1=10+f1;
                    g1=j;
                }else{
                    if(j!=g1+1)return 0;
                    f2=d[j]-a[i][j];
                    if(f2<0)f2=10+f2;
                    if(f1!=f2)return 0;
                }
            }
        if(cnt==0)return 0;
    }
    return 1;

}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                for(int u=0;u<=9;u++)
                    for(int v=0;v<=9;v++){
                        d[1]=i,d[2]=j,d[3]=k,d[4]=u,d[5]=v;
                        if(check())ans++;
                    }
    cout<<ans;
    return 0;
}
