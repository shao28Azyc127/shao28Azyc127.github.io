#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
set<ll>iq;
ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}
string change_s(ll a){
    string val="";
    while(a){
        val+=((a%10)+'0');
        a/=10;
    }
    reverse(val.begin(),val.end());
    return val;
}
string youli(ll a,ll b){
    if(a==0){
        return "0";
    }
    char sign=0;
    if(!(a<0&&b<0)&&(a<0||b<0)){
        sign='-';
    }
    a=abs(a);
    b=abs(b);
    if(a%b==0){
        if(sign=='-'){
            return sign+change_s(a/b);
        }else{
            return change_s(a/b);
        }
    }
    ll g=gcd(a,b);
    if(sign=='-'){
        return '-'+change_s(a/g)+'/'+change_s(b/g);
    }
    return change_s(a/g)+'/'+change_s(b/g);
}
ll change_sqrt[10000000];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(int i=1;i<10000000;++i){
        change_sqrt[i]=1e18;
    }
    for(int i=0;i<=3000;++i){
        change_sqrt[i*i]=i;
    }
    ll t,m;
    scanf("%lld%lld",&t,&m);
    while(t--){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll del=b*b-4*a*c;
        if(del<0){
            printf("NO\n");
            continue;
        }else{
            ll bottom=2*a;
            if(change_sqrt[del]!=1e18){
                ll x1=-b+change_sqrt[del],x2=-b-change_sqrt[del];
                ll x;
                if(bottom>=0){
                    x=x1;
                }else{
                    x=x2;
                }
                cout<<youli(x,bottom)<<endl;
                continue;
            }else{
                string s="";
                if(b!=0){
                    s+=youli(-b,2*a)+"+";
                }
                ll val=1;
                for(int i=2;i*i<=del;++i){
                    while(del%(i*i)==0){
                        val*=i;
                        del/=(i*i);
                    }
                }
                bottom=abs(bottom);
                ll g=gcd(val,abs(bottom));
                val/=g;
                bottom/=g;
                if(val!=1){
                    s+=change_s(val)+"*";
                }
                s+="sqrt("+change_s(del)+")";
                if(bottom!=1){
                    s+="/"+change_s(bottom);
                }
                if(s.size()==0){
                    s="0";
                }
                cout<<s<<endl;
            }
        }
    }
    return 0;
}


