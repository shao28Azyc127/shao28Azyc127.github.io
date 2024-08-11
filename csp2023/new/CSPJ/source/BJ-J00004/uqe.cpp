#include<iostream>
#include<cmath>
using namespace std;
int n,m,a,b,c;
int mx(int a,int b){
    if(a>b)return a;
    return b;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    while(n--){
        cin>>a>>b>>c;
        int k=b*b-(4*a*c);
        if(k<0)cout<<"NO"<<endl;
        else{
            int k1=(-b+sqrt(k))/(2*a);
            int k2=(-b-sqrt(k))/(2*a);
            cout<<mx(k1,k2)<<endl;
        }
    }
    return 0;
}
