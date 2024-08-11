#include<bits/stdc++.h>
using namespace std;
int n,d,s[100010],pr[100010],m=0,sheng=0,i=1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;++i){
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=n;i++)scanf("%d",&pr[i]);
    while(i<n){
        int juli=0,zhan;
        for(int j=i;j<n;++j){
            juli+=s[j];
            if(pr[j+1]<pr[i]){
                juli-=sheng;
                zhan=j+1;
                break;
            }
            if(j+1==n){
                juli-=sheng;
                zhan=n;
            }
        }
        if(juli/d==0){
            m=m+pr[i]*juli/d;
        }else{
            m=m+pr[i]*(juli/d+1);
            sheng=d*(juli/d+1)-juli;
        }
        i=zhan;
    }
    printf("%d",m);
    return 0;
}
