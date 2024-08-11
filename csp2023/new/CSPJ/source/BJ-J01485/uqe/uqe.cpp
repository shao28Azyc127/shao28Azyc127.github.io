#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int gcd(int a, int b){
    int c, d;
    a=abs(a), b=abs(b);
    if(a<b){
        c=a;
        a=b;
        b=c;
    }
    d=a%b;
    if(d==0) return b;
    else return(gcd(b,d));
}
void out(int up, int dw){
    int s=gcd(up,dw);
    int a, b;
    a=up/s; b=dw/s;
    if(b<0){
        a*=-1;
        b*=-1;
    }
    if(b==1) cout<<a;
    else{
        cout<<a<<"/"<<b;
    }
}
double out2(int up, int dw){
    double f=up/dw;
    return f;
}
int ta(int a){
    int p;
    for(int i=a-1; i>=2; i--){
        if(a%i==0&&sqrt(i)-(int)sqrt(i)==0){
            p=sqrt(i);
            return p;
        }
    }
    return 0;
}
int T, M;
int a, b, c;
int dt, x1, x2;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin>>T>>M;
    for(int i=1; i<=T; i++){
        cin>>a>>b>>c;
        dt=(b*b)-(4*a*c);
        if(dt<0){
            cout<<"NO";
            continue;
        }
        if(sqrt(dt)-(int)sqrt(dt)!=0){
            int q1_u=-b;
            int q1_d=2*a;
            int q2_u=1;
            int q2_d=2*a;
            int r=dt;
            out(q1_u, q1_d);
            cout<<"+";
            if(q2_d==1) cout<<"sqrt("<<r<<")"<<endl;
            else if(q2_d>1) cout<<"sqrt("<<r<<")/"<<q2_d<<endl;
            else{
               cout<<ta(r)<<"sqrt("<<r/ta(r)<<")/"<<q2_d<<endl;
            }

        }else{
            int o=sqrt(dt);
            int x1_up=(-b+o);
            int x1_dw=(2*a);
            int x2_up=(-b-o);
            int x2_dw=(2*a);
            if(out2(x1_up, x1_dw)>out2(x2_up, x2_dw)) out(x1_up, x1_dw);
            else out(x2_up, x2_dw);

            cout<<endl;
            //out(x2_up, x2_dw);
        }

    }



    fclose(stdin);
    fclose(stdout);
}

