#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,d,v[N],a[N],s[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=1;i<n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long you=0,sum=0,mn=2e9;
    for(long long i=1;i<n;i++){
        mn=min(mn,a[i]);
        if(you*d<s[i]){
            long long cha=s[i]-you*d;
            if(cha%d==0){
                you+=cha/d;
                sum+=cha/d*mn;
            }else{
                long long buy=cha/d+1;
                you+=buy;
                sum+=buy*mn;
            }
        }
    }
    cout<<sum;
    return 0;
}
