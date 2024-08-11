#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int sjx=b*b-4*a*c;
        if(sjx<0){
            cout<<"NO\n";
            continue;
        }
        double x1=(-double(b)+double(sqrt(sjx)))/2*double(a);
        double x2=(-double(b)-double(sqrt(sjx)))/2*double(a);
        double x;
        if(x1>=x2){
            x=x1;
        }else{
            x=x2;
        }
        if(double(x-double(int(x)))==0){
            cout<<x<<endl;
            continue;
        }
    }
    return 0;
}
