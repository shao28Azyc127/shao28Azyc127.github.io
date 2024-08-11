#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int tr=(b*b)-(4*a*c);
        if(tr<0){
            cout<<"NO"<<endl;
        }
        else if(tr==0){
            cout<<(b*-1)/(2*a)<<endl;
        }
        else{
            int x=(b*-1+sqrt(tr))/(2*a);
            int y=(b*-1-sqrt(tr))/(2*a);
            cout<<max(x,y)<<endl;
        }
    }
    return 0;
}
