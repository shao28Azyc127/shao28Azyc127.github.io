#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(a%b!=0){
        a=a%b;
        swap(a,b);
    }return b;
}


void yls(double n){
    int a=1;
    while(n!=(int)(n)){
        n*=10;
        a*=10;
    }int g=gcd(a,n);
    if(a/g<0){
        a=-a;
        n=-n;}
    cout<<n/g;
    if(a/g-1)
    cout<<'/'<<a/g;
    return ;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int s=(b*b)-(4*a*c);
        if(s<0){
            cout<<"NO\n";
        }else{
            double ax=((-b)-sqrt(s))/(2*a),bx=(sqrt(s)-b)/(2*a);
            double mx=max(ax,bx);
            if(mx==(int)(mx)){
                cout<<(int)(mx)<<'\n';
            }else if(sqrt(s)==(int)(sqrt(s))){
                yls(mx);
                cout<<'\n';
            }else{
                if(b!=0){
                yls(1.0*(-b)/(2*a));
                cout<<'+';
                }
                long long p=1,j=1,mx=1;
                while(p<s){
                    p=j*j;
                    if(s%p==0){
                        mx=j;
                    }j++;
                }
                int gs=abs(gcd(mx,a*2));
                if(mx/gs<0&&a*2/gs<0){
                    mx=-mx;
                    a=-a;
                }
                if(mx!=1&&mx/gs!=1){
                    cout<<mx/gs<<'*';
                }
                cout<<"sqrt("<<s/mx/mx<<")";
                if(abs(a*2/gs)!=1)
                cout<<'/'<<a*2/gs;
                cout<<'\n';
            }
        }
    }return 0;
}
