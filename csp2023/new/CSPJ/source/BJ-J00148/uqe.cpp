#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
    while(a and b){
        int c=a%b;
        a=b,b=c;
    }
    return a;
}
struct flt{
    long long s,m;
    void upd(){
        if(!s){
            m=1;
            return;
        }
        if(!m){
            m=1,s=-99999999;
            return;
        }
        long long g=gcd(s,m);
        s/=g,m/=g;
        if(m<0){
            m/=-1;
            s*=-1;
        }
    }
    flt operator+(const flt p){
        flt ret;
        ret.m=m*p.m;
        ret.s=s*p.m+p.s*m;
        ret.upd();
        return ret;
    }
    flt operator-(const flt p){
        flt ret;
        ret.m=m*p.m;
        ret.s=s*p.m-p.s*m;
        ret.upd();
        return ret;
    }
    flt operator*(const flt p){
        flt ret;
        ret.m=m*p.m;
        ret.s=s*p.s;
        ret.upd();
        return ret;
    }
    flt operator/(const flt p){
        flt ret;
        ret.m=m*p.s;
        ret.s=s*p.m;
        ret.upd();
        return ret;
    }
};
flt mkflt(int s,int m){
    flt ret;
    ret.s=s,ret.m=m;
    return ret;
}
pair<int,int> sq(int s){
    pair<int,int> ret;
    ret.first=1,ret.second=1;
    for(int i = 2;i <= sqrt(s);i++){
        while(s%(i*i)==0){
            s/=(i*i);
            ret.first*=i;
        }
    }
    ret.second=s;
    return ret;
}
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t >> m;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(b*b<4*a*c) cout << "NO\n";
        else{
            int delta=b*b-4*a*c;
            flt fst;
            fst.s=-1*b;
            fst.m=2*a;
            fst.upd();
            
            flt scd;
            pair<int,int> p=sq(b*b-4*a*c);
            scd.s=p.first;
            scd.m=2*a;
            scd.upd();
            scd.s=abs(scd.s);
            if(p.second==1 or p.second==0){
                scd.s*=p.second;
                fst=fst+scd;
                fst.upd();
                cout << fst.s;
                if(fst.m==1) {cout << endl;}
                else {cout << '/' << fst.m << endl;}
            }else{
                if(fst.s!=0){
                    cout << fst.s;
                    if(fst.m!=1) cout << '/' << fst.m;
                    cout << '+';
                }
                if(1){
                    if(scd.s!=1) cout << scd.s << '*';
                    cout << "sqrt(" << p.second << ")";
                    if(scd.m==1){cout << endl;}
                    else{cout << '/' << scd.m << endl;}
                }
            }
        } 
    }
    return 0;
}