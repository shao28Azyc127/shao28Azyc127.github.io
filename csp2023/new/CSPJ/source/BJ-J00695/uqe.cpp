#include <bits/stdc++.h>

using namespace std;
void change(int &q1,int &q){
    for(int i=2;i<=sqrt(q);i++){
        while(q%(i*i)==0){
            q/=(i*i);
            q1*=i;
        }
    }
}
int a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int n=b*b-4*a*c;
        if(n<0) cout<<"NO"<<'\n';
        else{
            if(int(sqrt(n))*int(sqrt(n))==n){
                int q;
                if(a>0) q=-b+sqrt(n);
                else q=-b-sqrt(n);
                if(q/(2*a)*2*a==q){
                    cout<<q/(2*a)<<'\n';
                }
                else{
                    if(q*2*a<0){
                        cout<<'-';
                    }q=abs(q),a=abs(a);
                    cout<<q/__gcd(q,2*a)<<'/'<<2*a/__gcd(q,2*a)<<'\n';
                }
            }
            else{
                int q=n;
                if(b!=0){
                    if(-b/(2*a)*2*a==-b){
                        cout<<-b/(2*a);
                    }
                    else{
                        if(-b*2*a<0){
                        cout<<'-';
                        }
                        int k=a;b=abs(b),k=abs(k);
                        cout<<b/__gcd(2*k,b)<<'/'<<2*k/__gcd(2*k,b);
                    }
                    cout<<"+";

                }
                int q1=1;
                change(q1,q);
                if(q1*a<0){
                       
                cout<<'-';} a=abs(a),q1=abs(q1);
                if(q1/__gcd(2*a,q1)==1){
                    if(2*a/__gcd(2*a,q1)==1)cout<<"sqrt("<<q<<")"<<'\n';
                    else cout<<"sqrt("<<q<<")/"<<2*a/__gcd(2*a,q1)<<'\n';
                }
                else{
                    if(q1/(2*a)*2*a==q1){
                        cout<<q1/(2*a)<<"*"<<"sqrt("<<q<<")"<<'\n';
                    }
                    else{
                        cout<<q1/__gcd(2*a,q1)<<"*";
                        cout<<"sqrt("<<q<<")/"<<2*a/__gcd(2*a,q1)<<'\n';
                    }

                }
            }
        }
    }
    return 0;
}
