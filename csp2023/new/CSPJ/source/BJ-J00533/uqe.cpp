#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
int k;
int gcd(int x,int y){
    int ans=1;
    for(int i=2;i<=x&&i<=y;i++){
        while(x%i==0&&y%i==0){
            x/=i,y/=i;
            ans*=i;
        }
    }
    return ans;
}
int fun(int x){
    int ans=1;
    for(int i=2;i<=sqrt(x);i++){
        while(x%(i*i)==0){
            x/=(i*i);
            ans*=i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        k=b*b-4*a*c;
        if(k<0) cout<<"NO\n";
        else if(k==0){
            int p=-b,q=2*a;
            p/=gcd(p,q),q/=gcd(p,q);
            if(q<0) p=-p,q=-q;
            if(q==1) cout<<p<<endl;
            else cout<<p<<'/'<<q<<endl;
        }
        else{
            if((-b+sqrt(k))/2/a>(-b-sqrt(k))/2/a){
                if(sqrt(k)*sqrt(k)==k){
                    int p=-b+sqrt(k),q=2*a;
                    p/=gcd(p,q),q/=gcd(p,q);
                    if(q<0) p=-p,q=-q;
                    if(q==1) cout<<p<<endl;
                    else cout<<p<<'/'<<q<<endl;
                }
                else{
                    int p1=-b,q1=2*a,p2=1,q2=2*a;
                    p2*=fun(k),k/=fun(k)*fun(k);
                    p1/=gcd(p1,q1),q1/=gcd(p1,q1);
                    if(q1<0) p1=-p1,q1=-q1;
                    p2/=gcd(p2,q2),q2/=gcd(p2,q2);
                    if(q2<0) p2=-p2,q2=-q2;
                    if(p1!=0){
                        if(q1==1) cout<<p1;
                        else cout<<p1<<'/'<<q1;
                        cout<<'+'<<endl;
                    }
                    if(p2==1&&q2==1) cout<<"sqrt("<<k<<")\n";
                    else if(q2==1) cout<<p2<<"*sqrt("<<k<<")\n";
                    else{
                        if(p2==1) cout<<"sqrt("<<k<<")/"<<q2<<endl;
                        else cout<<p2<<"*sqrt("<<k<<")/"<<q2<<endl;
                    }
                }
            }
            else{
                if(sqrt(k)*sqrt(k)==k){
                    int p=-b-sqrt(k),q=2*a;
                    p/=gcd(p,q),q/=gcd(p,q);
                    if(q<0) p=-p,q=-q;
                    if(q==1) cout<<p<<endl;
                    else cout<<p<<'/'<<q<<endl;
                }
                else{
                    int p1=-b,q1=2*a,p2=-1,q2=2*a;
                    p2*=fun(k),k/=fun(k)*fun(k);
                    p1/=gcd(p1,q1),q1/=gcd(p1,q1);
                    if(q1<0) p1=-p1,q1=-q1;
                    p2/=gcd(p2,q2),q2/=gcd(p2,q2);
                    if(q2<0) p2=-p2,q2=-q2;
                    if(p1!=0){
                        if(q1==1) cout<<p1;
                        else cout<<p1<<'/'<<q1;
                        cout<<'+'<<endl;
                    }
                    if(p2==1&&q2==1) cout<<"sqrt("<<k<<")\n";
                    else if(q2==1) cout<<p2<<"*sqrt("<<k<<")\n";
                    else{
                        if(p2==1) cout<<"sqrt("<<k<<")/"<<q2<<endl;
                        else cout<<p2<<"*sqrt("<<k<<")/"<<q2<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
