#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(int x){
    int t=sqrt(x);
    return t*t!=x;
}
int f(int x){
    int ret=1;
    for(int i=2;i*i<=x;i++){
        int cnt=0;
        while(x%i==0){
            cnt++;
            x/=i;
            ret*=i;
        }
        if(cnt%2==1){
            ret/=i;
        }
    }
    return ret;
}
string num(int u,int d){
    if(d<0){
        u=-u;
        d=abs(d);
    }
    int t=__gcd(abs(u),abs(d));
    u/=t;
    d/=t;
    string ret="";
    ret+=to_string(u);
    if(d!=1){
        ret+="/";
        ret+=to_string(d);
    }
    return ret;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&n,&m);
    while(n--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        if(!check(delta)){
            int u,d=2*a;
            if(d<0){
                u=-min(-b+sqrt(delta),-b-sqrt(delta));
                d=abs(d);
            }
            else{
                u=max(-b+sqrt(delta),-b-sqrt(delta));
            }
            cout<<num(u,d)<<endl;
        }
        else{
            string q1=num(-b,2*a);
            if(q1!="0"){
                cout<<q1<<"+";
            }
            int t=f(delta);
            if((int)sqrt(t)==abs(2*a)){
                printf("sqrt(%d)\n",delta/t);
            }
            else if(int(sqrt(t))%abs(2*a)==0){
                printf("%d*sqrt(%d)\n",(int)sqrt(t)/abs(2*a),delta/t);
            }
            else{
                int u=sqrt(t);
                int d=abs(2*a);
                int x=__gcd(abs(u),abs(d));
                u/=x;
                d/=x;
                if(u==1){
                    printf("sqrt(%d)/%d\n",delta/t,d);
                }
                else{
                    printf("%d*sqrt(%d)/%d\n",u,delta/t,d);
                }
            }
        }
    }
    return 0;
}
