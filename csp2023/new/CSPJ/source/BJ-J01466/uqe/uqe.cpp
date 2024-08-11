#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
double x,x1,x2;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>T>>M;
    for(int i=0;i<T;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }
        else{
            x1=double((-b+sqrt(b*b-4*a*c))/(2*a));
            x2=double((-b-sqrt(b*b-4*a*c))/(2*a));
            x=max(x1,x2);
            if(sqrt(b*b-4*a*c)==ceil(sqrt(b*b-4*a*c))){ //这个数是有理数
                if(x==ceil(x)){
                    cout<<x<<endl;
                }
                else{
                    int gw=abs(__gcd(int(-b+sqrt(b*b-4*a*c)),2*a));
                    if(-b+sqrt(b*b-4*a*c)>0&&2*a<0){
                        gw=-gw;
                    }
                    cout<<(-b+sqrt(b*b-4*a*c))/gw<<"/"<<2*a/gw<<endl;
                }
            }
            else{
                if((double)-b/2/a==ceil((double)-b/2/a)){
                    cout<<(double)-b/2/a<<"+";
                }
                else{
                    int gw=abs(__gcd(-b,2*a));
                        if(-b>0&&2*a<0){
                            gw=-gw;
                        }
                    cout<<-b/gw<<"/"<<2*a/gw<<"+";
                }
                int gw1=0,flag=0;
                for(int j=sqrt(b*b-4*a*c);j>1;j--){
                    if((b*b-4*a*c)%j==0){
                        gw1=j;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    cout<<"sqrt("<<b*b-4*a*c<<")"<<"/"<<2*a<<endl;
                }
                else{

                }
            }

        }
    }
    return 0;
}