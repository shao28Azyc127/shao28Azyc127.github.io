#include<bits/stdc++.h>
using namespace std;
long long b[100005],a[100005],s[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,cost=0,rem=0,pos=0,minx=2e9,ttt,k;
    bool flg=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>b[i];
        if(i>1)
            s[i]=s[i-1]+b[i-1];
    }
    s[n]=s[n-1]+b[n-1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                flg=1;
                long long dis=s[j]-pos;
                long long cur=dis/d;
                if(dis%d!=0) cur++;
                long long tmp=cur*d;
                pos=pos+tmp;
                cost+=cur*a[i];
                i=j;
                break;
            }
        }
        if(!flg){
            long long l,minn=2e9;
            for(int j=i+1;j<=n;j++){
                if(a[j]<=minn){
                    l=j,minn=a[j];
                }
            }
            long long dis=s[l]-pos;
            long long cur=dis/d;
            if(dis%d!=0) cur++;
            long long tmp=cur*d;
            pos=pos+tmp;
            cost+=cur*a[i];
            i=l;
        }
        flg=0;
    }
    cout<<cost;
    return 0;
}