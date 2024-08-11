#include<bits/stdc++.h>
using namespace std;
int n,d,dp[100000050];
int t1[1000000];
int t2[1000000];
double t,tt;
int tempid,tempdata=2100000000;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;i++){
        cin>>t1[i];
    }
    for(int i=1;i<=d;i++){
        cin>>t2[i];
        if(t2[i]<tempdata){
            tempdata=t2[i];
            tempid=i;
        }
    }
    int f=0;
    for(int i=1;i<=n;i++){
        t=0;
        if(f==1){
            f=0;
            continue;
        }
        else if(i==tempid){
            for(int j=i;j<=n;j++){
                t+=t1[j];
            }
            t/=d;
            t*=tempdata;
            tt+=t;
            break;
        }
        else if(t2[i]<t2[i+1]){
            t=t+t1[i]+t1[i+1];
            t/=d;
            t*=t2[i];
            f=1;
        }
        else{
            t+=t1[i];
            t/=d;
            t*=t2[i];
        }
        tt+=t;
    }
    printf("%.0lf",tt);
    return 0;
}
