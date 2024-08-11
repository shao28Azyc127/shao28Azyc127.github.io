#include<cstdio>
#include<iostream>
using namespace std;
int n,d,dis[100000],fee[100000],add,sum,t,remain;

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);

scanf("%d %d",&n,&d);
for(int i=1;i<n;i++){
    scanf("%d",&dis[i]);

}
for(int i=1;i<=n;i++){
    scanf("%d",&fee[i]);

}

t=dis[1];
i=1;
for(int j=1;j<n;j++){


    while(fee[j]<fee[i+1]){
        i++;
        t=t+dis[i];
    }
    if((t-remain)%d==0){
        sum=sum+(t-remian)/d*fee[j];
        remain=0;
    }else{
        re=(t-remain)/d+1;
        sum=sum+re*fee[j];
        remain=re*d-t;
    }
    i++;
    t=0;
     j=i;
}

printf("%d",sum);



return 0;


}
