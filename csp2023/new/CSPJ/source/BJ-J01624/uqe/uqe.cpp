#include<bits/stdc++.h>
using namespace std;
long long T,M;
long long gcd(long long a,long long b){
    if(a>b)swap(a,b);
    long long k=b%a;
    b=a;
    a=k;
    if(a==0)return b;
    gcd(a,b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }else{
            if((int)sqrt(d)*(int)sqrt(d)==d){
                long long p1=-1*b+sqrt(d);
                long long q=2*a;
                long long p2=-1*b-sqrt(d);
                long long s;
                if(q>0){
                    s=max(p1,p2);
                }else{
                    s=min(p1,p2);
                }
                if(s==0){
                    cout<<0<<endl;
                    continue;
                }
                if(s%q==0){
                    cout<<s/q<<endl;
                    continue;
                }
                if(s<0){
                    if(q<0){
                        s=-s;
                        q=-q;
                    }else{
                        cout<<'-';
                        s=-s;
                    }
                }
                if(s>0&&q<0){
                    cout<<'-';
                    q=-q;
                }
                cout<<s/gcd(s,q)<<'/'<<q/gcd(s,q)<<endl;
            }else {
                long long f1=-1*b;
                long long f2=2*a;
                if(f1!=0){
                    if(f1%f2==0){
                        cout<<f1/f2<<'+';
                    }else{
                        int cnt=0;
                        if(f1<0){
                            cnt++;
                            f1=f1*-1;
                        }
                        if(f2<0){
                            cnt++;
                            f2=f2*-1;
                        }
                        if(cnt==1){
                            cout<<'-';
                        }
                        cout<<f1/gcd(f1,f2)<<'/'<<f2/gcd(f1,f2)<<'+';
                    }
                }
                if(f2<0){
                    f2=f2*-1;
                }
                long long ans=1;
                for(long long i=1000;i>=1;i--){
                    if(d%(i*i)==0){
                        ans*=i;
                        d=d/(i*i);
                    }
                }
                long long ans1=ans/gcd(ans,f2);
                long long f22=f2/gcd(ans,f2);
                if(ans1!=1){
                    cout<<ans1<<'*';
                }
                cout<<"sqrt("<<d<<")";
                if(f22!=1){
                    cout<<'/'<<f22;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}