#include<bits/stdc++.h>
using namespace std;
int n,d,a[1000100],b[103049],ans,cnt;
int main(){
cin>>n>>d;
for(int i=1;i<=n-1;i++){
cin>>a[i];
ans+=a[i];
}
for(int i=1;i<=n;i++)cin>>b[i];
if(ans%d==0)cnt=ans/d;
else cnt=(ans/d)+1;
cout<<cnt*b[1];
return 0;
}
