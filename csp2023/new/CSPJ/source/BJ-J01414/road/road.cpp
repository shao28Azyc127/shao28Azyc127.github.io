#include<bits/stdc++.h>
using namespace std;

int n,d,v[100086],a[100086];
int ans;
int vall;


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        vall+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mina=a[1];
    for(int i=2;i<=n;i++){
        mina=min(mina,a[i]);
    }
    //1st jiaman
    if(mina==a[1]){
        ans=vall/d;
        if(vall%d!=0)    ans++;
    //cout<<"@"<<ans<<" ";
        ans=ans*a[1];
    }
    cout<<ans;
    return 0;
}
