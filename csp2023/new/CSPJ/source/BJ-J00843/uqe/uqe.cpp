#include<iostream>
#include<cmath>
using namespace std;
int T,M;
int a,b,c;
int Delta;
int gcd(int x,int y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int simpler(int x){
    int maxn=1;
    for(int i=2;i*i<=x;i++){
        if(x%(i*i)==0)
            maxn=i;
    }
    return maxn;
}
double abss(double x){
    if(x<0)return 0-x;
    else return x;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        Delta=b*b-4*a*c;
        if(Delta<0){
            cout<<"NO";
        }else{
            double ans=(0-b)*1.0/(2*a)+abss(sqrt(Delta)*1.0/(2*a));
            int x=(int)ans;
            if(ans==x){
                cout<<x<<endl;
                continue;
            }
            //-b/2a + sqrt(Delta)/2a;
            if((0-b)!=0){
                if(((0-b)%(2*a))==0){
                    cout<<(0-b)/(2*a);
                }else{
                    int t1=0-b;
                    int t2=2*a;
                    if((t1)/gcd(t1,t2)>=0&&(t2)/gcd(t1,t2)<0)
                        cout<<0-(t1)/gcd(t1,t2)<<"/"<<0-(t2)/gcd(t1,t2);
                    else
                        cout<<(t1)/gcd(t1,t2)<<"/"<<(t2)/gcd(t1,t2);
                }
                if(Delta!=0)
                cout<<"+";
            }
            int s=simpler(Delta);
            int Deltanow=Delta/s/s;
            //q2=s/(2*a)
            if(Deltanow==0){
                cout<<endl;
                continue;
            }
            int tmpgcd=gcd(s,2*a);
            int ts=s/gcd(s,2*a);
            int ta=(2*a)/gcd(s,2*a);
            if(ta<0)ta=0-ta;
            if(ts<0)ts=0-ts;
            if(ta==ts)cout<<"sqrt("<<Deltanow<<")";
            else if(ta==1)cout<<ts<<"*sqrt("<<Deltanow<<")";
            else if(ts==1)cout<<"sqrt("<<Deltanow<<")/"<<ta;
            else{
                cout<<ts<<"*sqrt("<<Deltanow<<")/"<<ta;
            }
        }
        cout<<endl;
    }
    return 0;
}