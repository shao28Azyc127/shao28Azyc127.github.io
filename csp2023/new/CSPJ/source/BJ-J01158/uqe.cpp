#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
int d,e;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int v=b*b-4*a*c;
        if(v<0){
            cout<<"NO"<<endl;
        }else{
            int x1,x2,x;
            x1=(-b+sqrt(v))*1.0/2*a;
            x2=(-b-sqrt(v))*1.0/2*a;
            x=max(x1,x2);
            if(x%1==0||x%-1==0) cout<<x<<endl;
            for(int i=2;i<=2*a;i++){
                int p=x*i;
                if((p%1==0||p%-1==0)&&gcd(p,i)==1){
                    d=p;
                    e=i;
                    cout<<p<<"/"<<i<<endl;
                }
            }
        }
    }
    return 0;
}
