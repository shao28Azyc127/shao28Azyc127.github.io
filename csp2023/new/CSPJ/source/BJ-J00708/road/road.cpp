#include<bits/stdc++.h>
using namespace std;
int a[10000],l[10001],you,next1,money,now=1,x,zou;
int main(){
    int n,d;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>x;
        a[i]=a[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    while(now!=n){
            next1=n;
        for(int j=now+1;j<n;j++){
            if(l[j]<l[now]){
                next1=j;
                break;
            }
        }
        int juli=a[next1]-a[now]-zou;
        if(juli%d==0){
            money+=juli/d*l[now];
            you=juli/d;
            zou+=you*d;
        }else{
        money+=((juli/d)+1)*l[now];
        you=(juli/d)+1;
        zou+=you*d;
        }
        now=next1;
        zou-=juli;
    }
        cout<<money;
    return 0;
}

