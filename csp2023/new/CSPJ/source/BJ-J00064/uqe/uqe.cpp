#include<bits/stdc++.h>
using namespace std;
int t,m;
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0) cout<<"NO"<<endl;
        else cout<<max((-b+sqrt(delta))/2,(-b-sqrt(delta))/2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}