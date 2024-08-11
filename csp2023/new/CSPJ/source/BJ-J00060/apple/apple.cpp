#include<bits/stdc++.h>
using namespace std;
long long n,ne=0,ny=0;
long long f=0;
long long a[1000010]={0};
int flag=0;
long long e=1;
long long ans=0;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ny=n;
    while(ny>0)
    {
        ny=ny-(ny-1)/3-1;
        ne++;
    }
    cout<<ne<<' ';
    for(long long i=1;i<=n;i++){
        a[i]=i;
    }
    for(long long j=1;j<=ne;j++){
        for(long long i=1;i<=n;i++){
            if(a[i]==-1){
                e++;
                continue;
            }
            if((i-e)%3==0){
                if(a[i]==n){
                    ans=j;
                    flag=1;
                    break;
                }
                a[i]=-1;
            }
        }
        e=1;
        if(flag==1){
            cout<<ans;
            break;
        }
    }
    return 0;
}
