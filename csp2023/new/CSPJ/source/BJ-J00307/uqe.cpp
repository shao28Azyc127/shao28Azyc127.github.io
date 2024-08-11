#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
freopen("que.in","r",stdin);
freopen("que.out","w",stdout);
int n,m,a[1010],b[1010],c[1010];
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i]>>c[i];


    if((b[i]*b[i])<4*a[i]*c[i]){cout<<"NO"<<endl;}
    else if((b[i]*b[i])==4*a[i]*c[i]){cout<<-1*b[i]/2/a[i]<<endl;}
    else{
        m=sqrt((b[i]*b[i])-(4*a[i]*c[i]));
       cout<<(m-1*b[i])/2/a[i]<<endl;}}

return 0;}
