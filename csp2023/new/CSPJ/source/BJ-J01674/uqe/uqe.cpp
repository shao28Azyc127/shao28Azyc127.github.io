#include<bits/stdc++.h>
using namespace std;
int t,m,check[2501];
int a,b,c,d;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i = 1;i <= 2500;i++){
        check[i] = i*i;
    }
    while(t--){
        cin>>a>>b>>c;
        d = b*b-4*a*c;
        if(d < 0){
            cout<<"NO"<<'\n';
            continue;
        }
        bool f11,f12;
        int ans11,ans12;
        if(b != 0){
            f11 = true;
            if(abs(b)%(2*abs(a)) == 0){
                f12 = true;
                ans11 = -b/(2*a);
                ans12 = 1;
            }else{
                f12 = false;
                ans11 = -b/__gcd(abs(a*2),abs(b))*(a/abs(a));
                ans12 = abs(2*a)/__gcd(abs(a*2),abs(b));
            }
        }else{
            f11 = false;
        }
        if(d == 0){
            if(f11){
                if(f12){
                    cout<<ans11;
                }else{
                    cout<<ans11<<'/'<<ans12;
                }
            }else{
                cout<<0;
            }
            cout<<'\n';
            continue;
        }
        int ans2 = d;
        for(int i = 2;ans2 >= check[i];i++){
            while(ans2%check[i] == 0){
                ans2 /= check[i];
            }
        }
        bool f2;
        if(ans2 == 1){
            f2 = true;
        }else{
            f2 = false;
        }
        bool f3;
        int ans31,ans32;
        if(abs(int(sqrt(d/ans2)))%(2*abs(a)) == 0){
            f3 = true;
            ans31 = abs((sqrt(d/ans2))/(2*a));
            ans32 = 1;
        }else{
            f3 = false;
            ans31 = (int(sqrt(d/ans2)))/__gcd(abs(a*2),abs(int(sqrt(d/ans2))))*(a/abs(a));
            ans32 = abs(2*a)/__gcd(abs(a*2),abs(int(sqrt(d/ans2))));
        }
        if(f2){
            int fm,fz;
            fm = ans12*ans32;
            fz = ans11*ans32+ans12*ans31;
            if(abs(fz)%abs(fm) == 0){
                cout<<fz/fm;
            }else{
                cout<<fz/__gcd(abs(fz),abs(fm))*(fm/abs(fm))<<abs(fm)/__gcd(abs(fz),abs(fm));
            }
        }else{
            if(f11){
                if(f12){
                    cout<<ans11<<'+';
                }else{
                    cout<<ans11<<'/'<<ans12<<'+';
                }
            }
            if(f3){
                if(ans31 == 1){
                    cout<<"sqrt("<<ans2<<")";
                }else{
                    cout<<ans31<<"*sqrt("<<ans2<<")";
                }
            }else{
                if(ans31 == 1){
                    cout<<"sqrt("<<ans2<<")/"<<ans32;
                }else{
                    cout<<ans31<<"*sqrt("<<ans2<<")/"<<ans32;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}
