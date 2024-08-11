#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,d,s=0;
cin>>n>>d;
int v[n],a[n+1];
for(int i=1;i<=n-1;i++){
    cin>>v[i];
    s+=v[i];
}
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cout<<int(s/a[1]/d+0.999999);
fclose(stdin);
fclose(stdout);
return 0;
}

