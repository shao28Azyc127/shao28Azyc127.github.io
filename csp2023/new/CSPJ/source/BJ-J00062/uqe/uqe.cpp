#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<0){
            a=-a;
            b=-b;
            c=-c;
        }
        int dt=b*b-4*a*c;
        //cout<<dt<<endl;
        if(dt<0){
            cout<<"NO"<<endl;
            continue;
        }
        int sqt=sqrt(dt);
        if(sqt*sqt==dt){
            int z=-b+sqt;
            //cout<<b<<endl;
            if(z<0){
                cout<<"-";
            }
            int h=gcd(abs(z),2*a);
            z=abs(z)/h;
            int f=2*a/h;
            if(f!=1){
                cout<<z;
                cout<<"/";
                cout<<f;
                cout<<endl;
            }
            else{
                cout<<z<<endl;
            }
        }
        else{
            int k=sqt;
            while(dt%(k*k)!=0)k--;
            int rm=dt/(k*k);
            if(b>0)cout<<"-";
            int h1=gcd(abs(b),2*a);
            int z1=abs(b)/h1;
            int f1=2*a/h1;
            if(z1!=0){
                cout<<z1;
                if(f1!=1){
                    cout<<"/";
                    cout<<f1;
                }
                cout<<"+";
            }
            int h2=gcd(k,2*a);
            int z2=k/h2;
            int f2=2*a/h2;
            if(z2!=1){
                cout<<z2;
                cout<<"*";
            }
            cout<<"sqrt("<<rm<<")";
            if(f2!=1){
                cout<<"/";
                cout<<f2;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
