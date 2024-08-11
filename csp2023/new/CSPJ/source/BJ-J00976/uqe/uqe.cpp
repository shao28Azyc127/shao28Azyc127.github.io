#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
int searchSqrt(int x){
    int s=sqrt(x);
    for(int i=s;i>=1;i--){
        int sq=i*i;
        if(x%sq==0){
            return i;
        }
    }
    return 0;
}
int main(){
    FILE* f=freopen("uqe.in","r",stdin);
    FILE* f2=freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(b*b-4*a*c==0){
            b=-b;
            a=2*a;
            int k=gcd(abs(a),abs(b));
            b/=k;
            a/=k;
            if(a!=1&&b!=0){
                cout<<b<<'/'<<a<<endl;
                continue;
            }
            cout<<b<<endl;
            continue;
        }
        double st=sqrt(b*b-4*a*c);
        int k=ceil(st);
        int x,a2=a*2;
        if(k==st){
            if(2*a<0){
                x=-b-st;
            }
            else{
                x=-b+st;
            }
            int k2=gcd(abs(x),abs(a2));
            x/=k2;
            a2/=k2;
            if(abs(a2)!=1&&x!=0){
                cout<<x<<'/'<<a2<<endl;
                continue;
            }
            if(a2==-1){
                cout<<-x<<endl;
            }
            cout<<x<<endl;
            continue;
        }
        int b2=-b;
        a2=2*a;
        int k2=gcd(abs(b2),abs(a2));
        b2/=k2;
        int f=b*b-4*a*c;
        int h=searchSqrt(f);
        f/=h*h;
        int k3=gcd(h,abs(a2));
        int a3=a2;
        h/=k3;
        a2/=k2;
        a3/=k3;
        if(a2<0){
            a2=-a2;
            b2=-b2;
        }
        if(a2==1&&b2!=0){
            cout<<b2<<'+';
        }
        else if(a2==-1&&b2!=0){
            cout<<-b2<<'+';
        }
        else if(b2!=0){
            cout<<b2<<'/'<<a2<<'+';
        }
        if(h!=1){
            cout<<h<<'*';
        }
        cout<<"sqrt(";
        cout<<f;
        cout<<')';
        if(a3>0&&a3!=1){
            cout<<'/'<<a3;
        }
        else if(a3<0&&a3!=-1){
            cout<<'/'<<-a3;
        }
        cout<<endl;
    }
    fclose(f);
    fclose(f2);
    return 0;
}
