#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int gcd(int a,int b){
    for(int i=min(a,b);i>=1;i--){
        if((a%i==0)&&(b%i==0)){
            return i;
        }
    }
    return 1;
}

void outputFloat(int d,int e){
    if(d*e<0)cout<<'-';
    cout<<abs(d)/gcd(abs(d),abs(e));
    int f=abs(e)/gcd(abs(d),abs(e));
    if(f!=1&&d!=0)cout<<'/'<<f;
}

int mysqrt(int x){
    int ans=1;
    for(int i=2;i*i<=x;i++){
        while(x/(i*i)*i*i==x){
            x/=i*i;
            ans*=i;
        }
    }
    return ans;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int deta=b*b-4*a*c;
        if(deta<0)cout<<"NO"<<endl;//wujie
        else{
            int k=sqrt((long double)deta);
            if(k*k==deta){//youli
                int d=a>0?-b+k:-b-k;
                int e=2*a;
                outputFloat(d,e);
                cout<<endl;
            }
            else{//wuli
                if(b!=0){
                    outputFloat(-b,2*a);
                    cout<<'+';
                }
                int d=mysqrt(deta);
                int e=abs(2*a);
                int f=gcd(d,e);
                if(d/f!=1)cout<<d/f<<'*';
                cout<<"sqrt("<<deta/(d*d)<<")";
                if(e/f!=1)cout<<'/'<<e/f;
                cout<<endl;
            }
        }
    }

    return 0;
}