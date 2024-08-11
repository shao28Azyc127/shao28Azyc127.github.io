//lock.cpp
#include <bits/stdc++.h>

using namespace std;
bool vis[100005];
bool tmpvis[100005];
int n,a[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=1;j<=5;j++){
            int k=0;
            scanf("%d",&k);
            x=x*10+k;
        }
        a[i]=x;
    }
    memset(vis,true,sizeof(vis));
    for(int i=1;i<=n;i++){
        memset(tmpvis,false,sizeof(tmpvis));
        int tmps[6],k=a[i];
        for(int j=5;j>=1;j--){
            tmps[j]=k%10;
            k/=10;
        }
        for(int m=1;m<=5;m++){
            for(int o=0;o<=9;o++){
                if(tmps[m]!=o){
                    int prev=tmps[m];
                    tmps[m]=o;
                    int x=0;
                    for(int i=1;i<=5;i++){
                        x=x*10+tmps[i];
                    }
                    tmpvis[x]=true;
                    tmps[m]=prev;
                }
            }
        }

        for(int m=1;m<=4;m++){
            for(int o=1;o<=9;o++){
                int prev1=tmps[m],prev2=tmps[m+1];
                tmps[m]=(tmps[m]+o)%10;
                tmps[m+1]=(tmps[m+1]+o)%10;
                int x=0;
                for(int i=1;i<=5;i++){
                    x=x*10+tmps[i];
                }
                tmpvis[x]=true;
                tmps[m]=prev1;
                tmps[m+1]=prev2;
            }
        }
        for(int i=0;i<=100000;i++){
            vis[i]=vis[i]&tmpvis[i];
        }
    }
    long long cnt=0;
    for(int i=0;i<=100000;i++){
        if(vis[i])cnt++;
    }
    printf("%lld\n",cnt);
    return 0;
}
