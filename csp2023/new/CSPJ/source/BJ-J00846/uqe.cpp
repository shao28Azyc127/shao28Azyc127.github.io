#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int x=b*b-(4*a*c);
        if(x<0){
            cout<<"NO";
        }
        else{
            double k=sqrt(x);
            if(k*k==x){
                int xx=(0-b+k);
                int yy=(0-b-k);
                if(xx>yy){
                    int g=__gcd(xx,2*a);
                    if(2*a/g==1)cout<<xx/g<<"\n";
                    else cout<<xx/g<<"/"<<2*a/g<<"\n";
                }
                else {
                    int g=__gcd(yy,2*a);
                    if(2*a/g==1)cout<<yy/g<<"\n";
                    else cout<<yy/g<<"/"<<2*a/g<<"\n";
                }
            }
            else{
                int g=__gcd(b,2*a);
                int bb=b/g;
                int aa=2*a/g;
                if(aa<0){
                    aa=abs(aa);
                }
                else if(bb<0){
                    bb=abs(bb);
                }
                else bb=0-bb;
                if(bb==0){
                    if(x%(2*a)==0){
                        x/=2*a;
                        int jj=0;
                        for(int i=2;i*i*i*i<=x;i++){
                            if(x%(i*i)==0){
                                x/=i*i;
                                jj=i;
                            }
                        }
                        if(jj==0)cout<<"sqrt("<<x<<")\n";
                        else cout<<jj<<"*sqrt("<<x<<")\n";
                    }
                    else{
                        int jj=0;
                        for(int i=2;i*i*i*i<=x;i++){
                            if(x%(i*i)==0){
                                x/=i*i;
                                jj=i;
                            }
                        }
                        jj/=(__gcd(jj,2*a));
                        if(jj==0||jj==1)cout<<"sqrt("<<x<<")/"<<2*a<<"\n";
                        else cout<<jj<<"*sqrt("<<x<<")/"<<2*a/(__gcd(jj,2*a))<<"\n";
                    }
                }
                else{
                    if(x%(2*a)==0){
                        x/=2*a;
                        int jj=0;
                        for(int i=2;i*i*i*i<=x;i++){
                            if(x%(i*i)==0){
                                x/=i*i;
                                jj=i;
                            }
                        }
                        if(jj>0){
                            if(aa==1)cout<<bb<<"+"<<jj<<"*sqrt("<<x<<")\n";
                            else cout<<bb<<"/"<<aa<<"+"<<jj<<"*sqrt("<<x<<")\n";
                        }
                        else if(jj<0){
                            if(aa==1)cout<<bb<<"-"<<jj<<"*sqrt("<<x<<")\n";
                            else cout<<bb<<"/"<<aa<<"-"<<jj<<"*sqrt("<<x<<")\n";
                        }
                        else{
                            if(aa==1)cout<<bb<<"+"<<"sqrt("<<x<<")\n";
                            else cout<<bb<<"/"<<aa<<"+"<<"sqrt("<<x<<")\n";
                        }
                    }
                    else{
                        int jj=0;
                        for(int i=2;i*i*i*i<=x;i++){
                            if(x%(i*i)==0){
                                x/=i*i;
                                jj=i;
                            }
                        }
                        jj/=(__gcd(jj,2*a));
                        if(aa==1){
                            if(jj==0||jj==1)cout<<bb<<"+"<<"sqrt("<<x<<")/"<<2*a<<"\n";
                            else cout<<bb<<"+"<<jj<<"*sqrt("<<x<<")/"<<2*a/(__gcd(jj,2*a))<<"\n";
                        }
                        else{
                            if(jj==0||jj==1)cout<<bb<<"/"<<aa<<"+"<<"sqrt("<<x<<")/"<<2*a<<"\n";
                            else cout<<bb<<"/"<<aa<<"+"<<jj<<"*sqrt("<<x<<")/"<<2*a/(__gcd(jj,2*a))<<"\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}
