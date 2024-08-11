#include <bits/stdc++.h>
#define int long long
#define db long double
using namespace std;
inline int read(){
    char c=getchar();
    int r=0;
    bool fl=0;
    if(c=='-') fl=1,c=getchar();
    while('0'<=c&&c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return fl==1?-r:r;
}
bool isp(int n){
    if(n==1||n==0) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int t,m,a,b,c;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    t=read();
    m=read();
    while(t--){
        a=read(),b=read(),c=read();
        int dlt=(b*b)-(4*a*c);
        if(dlt<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(dlt>=0){
            int sq=sqrt(dlt);
            if(sq*sq==dlt){
                int fz=(a>0?max((sq-b),(-sq-b)):min((sq-b),(-sq-b))),fm=2*a;
                int g=__gcd(fz,fm);
                fz/=g;
                fm/=g;
                if(fm==1){
                    cout<<fz<<endl;
                }else{
                    if(fz>0&&fm<0) fz*=-1,fm*=-1;
                    cout<<fz<<"/"<<fm<<endl;
                }
            }else{
                int d=dlt;
                int r=1;
                map<int,int> ys;
                for(int i=sqrt(dlt);i>=2;i--){
                    while(d%i==0&&isp(i)){
                        d/=i;
                        // cout<<d<<endl;
                        ys[i]++;
                    }
                }
                // cout<<dlt<<" ";
                for(int i=sqrt(dlt);i>=2;i--){
                    // cout<<ys[i]<<' ';
                    while(ys[i]>=2){
                        ys[i]-=2;
                        dlt/=(i*i);
                        r*=i;
                    }
                }
                // cout<<b<<' '<<2*a<< ' ' <<r<<endl;
                // cout<<endl;
                int fm=2*a;
                int g=__gcd(__gcd(b,r),fm);
                fm/=g;

                b/=g;
                r/=g;
                int fm1=fm;
                int g1,g2;
                g1=__gcd(fm,b);
                g2=__gcd(fm1,r);
                b/=g1;
                fm/=g1;
                fm1/=g2;
                r/=g2;
                
                if(b%fm==0) b/=fm,fm=1;
                if(r%fm1==0) r/=fm1,fm1=1;
                if(fm1<0&&r<0) fm1*=-1,r*=-1;
                if(b>0&&fm<0) b*=-1,fm*=-1;
                cout<<(b==0?"":to_string(-b))<<(fm==1?"":"/"+to_string(fm))<<(b==0?"":"+")<<((r==1||r==-1)?"":(to_string(r<0?-r:r)+"*"))<<"sqrt("<<dlt<<")"<<(fm1==1||fm1==-1?"":"/"+to_string(fm1<0?-fm1:fm1))<<endl;
            }
            continue;
        }
        // if(dlt>0){
        //     continue;
        // }
    }
    return 0;
}
/*5 4 
10 10 10 10 
9 8 9 6 5*/
