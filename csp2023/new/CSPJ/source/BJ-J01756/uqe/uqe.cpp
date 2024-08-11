#include<bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c;
int der,sder;
int gz,yz;
int cs;
int csg,csy;
int hder;
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        csg=2*a;
        csy=2*a;
        yz=-b;
        der=b*b-4*a*c;
        if(der<0){
            cout<<"NO"<<endl;
            continue;
        }
        gz=0;
        sder=sqrt(der);
        if(sder*sder!=der){
            gz=1;
            for(int i=2;i<=sder;i++){
                if(der%(i*i)==0){
                    gz=i;
                }
            }
            hder=der/gz/gz;
        }
        if(yz!=0)
            if(yz%csy==0){
                yz/=csy;
                csy=1;
            }
            else{
                int gys=gcd(abs(yz),abs(csy));
                yz/=gys;
                csy/=gys;
            }
        if(csy<0){
            csy=abs(csy);
            yz*=-1;
        }
        if(gz!=0)
            if(gz%csg==0){
                gz/=csg;
                csg=1;
            }
            else{
                int gys=gcd(abs(gz),abs(csg));
                gz/=gys;
                csg/=gys;
            }
        if(sder*sder==der){
            if(sder!=0){
                if(sder%csg==0){
                    gz=sder/csg;
                    csg=1;
                }
                else{
                    int gys=gcd(abs(sder),abs(csg));
                    gz=sder/gys;
                    csg/=gys;
                }
            }
        }
        if(gz<0){
            gz=abs(gz);
        }
        if(csy==csg&&sder*sder==der){
            yz+=gz;
            if(yz!=0)
                if(yz%csy==0){
                    yz/=csy;
                    csy=1;
                }
                else{
                    int gys=gcd(abs(yz),abs(csy));
                    yz/=gys;
                    csy/=gys;
                }
            gz=0;
        }
        else if(csy==1&&sder*sder==der){
            csy=csg;
            yz=yz*csg+gz;
            gz=0;
        }
        else if(csg==1&&sder*sder==der){
            csy=csg;
            yz=yz+gz*csg;
            gz=0;
        }
        if(yz!=0)
            if(yz%csy==0){
                yz/=csy;
                csy=1;
            }
            else{
                int gys=gcd(abs(yz),abs(csy));
                yz/=gys;
                csy/=gys;
            }
        if(yz!=0){
            cout<<yz;
            if(csy!=1){
                cout<<"/"<<csy;
            }
        }
        if(yz!=0&&gz!=0){
            cout<<"+";
        }
        csg=abs(csg);
        if(gz!=0){
            if(abs(gz)!=1||(abs(gz)==1&&sder*sder==der))cout<<abs(gz);
            if(sder*sder!=der&&abs(gz)!=1){
                cout<<"*sqrt("<<hder<<")";
            }
            else if(sder*sder!=der){
                cout<<"sqrt("<<hder<<")";
            }
            if(csg!=1){
                cout<<"/"<<csg;
            }
        }
        if(yz==0&&gz==0){
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
