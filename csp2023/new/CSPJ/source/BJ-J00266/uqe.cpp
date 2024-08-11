#include <bits/stdc++.h>
using namespace std;
int t,m;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        double d=b*b-4*a*c;//derta
        if (d<0){
            cout<<"NO"<<endl;
            continue;
        }
        double p=sqrt(d)-b,q=2*a,v=p/q;
        int vv=v;
        if (vv-v>0||v-vv>0){//nono
            if (q==1){
                cout<<p<<endl;
                continue;
            }
        }
        else cout<<v<<endl;
    }
    return 0;
}
