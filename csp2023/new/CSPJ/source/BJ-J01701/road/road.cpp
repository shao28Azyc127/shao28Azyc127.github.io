#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,v[N],p[N],s[N],hx[N],oil,mini,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    mini=INT_MAX;
    for(int i=1;i<n;i++){
        cin>>v[i];
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
        int tmp=0;
        if(oil*d<s[i]){
            tmp=s[i]/d;
            if(s[i]%d!=0)tmp++;
            tmp-=oil;
            ans+=tmp*mini;
            oil+=tmp;
        }
        if(mini>p[i])mini=p[i];
    }
    cout<<ans;
    return 0;
}
