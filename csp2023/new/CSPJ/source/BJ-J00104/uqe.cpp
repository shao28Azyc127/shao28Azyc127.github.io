#include <iostream>
#include <cmath>
#include <cstring>
#include <math.h>
using namespace std;
int n,m;
int gcd(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    if(a>b){
        return gcd(b,a%b);
    }else{
        return gcd(a,b%a);
    }

}
int simple(int &a,int &b){
    bool a1=(a>=0);
    bool b1=(b>=0);
    int g=gcd(abs(a),abs(b));
    if(a1){
        a=abs(a)/g;
    }else{
        a=-(abs(a)/g);
    }
    if(b1){
        b=abs(b)/g;
    }else{
        b=-(abs(b)/g);
    }
    return 0;
}
int co(int x,int y,int a){
    int ad=x+y,su=x-y;
    bool b1=(ad>=0),b2=(su>=0),b3=(a>=0);
    int t1,t2,t3;
    if(b1)t1=ad;
    else t1=-ad;
    if(b2)t2=su;
    else t2=-su;
    if(b3)t3=a;
    else t3=-a;
    int a1=t3,a2=t3;
    simple(t1,a1);
    simple(t2,a2);
    if(b1)ad=t1;
    else ad=-t1;
    if(b2)su=t2;
    else su=-t2;
    if(!b3){
        a1=-a1;
        a2=-a2;
    }
    if(a1==a2){
        if(ad<su){
            ad=su;
        }
    }else{
        int temp_1=ad,temp_2=su;
        temp_1=ad*a2;
        temp_2=su*a1;
        if(temp_1<temp_2){
            ad=su;
            a1=a2;
        }
    }
    if(ad%a1==0){
        cout<<ad/a1<<endl;
    }else{
        cout << ad<<"/"<<a1<<endl;
    }
    return 0;
}
int sm_sq(int x){

    int ttx=x;
    int y[2505];
    memset(y,0,sizeof(y));
    int k=2,hj=1;
    while(x/k!=0){
        if(x%k==0){
            while(x%k==0){
                x/=k;
                y[k]++;
                if(y[k]%2==0){
                    hj*=k;
                }
            }
        }
        k+=1;
    }
    return hj;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>> n >> m;
    sm_sq(48);
    sm_sq(24);
    for(int i = 0;i<n;i++){
        int a=0,b=0,c=0,num=0;
        cin >> a >> b >> c;
        int d=(b*b)-(4*a*c);
        if(d<0){
            cout << "NO"<<endl;
            continue;
        }else if(d==0){
            num=1;
        }else{
            num=2;
        }
        if(int(sqrt(d))*int(sqrt(d))==d){
            co(-b,sqrt(d),2*a);

        }else{
            int aa=2*a;
            int h = sm_sq(d);
            int gen=d/(h*h);
            if(b!=0){

                simple(b,aa);
                if(b%aa==0){
                    cout << b/aa;
                }else{
                    cout<<b<<"/"<<aa;
                }
            }
            if(aa>0){

                aa=2*a;
                simple(h,aa);
                if(h%aa==0){
                    cout<<"+" << h/aa<<"*sqrt("<<gen<<")"<<endl;
                }else{
                    cout<<"+"<<h<<"*sqrt("<<gen<<")/"<<aa<<endl;
                }
            }else{
               if(h%aa==0){
                    cout<<"+" << h/aa<<"*sqrt("<<gen<<")"<<endl;
                }else{
                    cout<<"+"<<h<<"*sqrt("<<gen<<")/"<<aa<<endl;
                }
            }
        }

    }
    return 0;
}

