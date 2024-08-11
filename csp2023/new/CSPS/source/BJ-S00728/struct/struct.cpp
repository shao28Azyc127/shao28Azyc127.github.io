#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op,ys,maxx=-1e9,dx;
    string s,a;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>op;
        if(op==1) {
            cin>>s;
            cin>>ys;
            for(int j=1;j<=ys;j++) {
                cin>>s>>a;
                if(s=="long") {
                    dx=8;
                }
                else if(s=="int") {
                    dx=4;
                }
                else if(s=="short") {
                    dx=2;
                }
                else {
                    dx=1;
                }
                maxx=max(maxx,dx);
            }
            cout<<maxx*ys<<" "<<maxx<<endl;
        }
    }
    return 0;
}
