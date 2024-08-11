#include <bits/stdc++.h>
using namespace std;
int a,b,sum=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>b;
    int x[a-1],m;
    for(int i=0;i<a-1;i++){
        cin>>x[i];
        sum+=x[i];
    }
    cin>>m;
    int ans=sum*m;
    cout<<ans;


    return 0;
}
