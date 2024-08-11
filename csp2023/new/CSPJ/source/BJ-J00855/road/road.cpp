#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,d,s=0,a,b;
cin>>n>>d;
for(int i=1;i<=n-1;i++){
    cin>>a;
    s+=a;
}
for(int i=1;i<=n;i++){
    cin>>b;
    if(i==1){
        cout<<s/d*b;
    }
}
fclose(stdin);
fclose(stdout);
return 0;
}
