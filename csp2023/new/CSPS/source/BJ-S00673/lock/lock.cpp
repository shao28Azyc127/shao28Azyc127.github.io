#include<bits/stdc++.h>
using namespace std;
long long n,a[10][10],may[90][10],i=1,is[90],ans;
void dfs(long long x){
    for(int b=0;b<=9;b++){
        if(b==a[1][x])continue;
        for(int c=1;c<=5;c++){
            may[i][c]=a[1][c];
        }
        may[i][x]=b;
        i++;
    }
    if(x==5)return;
    for(int b=1;b<=9;b++){
        for(int c=1;c<=5;c++){
            may[i][c]=a[1][c];
        }
        may[i][x]=(a[1][x]+b)%10;
        may[i][x+1]=(a[1][x+1]+b)%10;
        i++;
    }
    dfs(x+1);
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int b=1;b<=n;b++){
        for(int c=1;c<=5;c++){
            cin>>a[b][c];
        }
    }
    dfs(1);
    for(int b=2;b<=n;b++){
        for(int c=1;c<i;c++){
            if(is[c]==1)continue;
            long long num=0,f;
            for(int d=1;d<=5;d++){
                if(a[b][d]!=may[c][d]){
                    f=d;
                    num++;
                }
            }
            if(num>2 || num==2 && a[b][f-1]-may[c][f-1]!=a[b][f]-may[c][f] || num==0){
                is[c]=1;
            }
        }
    }
    for(int b=1;b<i;b++){
        if(is[b]==1)continue;
        ans++;
    }
    cout<<ans;
    return 0;
}
