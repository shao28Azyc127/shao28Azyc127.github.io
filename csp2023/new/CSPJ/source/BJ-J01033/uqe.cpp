#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    int x=a,y=b,ans=1;
    for(int i=2;i<max(a,b);i++){
        while(x%i==0 && y%i==0){
            ans*=i;
            x/=i;
            y/=i;
        }
    }
    return ans;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    short t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        short a,b,c;
        cin>>a>>b>>c;
        int s=b*b-4*a*c;
        if(s<0){
            cout<<"NO"<<'\n';
        }
        else{
            int q=sqrt(s);
            if(q*q==s){
                int g=-b+max(q,-q);
                if(a<0){
                    a*=-1;
                    g=b-min(q,-q);
                }
                int jl=gcd(g,a);
                g/=jl;
                a/=jl;

                if(g%(2*a)==0) cout<<g/2/a<<'\n';
                else if(g%a==0) cout<<g/a<<"/2"<<'\n';
                else if(g%2==0) cout<<g/2<<"/"<<a<<'\n';
                else cout<<g<<"/"<<a*2<<'\n';
            }
            else{
                int g=-b;
                int aa=a;
                if(g!=0){
                    int jl=gcd(g,a);
                    g/=jl;
                    a/=jl;
                    if(a<0){
                        a*=-1;
                        g*=-1;
                    }
                    if(g%(2*a)==0) cout<<g/2/a<<"+";
                    else if(g%a==0) cout<<g/a<<"/2"<<"+";
                    else if(g%2==0) cout<<g/2<<"/"<<a<<"+";
                    else cout<<g<<"/"<<a*2<<"+";
                }
                a=aa*2;

                int fl=1;
                if(a<0){
                    a*=-1;
                }
                for(int i=2;i<s;i++){
                    while(s%(i*i)==0){
                        if(a%i==0) a/=i;
                        else fl*=i;
                        s/=(i*i);
                    }
                }
                int ga=gcd(fl,a);
                fl/=ga;
                a/=ga;
                if(fl!=0 && fl!=1) cout<<fl<<"*";
                if(a!=1) cout<<"sqrt("<<s<<")/"<<a<<'\n';
                else cout<<"sqrt("<<s<<")"<<'\n';
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

