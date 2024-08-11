#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;cin>>t>>m;
    while(t--){
        double a,b,c;cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO\n";
            continue;
        }
        if(sqrt(b*b-4*a*c)==(int)sqrt(b*b-4*a*c)){
            int p=(a>0?sqrt(b*b-4*a*c)-b:-b-sqrt(b*b-4*a*c)),q=2*a;
            if(int(p)%int(q)==0) cout<<(p)/(q)<<'\n';
            else{
                if(p>0&&q>0||p<0&&q>0)cout<<p/__gcd(abs(p),q)<<'/'<<q/__gcd(abs(p),q)<<'\n';
                else cout<<-p/abs(__gcd(p,q))<<'/'<<-q/abs(__gcd(p,q))<<'\n';
            }
        }else{
            if(b){
                int p=-b,q=2*a;
                if(p%q==0) cout<<p/q;
                else{
                    if(p>0&&q>0||p<0&&q>0)cout<<p/__gcd(abs(p),q)<<'/'<<q/__gcd(abs(p),q);
                    else cout<<-p/abs(__gcd(p,q))<<'/'<<-q/abs(__gcd(p,q));
                }
            }
            int d=b*b-4*a*c,f=1;
            for(int i=sqrt(d);i>=2;i--){
                if(d%(i*i)==0){
                    f=i,d/=i*i;
                    break;
                }
            }
            if(b){
                if(f==1){
                    if(a>0)cout<<"+sqrt("<<d<<")/"<<2*a<<'\n';
                    else cout<<"+sqrt("<<d<<")/"<<-2*a<<'\n';
                }
                else{
                    int p=(a>0?f:-f),q=2*a;
                    if(p==q) cout<<"+sqrt("<<d<<")\n";
                    else if(p==-q) cout<<"-sqrt("<<d<<")\n";
                    else if(p%q==0){
                        if(p>0&&q>0||p<0&&q<0) cout<<'+'<<p/q<<"*sqrt("<<d<<")\n";
                        else cout<<'-'<<p/q<<"*sqrt("<<d<<")\n";
                    }
                    else{
                        if(p>0&&q>0){
                            if(p/__gcd(abs(p),q)!=1) cout<<'+'<<p/__gcd(abs(p),q)<<'*'<<"sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                            else cout<<"+sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                        }
                        else if(p<0&&q>0){
                            if(p/__gcd(abs(p),q)!=-1) cout<<'-'<<p/__gcd(abs(p),q)<<'*'<<"sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                            else cout<<"-sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                        }
                        else if(p<0){
                            if(-p/abs(__gcd(p,q))!=1)cout<<'+'<<-p/abs(__gcd(p,q))<<'*'<<"sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                            else cout<<"+sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                        }else{
                            if(-p/abs(__gcd(p,q))!=-1)cout<<'-'<<-p/abs(__gcd(p,q))<<'*'<<"sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                            else cout<<"-sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                        }
                    }
                }
            }
            else{
                if(f==1){
                    if(a>0)cout<<"sqrt("<<d<<")/"<<2*a<<'\n';
                    else cout<<"sqrt("<<d<<")/"<<-2*a<<'\n';
                }
                else{
                    int p=(a>0?f:-f),q=2*a;
                    if(p==q) cout<<"sqrt("<<d<<")\n";
                    else if(p==-q) cout<<"-sqrt("<<d<<")\n";
                    else if(p%q==0){
                        if(p>0&&q>0||p<0&&q<0) cout<<p/q<<"*sqrt("<<d<<")\n";
                        else cout<<'-'<<p/q<<"*sqrt("<<d<<")\n";
                    }
                    else{
                        if(p>0&&q>0){
                            if(p/__gcd(abs(p),q)!=1) cout<<p/__gcd(abs(p),q)<<'*'<<"sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                            else cout<<"sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                        }
                        else if(p<0&&q>0){
                            if(p/__gcd(abs(p),q)!=-1) cout<<'-'<<p/__gcd(abs(p),q)<<'*'<<"sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                            else cout<<"-sqrt("<<d<<")/"<<q/__gcd(abs(p),q)<<'\n';
                        }
                        else if(p<0){
                            if(-p/abs(__gcd(p,q))!=1)cout<<-p/abs(__gcd(p,q))<<'*'<<"sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                            else cout<<"sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                        }else{
                            if(-p/abs(__gcd(p,q))!=-1)cout<<'-'<<-p/abs(__gcd(p,q))<<'*'<<"sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                            else cout<<"-sqrt("<<d<<")/"-q/abs(__gcd(p,q))<<'\n';
                        }
                    }
                }
            }
        }
    }
    return 0;
}
