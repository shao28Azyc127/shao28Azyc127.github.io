#include<bits/stdc++.h>
using namespace std;
int n,d,a[100050],v[100005];
int cost,cnt,ful;
int lon(int i,int j){
    int s=0;
    for(int k=i;k<j;k++){
        s+=v[k];
    }
    return s;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    int j=1;
    for(int i=2;i<=n-1;i++){
        if(a[i]<a[j]){
            int s=lon(j,i);
            int f=s/d;
            if(f*d+ful<s)f++;
            ful+=f*d-s;
            cnt+=f*a[j];
            j=i;
        }
    }
    if(1){
        int s=lon(j,n);
        cnt+=s/d*a[j];
        if(cnt*d+ful<s)cnt+=a[j];
    }
    cout<<cnt;
    return 0;
}