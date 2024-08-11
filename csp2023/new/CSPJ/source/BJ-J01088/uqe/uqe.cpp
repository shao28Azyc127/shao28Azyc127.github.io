#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long hj(long long &xs,long long k){
    for(long long i=sqrt(k);i>=1;i--){
        if(k%(i*i)==0){
            xs=i;
            return k/(i*i);
        }
    }
}
void cou(long long x,long long y){
    long long gg=__gcd(x,y);
    x/=gg;
    y/=gg;
    if(x>0&&y<0){
        x=-x;
        y=-y;
    }
    if(y==1){
        cout<<x;
        return;
    }
    if(x==0){
        cout<<0;
        return;
    }
    cout<<x<<'/'<<y;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    cin>>T>>m;
    while(T--){
        long long x,y,z;
        cin>>x>>y>>z;
        long long del=y*y-4*x*z;
        if(del<0){
            cout<<"NO\n";
            continue;
        }
        long long sq=sqrt(del);
        if(2*x<0){
            sq=-sq;
        }
        if(sq*sq==del){
                cou(-y+sq,2*x);
                cout<<'\n';
        }
        else{
            long long xx,yy;
            yy=hj(xx,del);
            if(y!=0){
                cou(-y,2*x);
                cout<<'+';
            }
            if(x<0){
                xx=-xx;
            }
            if(xx!=2*x){
                long long g=__gcd(xx,2*x);
                xx/=g;
                x=x*2/g;
                if(xx!=1){
                    cout<<xx<<'*';
                }
                cout<<"sqrt("<<yy<<")";
                if(x!=1){
                    cout<<'/'<<x<<'\n';
                }
                else{
                    cout<<'\n';
                }
            }
            else{
                cout<<"sqrt("<<yy<<")\n";
            }
        }
    }
    return 0;
}
