#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long c[a],d[a],m=0;
    for(int i=0;i<a-1;i++){
        cin>>c[i];
        m+=c[i];
    }for(int i=0;i<a;i++){
        cin>>d[i];
    }int h=(m/b)*d[0];
    cout<<h;
    return 0;
}
