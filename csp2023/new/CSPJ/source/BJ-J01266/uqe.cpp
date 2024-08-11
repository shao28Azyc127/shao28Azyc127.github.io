#include<bits/stdc++.h>
using namespace std;
int a,b,c,delta,t,m;
string ans;
string itc(int n){
    string ret;
    int jian=0;
    if(n<0)ret+="(-",n=-n,jian=1;
    else ret+='+';
    while(n!=0){
        ret=char(n%10+'0')+ret;
        n/=10;
    }
    if(jian)ret+=")";
    return ret;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t>>m;
    while(t--){
        ans="";
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO\n";
            continue;
        }
        if(b==0&&c==0){
                cout<<0<<'\n';
                continue;
        }
        if(b!=0){
            if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)==0)                                     ans+=itc((-b+sqrt(delta))/(2*a));
            else if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)!=0&&sqrt(delta)==int(sqrt(delta))) ans+=itc((-b)/(2*a))+itc(sqrt(delta)/__gcd(int(sqrt(delta)),2*a))+"/"+itc((2*a)/__gcd(int(sqrt(delta)),2*a));
            else if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)!=0&&sqrt(delta)!=int(sqrt(delta))) ans+=itc((-b)/(2*a))+"+sqrt("+itc(delta)+")/"+itc(2*a);
            else if((-b)%(2*a)!=0&&int(sqrt(delta))%(2*a)==0)                                ans+=itc((-b)/__gcd(-b,2*a))+"/"+itc((2*a)/__gcd(-b,2*a))+itc(sqrt(delta)/(2*a));
            else if((-b)%(2*a)!=0&&int(sqrt(delta))%(2*a)!=0&&sqrt(delta)==int(sqrt(delta))) ans+=itc((-b)/__gcd(-b,2*a))+"/"+itc((2*a)/__gcd(-b,2*a))+itc(sqrt(delta)/__gcd(int(sqrt(delta)),2*a))+"/"+itc((2*a)/__gcd(int(sqrt(delta)),2*a));
            else                                                                             ans+=itc((-b)/__gcd(-b,2*a))+"/"+itc((2*a)/__gcd(-b,2*a))+"+sqrt("+itc(delta)+")/"+itc(2*a);
        }else{
            if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)==0)                                     ans+=itc(sqrt(delta)/(2*a));
            else if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)!=0&&sqrt(delta)==int(sqrt(delta))) ans+=itc(sqrt(delta)/__gcd(int(sqrt(delta)),2*a))+"/"+itc((2*a)/__gcd(int(sqrt(delta)),2*a));
            else if((-b)%(2*a)==0&&int(sqrt(delta))%(2*a)!=0&&sqrt(delta)!=int(sqrt(delta))) ans+="sqrt("+itc(delta)+")/"+itc(2*a);
        }
        cout<<ans;
    }
}
