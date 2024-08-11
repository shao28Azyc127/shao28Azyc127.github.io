//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

int num[1000005];
int prime[500005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int t; cin>>t;
    int m; cin>>m;

    num[1]=1;
    int cnt; cnt=0;
    for(int i=2;i<=m;i++){
        if(!num[i]){
            prime[++cnt]=i;
        }

        for(int j=1;j<=cnt,i*prime[j]<=m;j++){
            num[i*prime[j]]=1;

            if(i%prime[j]==0){
                break;
            }
        }
    }

    while(t--){
        int a; cin>>a;
        int b; cin>>b;
        int c; cin>>c;

        if(a<0){
            a=-a;
            b=-b;
            c=-c;
        }

        //cout<<a<<" "<<b<<" "<<c<<" ";

        int delta; delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO\n";
            continue;
        }

        //-b+sqrt(delta)/2*a

        int fm; fm=2*a;

        int x; x=1;
        int n; n=delta;
        for(int i=1;prime[i]*prime[i]<=n;i++){
            while(n%(prime[i]*prime[i])==0){
                n/=(prime[i]*prime[i]);
                //cout<<prime[i]*prime[i]<<endl;
                x*=prime[i];
            }
        }

        int yyy; yyy=abs(b);
        int lhx; lhx=__gcd(yyy,fm);

        yyy=-b;
        yyy/=lhx;
        int fffff; fffff=fm/lhx;

        if(delta==0){
            if(yyy==0){
                cout<<0<<endl;
                continue;
            }

            if(fffff==1){
                cout<<yyy;
            }
            else{
                cout<<yyy<<"/"<<fffff;
            }

            cout<<endl;
            continue;
        }

        lhx=__gcd(x,fm);
        x/=lhx;
        int kkkkk; kkkkk=fm/lhx;

        //cout<<x<<" "<<n<<" "<<kkkkk<<" "<<fffff<<" ";
        if(n==1){
            int ffz; ffz=yyy*kkkkk+x*fffff;
            int ffm; ffm=kkkkk*fffff;
            lhx=__gcd(abs(ffz),abs(ffm));

            //cout<<"abs:"<<lhx<<"   ";
            ffz/=lhx;
            ffm/=lhx;

            if(ffm==1){
                cout<<ffz;
            }
            else{
                cout<<ffz<<"/"<<ffm;
            }
        }
        else{
            if(yyy!=0){
                if(fffff==1){
                    cout<<yyy<<"+";
                }
                else{
                    cout<<yyy<<"/"<<fffff<<"+";
                }
            }

            if(x==1){
                cout<<"sqrt("<<n<<")";

                if(kkkkk!=1){
                    cout<<"/"<<kkkkk;
                }
            }
            else{
                cout<<x<<"*sqrt("<<n<<")";

                if(kkkkk!=1){
                    cout<<"/"<<kkkkk;
                }
            }
        }

        cout<<endl;
    }
    return 0;
}
