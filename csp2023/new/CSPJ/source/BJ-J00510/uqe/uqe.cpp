#include<iostream>
#include<cmath>
using namespace std;
long long t,m,a,b,c,d,x,xx,p,q,xxx,g,q1,q2,q3,q4;
int gcd(int y,int z){
    if(z==0)return y;
    else return gcd(z,y%z);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
        }
        else{
            xx=xxx=sqrt(d);
            xx*=xx;
            if(d==xx){
                if(a>0)p=(-b+xxx);
                else p=(-b-xxx);
                q=2*a;
                //cout<<p<<q<<endl;
                if((p<0||q<0)&&(p>=0||q>=0)&&p!=0)cout<<"-";
                p=abs(p);
                q=abs(q);
                g=gcd(p,q);
                p/=g;
                q/=g;
                if(q==1)cout<<p<<endl;
                else cout<<p<<"/"<<q<<endl;
            }
            else{
                q1=0-b;
                q2=2*a;
                //cout<<q1<<q2<<endl;
                if((q1<0||q2<0)&&(q1>=0||q2>=0)&&q1!=0)cout<<"-";
                q1=abs(q1);
                q2=abs(q2);
                g=gcd(q1,q2);
                q1/=g;
                q2/=g;
                if(q1!=0){
                    if(q2==1)cout<<q1;
                    else cout<<q1<<"/"<<q2;
                    cout<<"+";
                }
                q3=1;
                q4=2*a;
                //cout<<q3<<" "<<d<<" "<<q4<<endl;
                int r=d;
                for(int i = 2;i<=xxx;i++){
                    while(r%(i*i)==0){
                        int ii=i*i;
                        q3*=i;
                        r/=ii;
                    }
                }
                q3=abs(q3);
                q4=abs(q4);
                g=gcd(q3,q4);
                q3/=g;
                q4/=g;
                //cout<<q3<<" "<<r<<" "<<q4<<endl;
                if(q3!=1){
                    cout<<q3<<"*";
                }
                cout<<"sqrt("<<r<<")";
                if(q4!=1)cout<<"/"<<q4;
                cout<<endl;
            }
        }
    }
    return 0;
}
