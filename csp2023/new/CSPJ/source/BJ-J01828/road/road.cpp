#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,v[100005],a[100005];
int val=0,total=0;
int minn=LLONG_MAX,x=0;
int up_money(int id){
    int i,sum=v[id];
    for(i=id+1;i<n;i++){
        if(a[i-1]<=a[i]){
            sum+=v[i];
        }else{
            return sum;
        }
    }
    return sum;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int i;
    for(i=1;i<n;i++){
        cin>>v[i];
        x+=v[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn){
            minn=a[i];
        }
    }
    if(a[1]==minn){
        if(x%d==0){
            cout<<x/d*minn;
        }else{
            cout<<(x/d+1)*minn;
        }
        return 0;
    }
    for(i=1;i<n;i++){
        if(val>=v[i]){
            val-=v[i];
            continue;
        }
        int t=up_money(i);
        if(t%d==0){
            t=t/d;
        }else{
            if(t%d>val){
                t=t/d+1;
            }else{
                t=t/d;
            }
        }
        //cout<<i<<endl;
        //cout<<t<<" ";
        total+=t*a[i];
        val+=t*d;
        val-=v[i];
        //cout<<total<<" "<<val<<endl;
    }
    cout<<total;
    return 0;
}
