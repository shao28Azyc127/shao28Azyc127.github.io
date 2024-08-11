#include<bits/stdc++.h>
using namespace std;
long long n,d,ans=0;
long long v[100010];
long long a[100010];
long long m=0;
long long tmp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=0;i<n-1;i++) cin>>v[i];
    for(long long i=0;i<n;i++) cin>>a[i];
    //for(long long i=0;i<n;i++) cout<<v[i]<<' ';
    for(long long i=0;i<n;i++){
        if(tmp>=v[i]){
            tmp-=v[i];
            //cout<<"c"<<endl;
            continue;
        }
        int cnt=0;
        for(long long j=i+1;j<n;j++){
            cnt+=v[j];
            if(a[i]>a[j]) break;
        }
        //cout<<i<<' '<<cnt<<' ';
        if(cnt==0){
            v[i]-=tmp;
            if(v[i]%d==0){
                ans+=v[i]/d*a[i];
                tmp=0;
            }
            else {
                ans+=(v[i]/d+1)*a[i];
                tmp=(v[i]/d+1)*d-v[i];
            }
            //cout<<tmp<<' '<<v[i]<<' '<<ans<<endl;

            continue;
        }
        if(cnt%d==0) m=cnt/d;
        else m=cnt/d+1;
        ans+=m*a[i];
        tmp+=m*d-v[i];
        //cout<<tmp<<' '<<ans<<endl;
    }
    cout<<ans;
    return 0;
}

