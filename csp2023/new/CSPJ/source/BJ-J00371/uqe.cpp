#include<bits/stdc++.h>
using namespace std;
bool check(int x){
    for(int i=1;i<=min(1000,x);i++){
        if(i*i==x){
            return true;
        }
    }
    return false;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        else if(check(d)){
            int rrt=sqrt(d);
            int GCD=__gcd(-1*b+rrt,2*a);
            if(GCD==2*a)cout<<(-1*b+rrt)/(2*a);
            else cout<<(-1*b+rrt)/GCD<<'/'<<(2*a)/GCD;
            cout<<endl;
        }
        else{
            if(b!=0){
if((-1*b)%(2*a)==0)cout<<(-1*b)/(2*a);
else cout<<(-1*b)/__gcd(-1*b,2*a)<<'/'<<(2*a)/__gcd(-1*b,2*a);
}
            if(d==0)continue;
            if(b!=0)cout<<'+';
            int ans1=1,ans2=0;
            for(int i=2;i<=min(1000,x);i++){
                if(d%(i*i)==0){
                    ans1=i;
                    ans2=d/(i*i);
                }  
            }
            if(ans1!=1){
                if(__gcd(ans1,2*a)!=2*a)cout<<ans1/(__gcd(ans1,2*a))<<'*'<<"sqrt("<<ans2<<')'<<(2*a)/(__gcd(ans1,2*a));
            }
            else cout<<"sqrt("<<d<<')/'<<2*a;
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}