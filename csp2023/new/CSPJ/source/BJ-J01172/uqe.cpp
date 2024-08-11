#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int abs(int x){
    if(x<0)return -x;
    return x;
}

void youli(int a,int b){
    if(a<0&&b>0||a>0&&b<0)cout<<"-";
    a=abs(a);
    b=abs(b);
    int g=gcd(a,b);
    a=a/g;
    b=b/g;
    if(b==1){
        cout<<a;
        return;
    }
    cout<<a<<"/"<<b;
}

void fen(int a,int b){
    b=abs(b);
    int x=1;
    for(int i=2;i<=sqrt(a);i++){
        int cnt=0;
        while(a%i==0){
            a=a/i;
            cnt++;
            x=x*i;
        }
        if(cnt%2==1){
            a=a*i;
            x=x/i;
        }
    }
    x=sqrt(x);
    int g=gcd(x,b);
    x=x/g;
    b=b/g;
    if(x!=1)cout<<x<<"*";
    cout<<"sqrt("<<a<<")";
    if(b!=1) cout<<"/"<<abs(b);
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,m;
	cin>>T>>m;
	while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(int(sqrt(b*b-4*a*c*1.0))*int(sqrt(b*b-4*a*c*1.0))==b*b-4*a*c){
            if(a>0)
                youli(-b+int(sqrt(b*b-4*a*c*1.0)),2*a);
            else
                youli(-b-int(sqrt(b*b-4*a*c*1.0)),2*a);
            cout<<endl;
            continue;
        }
        if(b!=0){
            youli(-b,2*a);
            cout<<"+";
        }
        fen(b*b-4*a*c,2*a);
        cout<<endl;
	}
	return 0;
}
