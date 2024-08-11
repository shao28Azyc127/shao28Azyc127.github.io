#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
int n,d;
int v[N],a[N];
long long sumv[N];
long long dpmon[N],dpdis[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        sumv[i]=sumv[i-1]+v[i];
    }
    int minn=1e5+5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    if(minn==a[1]&&n>=1e5){
        if(sumv[n]%d==0)cout<<sumv[n]/d*a[1];
        else cout<<sumv[n]/d*a[1]+a[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        dpmon[i]=1e18;
    }
    dpmon[0]=dpmon[1]=0;
    for(int i=2;i<=n;i++){
        long long ans=0;
        for(int j=1;j<i;j++){
            long long tmp=(sumv[i]-sumv[j])-dpdis[j];
            long long buycnt=0;
            if(tmp%d==0)buycnt=tmp/d;
            else buycnt=tmp/d+1;
            if((dpmon[j]+buycnt*a[j])<dpmon[i]){
                dpmon[i]=dpmon[j]+buycnt*a[j];
                ans=buycnt*d-tmp;
            }
        }
        dpdis[i]=ans;
    }
    cout<<dpmon[n];
    return 0;
}