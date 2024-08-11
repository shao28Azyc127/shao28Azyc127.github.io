#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,M;
ll a,b,c;
bool IsInt(double num){
    return (int)num==num;
}
ll sqr(int n){
    if(n==1) return 1;
    for(int i=1;i<n;++i){
        if((IsInt(sqrt(1.0*n/i)))) return sqrt(double(n/i));
    }
    return -1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i=0;i<T;++i){
        cin>>a>>b>>c;
        if(b*b<4*a*c){
            cout<<"NO"<<endl;
        }

        else if(b*b==4*a*c){
            if(b*a>0) cout<<'-';
            a=abs(a);
            b=abs(b);
            ll M,S;
            M=2*a/__gcd(2*a,b);
            S=b/__gcd(2*a,b);
            if(M==1){
                cout<<S<<endl;
            }
            else printf("%lld/%lld\n",S,M);

        }
        else if(b*b>4*a*c){
            int d=b*b-4*a*c;
            ll M,S;
            if(sqr(d)==-1){
                if(b!=0){
                    if(b*a>0) cout<<'-';
                    a=abs(a);
                    b=abs(b);
                    M=2*a/__gcd(2*a,b);
                    S=b/__gcd(2*a,b);
                    if(M==1){
                        cout<<S<<endl;
                    }
                    else printf("%lld/%lld+",S,M);
                }
                printf("sqrt(%lld)/%lld\n",d,M);
            }
            else if(IsInt(sqrt(d))){
                if(b!=0){
                    b=b-sqrt(d);
                    if(b*a>0) cout<<'-';
                    a=abs(a);
                    b=abs(b);
                    M=2*a/__gcd(2*a,b);
                    S=b/__gcd(2*a,b);
                    if(M==1){
                        cout<<S<<endl;
                    }
                    else printf("%lld/%lld\n",S,M);
                }
            }
            else {
                if(b!=0){
                    if(b*a>0) cout<<'-';
                    a=abs(a);
                    b=abs(b);
                    M=2*a/__gcd(2*a,b);
                    S=b/__gcd(2*a,b);
                    if(M==1){
                        cout<<S<<"+";
                    }
                    else printf("%lld/%lld+",S,M);
                }
                b=sqrt(d);
                M=2*a;
                int F=sqr(d)/__gcd(sqr(d),M);
                M=M/__gcd(sqr(d),M);
                if(F!=1) cout<<F<<'*';
                if(M==1)    printf("sqrt(%lld)\n",d/sqr(d)/sqr(d));
                else printf("sqrt(%lld)/%lld\n",d/sqr(d)/sqr(d),M);
            }

        }


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
