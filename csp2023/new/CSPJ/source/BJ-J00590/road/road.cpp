#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,v[100001],a[100001];
int marks[100001],cnt=0,len[100001];
bool flag[100001];
int need(int len){
    return max((len-1)/d+1,(int)(0));
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int mina=2147483647,res=0,nowst=0,canv=0,sumv=0,totv=0;
    for(int i=1;i<n;i++){
            if(mina>a[i]){
            mina=a[i];
            marks[++cnt]=i;
            flag[i]=1;
            len[cnt-1]=sumv;
            sumv=0;
        }
        sumv+=v[i];
    }
    len[cnt]=sumv;
    /*for(int i=1;i<=cnt;i++){
        cout<<len[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<marks[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=cnt;i++){
        nowst=canv-totv;
        //cout<<nowst<<" ";
        res+=need(len[i]-nowst)*a[marks[i]];
        //cout<<res<<" ";
        //cout<<marks[i]<<" "<<need(len[i]-nowst)<<endl;
        totv+=len[i];
        canv+=need(len[i]-nowst)*d;
    }
    cout<<res;
    return 0;
}