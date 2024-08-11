#include<bits/stdc++.h>
using namespace std;
int n,t;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,b%a);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>t;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0) cout<<"NO\n";
        else{
            double fkjdsahfkjhds=sqrt(delta);
            int dskjhfkdsahfl=sqrt(delta);
            if(fkjdsahfkjhds==dskjhfkdsahfl){
                int x,y;
                x=-1*b+dskjhfkdsahfl;
                y=2*a;
                int tmp=gcd(abs(x),abs(y));
                if(abs(y)==tmp)
                    cout<<(x/tmp)*y/abs(y)<<'\n';
                else
                    cout<<(x/tmp)*y/abs(y)<<'/'<<abs(y)<<'\n';
            }
            else{
                int x,y;
                x=-1*b;
                y=2*a;
                int tmp=gcd(abs(x),abs(y)),tmp2=1;
                for(int i=2;i*i<=delta;i++) if(delta%(i*i)==0){
                    delta/=i*i;
                    tmp2*=i;
                }
                int tmp3=gcd(tmp2,abs(y));
                if(abs(y)==tmp)
                    cout<<(x/tmp)*y/abs(y);
                else
                    cout<<(x/tmp)*y/abs(y)<<'/'<<abs(y);
                if(abs(y)==tmp2&&delta!=0) cout<<'+'<<tmp2/tmp3*(y/abs(y))<<"sqrt("<<delta<<")\n";
                else cout<<'+'<<abs(tmp2/tmp3)<<"sqrt("<<delta<<")"<<abs(y/tmp3)<<'\n';
            }
        }
    }
    return 0;
}