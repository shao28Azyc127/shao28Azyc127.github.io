#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int gcd(int a,int b){
    if(b == 0)
        return a;
    if(a == 0)
        return b;
    return gcd(b,a%b);
}


string cac1(int x){
    int xx=x;
    string ans="";
    if(x == 0)
        return "0";
    if(x < 0)
        x = -x;
    while(x != 0){
        char l=x%10+'0';
        ans = l+ans;
        x /= 10;
    }
    if(xx < 0)
        ans = '-'+ans;
    return ans;
}

int cac2(int x){
    int ans = 1;
    for(int i=sqrt(x);i>=2;i--){
        if(x%(i*i) == 0){
            ans *= i;
            x /= i*i;
        }
    }
    return ans;
}


string cac(int a,int b,int c,int d){
    a *= 2;
    int aa;
    string ans="";
    int dd=cac2(d);
    if(d/(dd*dd) == 1){
        d = 0;
        b -= dd;
        dd = 0;
    }
    if(b != 0){
        int ff=gcd(abs(b),abs(a));
        if(ff == a){
            b /= a;
            aa = 1;
        }
        else{
            b /= ff;
            aa = a/ff;
        }
    }


    int ff=gcd(dd,abs(a));
    if(ff == a){
        dd /= ff;
        a = 1;
    }
    else{
        a /= ff;
        dd /= ff;
    }

    if(d == 0){
        ans = "";
    }
    else if(d/(dd*dd) == 1){
        ans = cac1(dd);
    }
    else{
        if(dd != 1){
            ans = cac1(dd)+"*sqrt("+cac1(d/(cac2(d)*cac2(d)))+")";
        }
        else{
            ans = "sqrt("+cac1(d/(cac2(d)*cac2(d)))+")";
        }
    }

    if(a != 1  &&  ans != ""){
        ans = ans+"/"+cac1(a);
    }

    if(b != 0){
        if(aa != 1){
            if(ans != "")
                ans = cac1(-b)+"/"+cac1(aa)+"+"+ans;
            else
                ans = cac1(-b)+"/"+cac1(aa);
        }
        else{
            if(ans != "")
                ans = cac1(-b)+"+"+ans;
            else
                ans = cac1(-b);
        }
    }

    if(ans == "")
        ans = "0";
    return ans;
}




int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin>>t;
    int m;
    cin>>m;
    for(int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a < 0){
            b = -b;
            c = -c;
            a = -a;
        }
        int d;
        d = pow(b,2)-4*a*c;
        if(d < 0){
            cout<<"NO"<<endl;
        }
        else{
            /*
            int x=-b+sqrt(d);
            x /= 2*a;
            cout<<x<<endl;
            */

            cout<<cac(a,b,c,d)<<endl;
        }
    }
    return 0;
}
