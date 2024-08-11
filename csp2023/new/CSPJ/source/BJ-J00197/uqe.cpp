#include <bits/stdc++.h>
using namespace std;
int t,m,d,ans=0;
const int maxn=1e5+5;
int v[maxn],a[maxn],cnt[maxn];
bool boo;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=1;i<=n;i++){
            cnt[i]=i*i;
        }
        if(b==0&&c==0) {
        cout<<"0"<<endl;
        return 0;}
        if(c==0){
            if(b<0){
                cout<<0-b<<"/"<<a<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }else if(b*b-4*a*c==0){
            cout<<(0-b)/(2*a)<<endl;
        }else{
            for(int i=1;i<=maxn;i++){
                if(b*b-4*a*c==cnt[i]){
                        boo=true;
                }
            }
            if(boo)cout<<(0-b+i)/(2*a)<<endl;
            else{
                if(b%abs(2*a)!=0){
                    if(a>0&&b>0)
                    cout<<0-(b/__gcd(2*a,b))<<"/"<<(2*a/__gcd(2*a,b))<<"+sqrt("<<b*b-4*a*c<<")/"<<(2*a)<<endl;
                    else if(a<0&&b>0)
                    cout<<(b/__gcd(0-2*a,b))<<"/"<<((0-2*a)/__gcd(0-2*a,b))<<"+sqrt("<<b*b-4*a*c<<")/"<<0-(2*a)<<endl;
                    else if(a>0&&b<0)
                    cout<<0-(b/__gcd(2*a,0-b))<<"/"<<(2*a/__gcd(2*a,0-b))<<"+sqrt("<<b*b-4*a*c<<")/"<<(2*a)<<endl;
                    else if(a<0&&b<0)
                    cout<<(b/__gcd(0-2*a,0-b))<<"/"<<((0-2*a)/__gcd(0-2*a,0-b))<<"+sqrt("<<b*b-4*a*c<<")/"<<0-(2*a)<<endl;
                }
                else {
                    if(a>0&&b>0)
                    cout<<b/(2*a)<<"+sqrt("<<b*b-4*a*c<<")/"<<(2*a)<<endl;
                    else if(a<0&&b>0)
                    cout<<b/(-2*a)<<"+sqrt("<<b*b-4*a*c<<")/"<<-(2*a)<<endl;
                    else if(a>0&&b<0)
                    cout<<-b/(2*a)<<"+sqrt("<<b*b-4*a*c<<")/"<<(2*a)<<endl;
                    else if(a<0&&b<0)
                    cout<<-b/(-2*a)<<"+sqrt("<<b*b-4*a*c<<")/"<<-(2*a)<<endl;
            }
        }
    }
    return 0;
}