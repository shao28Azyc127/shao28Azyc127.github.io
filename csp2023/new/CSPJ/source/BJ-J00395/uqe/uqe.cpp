#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    int c;
    if (a>b) c=b;
    else c=a;
    for(int i=c;;i--){
        if (a%i==0 and b%i==0) return i;
    }
}
int getk(int x){
    for (int i=round(sqrt(x));i>0;i--){
        if (x%(i*i)==0) return i;
    }
}
int main(){
    freopen("uqe.in",'r',stdin);
    freopen("uqe.out",'w',stdout);
    int T,M;
    int a[5003],b[5003],c[5003];
    double res[5003],dt[5003];
    cin>>T>>M;
    for(int i=0;i<T;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i=0;i<T;i++){
        dt[i]=b[i]*b[i]-4*a[i]*c[i];
        if (dt[i]<0){
            cout<<"NO"<<endl;
            continue;
        }

        res[i]=(-1*b[i]+sqrt(dt[i]))/(2*a[i]);
        int exst=0;
        if (sqrt(dt[i])-round(sqrt(dt[i]))==0) exst=sqrt(dt[i]);
        if(b[i]==0 && exst==0){
            ;
        }
        if (((-b[i]+exst)%(2*a[i])==0)){
            if (b[i]!=0) cout<<(-b[i]+exst)/(2*a[i]);
        }
        else{
            int g=gcd(-b[i],2*a[i]);
            if (2*a[i]/g<0){
                cout<<b[i]/g+exst*(-2*a[i]/g)<<'/'<<-2*a[i]/g;
            }else cout<<-b[i]/g<<'/'<<2*a[i]/g;
        }
        if(dt[i]==0){
            cout<<endl;
            continue;
        }
        cout<<'+';
        int k=getk(dt[i]);
        double q2=double(k)/(2*a[i]);
        double q3=1/q2;
        dt[i]/=(k*k);

        if(q2==1){
            cout<<"sqrt("<<dt[i]<<')';
        }
        else if (q2-round(q2)==0){
            cout<<int(q2)<<'*'<<"sqrt("<<dt[i]<<')';
        }
        else if (q3-round(q3)==0){
            cout<<"sqrt("<<dt[i]<<")/"<<int(q3);
        }
        else{
            cout<<k<<"*sqrt("<<dt[i]<<")/"<<2*a[i];
        }
        cout<<endl;
    }
    return 0;
}
