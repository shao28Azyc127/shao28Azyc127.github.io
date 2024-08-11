#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,d,k,s,l,g;
int q,f;
double dd;
int make(int e){
    int aa=1;
    for(int i=2;i*i<=e;i++){
        if(e%(i*i)==0){
            aa=i;
        }
    }
    f=e/aa/aa;
    return aa;
}
void make1(int x,int y){
    int r=abs(__gcd(x,y));
    int xx=x/r;
    int yy=y/r;
    if(abs(yy)==1&&yy*xx>0){
        cout<<abs(xx);
        return ;
    }
    if(abs(yy)==1&&yy*xx<0){
        cout<<'-'<<abs(xx);
        return ;
    }
    if(xx>0){
        if(yy>0){
            cout<<xx<<'/'<<yy;
        }else{
            cout<<'-'<<xx<<'/'<<abs(yy);
        }
    }else{
        if(yy>0){
            cout<<'-'<<abs(xx)<<'/'<<yy;
        }else{
            cout<<abs(xx)<<'/'<<abs(yy);
        }
    }
}
void make2(int x,int y,int z){
    int r=abs(__gcd(x,z));
    int xx=x/r;
    int zz=z/r;
    if(xx==1){
        if(zz==1){
            cout<<"sqrt("<<y<<")"<<endl;
            return ;
        }else{
            cout<<"sqrt("<<y<<")/"<<zz<<endl;
            return ;
        }
    }
    if(zz==1){
        cout<<xx<<"*sqrt("<<y<<")"<<endl;
        return ;
    }
    cout<<xx<<"*sqrt("<<y<<")/"<<zz<<endl;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        dd=sqrt(d);
        if(ceil(dd)==floor(dd)){
            k=(int)dd;
            l=2*a;
            if(a>0){
                s=-1*b+k;
                if(s%l==0){
                    cout<<s/l<<endl;
                    continue;
                }
                g=abs(__gcd(s,l));
                if(s>0){
                    cout<<abs(s/g)<<'/'<<abs(2*a/g)<<endl;
                }else if(s==0){
                    cout<<0<<endl;
                }else{
                    cout<<'-'<<abs(s/g)<<'/'<<abs(2*a/g)<<endl;
                }
            }else{
                s=-1*b-k;
                if(s%l==0){
                    cout<<s/l<<endl;
                    continue;
                }
                g=abs(__gcd(s,l));
                if(s>0){
                    cout<<'-'<<abs(s/g)<<'/'<<abs(2*a/g)<<endl;
                }else if(s==0){
                    cout<<0<<endl;
                }else{
                    cout<<abs(s/g)<<'/'<<abs(2*a/g)<<endl;
                }
            }
        }else{
            q=make(d);
            if(b==0){
                if(a>0){
                    make2(q,f,2*a);
                }else{
                    make2(q,f,-2*a);
                }
                continue;
            }
            make1(-1*b,2*a);
            cout<<'+';
            if(a>0){
                make2(q,f,2*a);
            }else{
                make2(q,f,-2*a);
            }
            continue;
        }
    }
    return 0;
}
