#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e5;
int n,x,vis[N],sum,pd[N],a[15],wz,ans,res=0,cyd;
bool check(int x){
    int flag=0,y;

    for(int i=1;i<=n;++i){
        pd[a[i]]=0;
    }
    for(int i=1;i<=9;++i){
        wz=1;
        for(int j=0;j<=4;++j){
            y=x+wz*i;
            y=x/(wz*10)*(wz)*10+y%(wz*10);
            if(vis[y]&&pd[y]==0){
                //cout<<x+wz*i<<" "<<y<<endl;
                ++flag;

                pd[y]=1;
                ++res;
            }
            wz*=10;
        }
    }
    for(int i=1;i<=9;++i){
        y=i*1e4+x;
        y%=M;
        cyd=y;
        y=y+i*1000;
        y=cyd/10000*10000+y%10000;

        if(vis[y]&&pd[y]==0){

            ++flag;
            pd[y]=1;
        }
    }

    for(int i=1;i<=9;++i){
        wz=1;
        for(int j=0;j<=3;++j){
            y+=1000000;
            y=x-i*wz*1;
            y=x/(wz*10)*(wz*10)+y%(wz*10);
            cyd=y;
            y=y-i*wz*10;
            y=y%(wz*100)+cyd/(wz*100)*(wz*100);
            //y+=1000000;

            y+=1000000;
            y%=100000;
            //cout<<y<<endl;

            if(vis[y]&&pd[y]==0){
                ++flag;
                pd[y]=1;
                //++res;
            }
            wz*=10;
        }

    }

    for(int i=1;i<=9;++i){
            y=i*1e3+x;
        y=x/10000*10000+y%10000;
        cyd=y;
        y=y+i*100;
        y=cyd/1000*1000+y%1000;

        if(vis[y]&&pd[y]==0){
            ++flag;

            pd[y]=1;

        }
    }
    for(int i=1;i<=9;++i){
             y=i*100+x;
        y=x/1000*1000+y%1000;
        cyd=y;
        y=y+i*10;
        y=cyd/100*100+y%100;

        if(vis[y]&&pd[y]==0){

            ++flag;
            pd[y]=1;
        }
    }
    for(int i=1;i<=9;++i){
            y=i*10+x;
        y=x/100*100+y%100;
        cyd=y;
        y=y+i*1;
        y=cyd/10*10+y%10;

        if(vis[y]&&pd[y]==0){

            ++flag;
            pd[y]=1;
        }
    }

    return flag==n;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        sum=0;
        for(int j=1;j<=5;++j){
            scanf("%d",&x);
            sum*=10;
            sum+=x;
        }
        a[i]=sum;
        vis[sum]=1;
    }
    for(int i=0;i<=99999;++i){
        if(check(i)){
            //cout<<i<<endl;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
