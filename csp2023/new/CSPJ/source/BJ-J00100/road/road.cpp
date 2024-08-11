#include<bits/stdc++.h>
using namespace std;
int n,d,s[100010],a[100010],minn=0x7fffffff,cnts,cnt,ans,c;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //a[n]=0x7fffffff;
    for(int i=n-1;i>=1;i--){
        if(a[i]!=a[n]){
            c=a[i];
            break;
        }
    }
    for(int i=1;i<=n;){
        minn=min(minn,a[i]);
        //if(minn==0x7fffffff) minn=a[i-1];
        for(int j=i;minn<=a[j+1];j++) cnt++;
        for(int j=i;j<=cnt+i;j++) cnts+=s[j];
        i+=cnt+1;
        if(cnts%d==0) ans+=(cnts/d*minn);
        else{
            ans+=((cnts/d+1)*minn);
            s[cnt+i+1]-=((cnts/d+1)*d-cnts);
        }
        cnt=0;
        cnts=0;
    }
    cout<<ans-c;
    return 0;
}
