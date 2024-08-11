#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e4+10;
int n,d,v[N],p[N],fp=0x7f7f7f7f,sum,ans,pl;

int hei(int d){
    int re=0;
    for (int i=d+1;i<=n;i++){
        re+=v[i];
        if (p[i]<p[d]){
            pl=i-d;
            return re;
        }
    }
    pl=n-d;
    return re;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=2,x;i<=n;i++) {//i-1~i need how much oil
        cin>>x;
        v[i]=x/d;
        sum+=x;
    }
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        fp=min(fp,p[i]);
    }
    if (fp==p[1]){//special A
        int s=sum/d;
        if (sum%d!=0) s++;
        //cout<<s*p[1];
        return 0;
    }
    for (int i=1;i<n;i++){
        int d=hei(i);//jv li
        //cout<<d<<" "<<pl<<" "<<i<<endl;
        ans+=p[i]*d;
        i=i+pl-1;
    }
    cout<<ans;
    return 0;
}
