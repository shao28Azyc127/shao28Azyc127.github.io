#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void prv(double n){
    if((int)n==n) cout<<n;
    else{
        for(int i=2;;i++){
            if(n*i==(int)n*i){
                printf("%d/%d",n*i,i);
            }
        }
    }
}
void pr(int a,int b,int c){
    double x=sqrt(b*b-4*(a*c));
    if(x*x==b*b-4*(a*c)){
        prv((-b+x)*1.0/(2*a));
        cout<<endl;
    }
    else{
        prv(-b);
        printf("*sqrt(%d)",b*b-4*(a*c));
        if(2*a!=1) cout<<'/'<<2*a;
        cout<<endl;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b,c,x1,x2;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        if(b*b-4*(a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }else{
            pr(a,b,c);
        }
    }
    return 0;
}
