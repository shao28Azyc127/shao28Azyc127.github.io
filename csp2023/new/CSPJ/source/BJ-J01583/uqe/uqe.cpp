#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t = 9,m,a[10],b[10],c[10];
    int q1,q,q2,q3,p1;
    int p,p2,r;
    int u,d,f;
    cin>>t>>m>>a[10]>>b[10]>>c[10];
        if(q == 1)
            cout<<q;
        else
            cout<<p/q;
        if(q2 > 0&&r > 1&&r%(d*d) != 0){
            if(q1 != 0)
                cout<<sqrt(r)<<'+';
            else
                return 0;
            if(q2 == 1)
                cout<<sqrt(r);
            else if(q2 != 0.0)
                cout<<q2*sqrt(r);
            else if(q3 == q2/1)
                cout<<sqrt(r)/q3;
            else
                cout<<f*sqrt(r)/d;
        }
    return 0;
}
