#include<iostream>
#include<queue>
using namespace std;
long long v[100005],a[100005];
long long q[100005];
long long cc(long long x,long long y){
    if(x<0){
        return 0;
    }
    if(x%y==0){
        return x/y;
    }
    else{
        return x/y+1;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        q[i]=q[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    long long lastp=1;
    long long re=0;
    for(int i=2;i<=n;i++){
        if(a[lastp]>a[i]){
            ans+=a[lastp]*cc(q[i]-q[lastp]-re,d);
            re=d*cc(q[i]-q[lastp]-re,d)-(q[i]-q[lastp]-re);
            lastp=i;
        }
    }
    ans+=cc(q[n]-q[lastp]-re,d)*a[lastp];
    cout<<ans;
    return 0;
}
/*
5 6
10 10 10 10
9 8 7 6 5

*/
