#include<bits/stdc++.h>
using namespace std;
double a,b,c,x1,x2;
int T,M;
int main()
{
    freopen("uqe.in","w",stdin);
    freopen("uqe.out","r",stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++){
        cin>>a>>b>>c;
        if((b*b-4*a*c)>0){
            x1=(-b+sqrt(b*b-4*a*c))/(2*a);
            x2=(-b+sqrt(b*b-4*a*c))/(2*a);
            if(x1>x2) cout<<x1<<endl;
            else cout<<x2<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
