#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long
ll n,a,b,c,r,mid,eve,outr,lu,ld,ru,rd,m,fu,fd;
pair<ll,ll> get_ans;
ll gcd(ll a,ll b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    while(b){
        mid=b;
        b=a%b;
        a=mid;
    }
    return a;
}
pair<ll,ll> get_can_be(ll inp){
    ll ans=1;
    for(ll i=2;i*i<=inp;i++){
        while(inp%i==0){
            inp/=i;
            if(inp%i==0){
                inp/=i;
                ans*=i;
            }
            else{
                inp*=i;
                break;
            }
        }
    }
    //cout<<inp<<' '<<ans<<endl;
    return pair<ll,ll>(inp,ans);
}
void con(){
    r=b*b-4*a*c;
    if(r<0){
        cout<<"NO"<<endl;
        return;
    }
    get_ans=get_can_be(r);
    r=get_ans.first;
    outr=get_ans.second;
    ru=outr;
    lu=-b;
    ld=2*a;
    rd=2*a;
    mid=gcd(lu,ld);
    lu/=mid;
    ld/=mid;
    if(ld<0){
        ld=-ld;
        lu=-lu;
    }
    mid=gcd(ru,rd);
    ru/=mid;
    rd/=mid;
    //cout<<ru<<' '<<rd<<' '<<mid<<endl;
    if(rd<0){
        ru=-ru;
        rd=-rd;
    }
    if(r==1){
        fd=ld*rd;
        fu=lu*rd+ru*ld;
        mid=gcd(fu,fd);
        fu/=mid;
        fd/=mid;
        cout<<fu;
        if(fd!=1) cout<<'/'<<fd;
        cout<<endl;
        return;
    }
    if(lu!=0){
        cout<<lu;
        if(ld!=1){
            cout<<'/'<<ld;
        }
        if(ru!=0&&r!=0){
            if(ru>0)
                cout<<'+';
            else{
                cout<<'+';
                ru=-ru;
            }
        }
    }
    if(ru==0||r==0){
        cout<<endl;
        return;
    }
    if(ru!=1&&ru!=-1){
        cout<<ru;
        if(r!=1) cout<<'*';
    }
    if(r!=1){
        cout<<"sqrt("<<r<<")";
    }
    if(ru==1&&r==1){
        cout<<1;
    }
    if(rd!=1){
        cout<<'/'<<rd;
    }
    cout<<endl;
}
int main()//-3 -18 54
{
  //  freopen("/home/cspj/Downloads/CSP-J/uqe/uqe2.in","r",stdin);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(size_t i=0;i<n;i++){
        cin>>a>>b>>c;
        con();
    }
    return 0;
}