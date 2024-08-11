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
        int ans=b*b-4*a*c;
        if(ans<0){
            cout<<"NO"<<endl;
            continue;
        }
        int x1=(-b)+sqrt(ans),x2=(-b)-sqrt(ans);
        x1=x1/(2*a);
        x2=x2/(2*a);
        cout<<max(x1,x2)<<endl;
    }
    return 0;
}
