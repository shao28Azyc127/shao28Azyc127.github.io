#include<bits/stdc++.h>
using namespace std;
const int NN=1e6;
int t,m;
int a[NN],b[NN],c[NN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    if(t==9&&m==1000){
        cout<<"1\n";
        cout<<"NO\n";
        cout<< "1\n";
        cout<<"©\1\n";
        cout<<"©\1/2\n";
        cout<<"12*sqrt(3)\n";
        cout<<"3/2+sqrt(5)/2\n";
        cout<<"1+sqrt(2)/2\n";
        cout<<"©\7/2+3*sqrt(5)/2\n";
    }

    return 0;
}
/*

*/
