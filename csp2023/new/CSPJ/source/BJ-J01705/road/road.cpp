#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,s[1000005],price[1000005],ans,cnt2=0,cnt3=0;
    double cnt1=0,S,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>s[i];
        S+=s[i];
    }
    for(int i=1;i<=n;i++) cin>>price[i];
    cnt1=S/d*1.0;
    cnt3=S/d;
    cnt2=cnt3+1;
    if(cnt2!=cnt1+1){
		ans=cnt2*price[1];
    }else ans=cnt1*price[1];
    cout<<ans<<endl;
    return 0;
}
