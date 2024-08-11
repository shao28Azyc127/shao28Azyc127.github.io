#include <bits/stdc++.h>
using namespace std;
int m;
void out(double x)
{
    if(x==floor(x)){
        cout<<int(x)<<endl;
        return;
    }
    for(int i = 1;i*x<=m&&i<m;i++){
        if(i*x==floor(i*x)){
            cout<<i*x<<"/"<<i<<endl;
            return ;
        }
        if((-i)*x==floor((-i)*x))
        {
            cout<<(-i)*x<<'/'<<i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=(b*b)-(4*a*c);
    if(x<0){
        cout<<"NO"<<endl;
        return;
    }
    double ans1,ans2;
    ans1=1.0*((-b)+sqrt(x))/(2*a);
    ans2=1.0*((-b)-sqrt(x))/(2*a);
    out(max(ans1,ans2));
    return;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin>>t>>m;
    for(int i = 1;i<=t;i++)
        solve();
    return 0;
}
