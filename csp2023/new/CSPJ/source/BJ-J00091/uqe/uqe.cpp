#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin>>t>>a;
    while(t--){
        cin>>a>>b>>c;
        int s=b*b-4*a*c,k=(int)sqrt(s);
        if(s<0){
            cout<<"NO"<<endl;
            continue;
        }
        int p,q;
        if(k*k==s){
            p=(-b+k)/2/a;
            q=(-b-k)/2/a;
            if(q==1||-q==1){
                cout<<p<<endl;
                continue;
            }
            if(p==1||-p==1){
                cout<<q<<endl;
                continue;
            }
            cout<<p<<"/"<<q;
        }
    }
    return 0;
}