#include<bits/stdc++.h>
using namespace std;
int c[100005],d[100005];
long long af[100005];
int main(){
    int a,b,ans=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a-1;i++){
        scanf("%d",&c[i]);
        af[i+1]=af[i]+c[i];
    }
    for(int i=1;i<=a;i++){
        scanf("%d",&d[i]);
    }
    int now=1,le=0;
    for(int i=1;i<a-1;i++){
        if(d[i]>d[i+1]){
            int fk=ceil(double((af[i+1]-af[now])-le)/b);
            if(ceil(double((af[i+1]-af[now])-le)/b)!=ceil(double((af[i+1]-af[now]))/b)){
                int s=ceil(double((af[i+1]-af[now])-le)/b)-ceil(double((af[i+1]-af[now]))/b);
                le=le-s*b;
            }

            ans=ans+d[now]*fk;
            le=le+fk*b-(af[i+1]-af[now]);
            now=i+1;
        }
    }
    int f=ceil(double(af[a]-af[now]-le)/b)*d[now];
    printf("%d",f+ans);
}
