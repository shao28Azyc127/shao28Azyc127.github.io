#include<bits/stdc++.h>
using namespace std;
long double t,m,a,b,c,w,ans;
bool yl(long double x){
    long double sx=int(sqrt(x));
    if(sx*sx==x)return 1;
    return 0;
}
void yf(int &x,int &y){
    int g=__gcd(x,y);
    x/=g;
    y/=g;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        w=b*b-4*a*c;
        if(w<0)cout<<"NO\n";
        else{
            if(yl(w)){
                int ans1=sqrt(w)-b,ans2=2*a;
                yf(ans1,ans2);
                if(ans1<0&&ans2<0)ans1=-ans1,ans2=-ans2;
                else if(ans1<0)ans1=-ans1,cout<<"-";
                else if(ans2<0)ans2=-ans2,cout<<"-";
                if(ans2!=1)cout<<ans1<<"/"<<ans2<<endl;
                else cout<<ans1<<endl;
            }
            else cout<<"NO\n";
        }
    }
    return 0;
}
