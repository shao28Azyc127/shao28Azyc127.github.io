#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005];
int a[100005];
long long ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mv=a[1];
    for(int i=1;i<n;i++){
        mv=min(mv,a[i]);
        if(v[i]%d==0){
            ans+=(v[i]/d)*mv;
        }
        else{
            ans+=(v[i]/d+1)*mv;
            v[i+1]-=((v[i]/d+1)*d-v[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
