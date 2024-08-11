#include <bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        int x=b*b;
        int y=4*a*c;
        int temp=x-y;
        if(temp<0) cout<<"NO"<<endl;
        else cout<<(-b+sqrt(temp))/(2*a)<<endl;
    }
    return 0;
}
