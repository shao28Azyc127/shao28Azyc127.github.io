#include<bits/stdc++.h>
using namespace std;
long long n,m,ny=0;
long long f=0;
long long q=0;
long long a,b,c,k;
int flag=0;
long long e=1;
long long ans=0;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        f=pow(b,b)-4*a*c;
        if(f<0)
        {
            cout<<"NO"<<endl;
        }
        if(b!=0){
            if(f==0){
                if((-b)%(2*a)==0)
                {
                    cout<<-b/2*a<<endl;
                }
                else{

                    if(b>2*a){
                        for(int j=abs(2*a)-1;j>=1;j--){
                            if(-b%j==0)
                            {
                                k=j;
                                cout<<-b/k<<"/"<<2*a/k<<endl;
                                break;
                            }
                        }
                    }
                    else{
                        for(int j=abs(b)-1;j>=1;j--){
                            if(-b%j==0)
                            {
                                k=j;
                                cout<<-b/k<<"/"<<2*a/k<<endl;
                                break;
                            }
                        }
                    }
                }
            }

        }
        if(f!=0)
        {
            if(sqrt(f)>2*a){
                for(int j=abs(2*a);j>=1;j--){
                    q=sqrt(f);
                    if(q%j==0)
                    {
                        k=j;
                        cout<<sqrt(f)/k<<"/"<<2*a/k<<endl;
                        break;
                    }
                }
            }
            else{
                for(int j=abs(sqrt(f));j>=1;j--){
                    q=sqrt(f);
                    if(q%j==0)
                    {
                        k=j;
                        cout<<sqrt(f)/k<<"/"<<2*a/k<<endl;
                        break;
                    }
                }
            }
        }

    }
    return 0;
}

