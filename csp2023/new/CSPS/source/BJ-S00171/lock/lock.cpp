#include<iostream>
#include<cstdio>
using namespace std;
int vis[1123456];
int a[10],c[10],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
        {
            int b;
            cin>>b;
            a[i]*=10;
            a[i]+=b;
        }
    for(int i=1;i<=n;i++)   vis[a[i]]-=10;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            if(a[i]%10+j<10)    vis[a[i]+j]++;
            else    vis[a[i]+j-10]++;
        }
        for(int j=1;j<=9;j++){
            if((a[i]%100)/10+j<10)    vis[a[i]+j*10]++;
            else    vis[a[i]+j*10-100]++;
        }
        for(int j=1;j<=9;j++){
            if((a[i]%1000)/100+j<10)    vis[a[i]+j*100]++;
            else    vis[a[i]+j*100-1000]++;
        }
        for(int j=1;j<=9;j++){
            if((a[i]%10000)/1000+j<10)    vis[a[i]+j*1000]++;
            else    vis[a[i]+j*1000-10000]++;
        }
        for(int j=1;j<=9;j++){
            if(a[i]/10000+j<10)    vis[a[i]+j*10000]++;
            else    vis[a[i]+j*10000-100000]++;
        }
    }
//    cout<<1<<endl;
    for(int i=1;i<=n;i++){
        int now=a[i],x=5;
        while(now){
            c[x]=now%10;
            now/=10;
            x--;
        }
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                c[j]++;
                c[j+1]++;
                c[j]%=10;
                c[j+1]%=10;
                int cnt=0;
                for(int l=1;l<=5;l++)
                    cnt*=10,cnt+=c[l];
                vis[cnt]++;
            }
            c[j]++;
            c[j+1]++;
            c[j]%=10;
            c[j+1]%=10;
        }
    }
    for(int i=0;i<=99999;i++)
        if(vis[i]==n)   {ans++;}
    cout<<ans<<endl;
//    cout<<vis[28311]<<endl;
    return 0;
}
