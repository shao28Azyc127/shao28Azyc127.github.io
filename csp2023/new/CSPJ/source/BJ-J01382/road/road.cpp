#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
long long n,m,ans=0,t=1,g=0,k=0,d=0;
cin>>n>>m;
for(long long i=1;i<n;i++){
    cin>>a[i];
}
for(long long i=1;i<=n;i++){
    cin>>b[i];
}
while(t<n){
long long s=b[t];
long long sum=t;
for(long long i=t+1;i<=n;i++){
    if(b[i]<s){
        sum=i;
        break;
    }
}
if(sum==1){
    for(int i=1;i<n;i++){
        k=k+a[i];
    }
    for(long long i=0;i<k;i=i+m){
    d++;
        }
        cout<<d*b[1];
    return 0;
}

int q=0;
for(long long j=t;j<=sum-1;j++){
    q=q+a[j];
}
int d=0;
for(long long i=0+g;i<q;i=i+m){
    d++;
}
g=g+d*m-q;
ans=ans+d*b[t];
t=sum;
}
cout<<ans;
return 0;
}

