#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m,dis[N],price[N],k,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i < n;i++) scanf("%d",&dis[i]);
    for(int i = 1;i <= n;i++) scanf("%d",&price[i]);
    for(int i = 1;i < n;){
        int j = i+1,sum=dis[i]-k;
        while(j<n&&price[j]>price[i]){
            sum+=dis[j];
            j++;
        }
        if(sum%m==0){
            ans+=(sum/m)*price[i];
            k=0;
        }else{
            ans+=(sum/m+1)*price[i];
            k=(sum/m+1)*m-sum;
        }
        i=j;
    }
    cout<<ans;
}
