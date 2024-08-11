#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,m;
void solve(){

    int a,b,c;
    cin>>a>>b>>c;
    int delta=b*b-4*a*c;
    if(delta<0){
        cout<<"NO\n";
    }else{
        if(delta==0){
            if(2*a==1){
                cout<<-b<<'\n';
            }else{
                if(-b/a*2==(int)-b/a*2) cout<<-b/2*a<<'\n';
                    else cout<<-b<<"/"<<2*a<<'\n';
            }
        }else{
            if(2*a==1){
                if((int)(sqrt(delta))*(int)(sqrt(delta))==delta) cout<<-b<<'+'<<sqrt(delta)<<'\n';
                    else cout<<-b<<"+"<<"sqrt"<<"("<<delta<<")"<<'\n';
            }else{
                if((int)(sqrt(delta))*(int)(sqrt(delta))==delta) {
                    if(-b/2*a==(int)-b/2*a){
                            int A=-b/2*a;
                            if(sqrt(delta)/a==(int)sqrt(delta)/a) cout<<A+(sqrt(delta)/a)<<'\n';
                            else cout<<A<<'+'<<sqrt(delta)<<'/'<<a<<'\n';
                    }
                    else{
                        cout<<-b<<"/"<<2*a<<'+';
                        if(sqrt(delta)/a==(int)sqrt(delta)/a) cout<<(sqrt(delta)/a)<<'\n';
                        else cout<<sqrt(delta)<<'/'<<a<<'\n';
                    }
                }
                else if(-b/2*a==(int)-b/2*a) cout<<-b/2*a<<"+"<<"sqrt("<<delta<<")"<<"/"<<2*a<<'\n';
                else cout<<-b<<"/"<<2*a<<"+"<<"sqrt("<<delta<<")"<<"/"<<2*a<<'\n';
            }
        }
    }
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T>>m;
    while(T--){
        solve();
    }
    return 0;
}
