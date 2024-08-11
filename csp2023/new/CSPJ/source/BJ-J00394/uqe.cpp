#include<bits/stdc++.h>
using namespace std;
int a[10002],b[10002],c[10002],d[10002];
int gcd(int a,int b){
    int a1=abs(a),b1=abs(b);
    for(int i=min(a1,b1);i>=1;i--){
        if(a1%i==0 && b1%i==0){
            return i;
        }
    }
    return 1;
}
int sqr(int a){
    int x=floor(sqrt(a));
    for(int i=x;i>=2;i--){
        if(a%(i*i)==0) a/=(i*i);
    }
    return a;
}
int main(){
    int T,M,p1,q1;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        cin>>a[i]>>b[i]>>c[i];
        d[i]=(b[i]*b[i])-(4*a[i]*c[i]);
    }
    for(int i=0;i<T;i++){
        if(d[i]<0){
            cout<<"NO"<<endl;
        }else if(d[i]==0){
            int c=b[i]*-1,d=a[i]*2;
            int gcd1=gcd(c,d);
            int c1=c/gcd1,d1=d/gcd1;
            if(d1==1) cout<<c1/d1<<endl;
            else printf("%d/%d\n",c1,d1);
        }else{
            int dd=d[i];
            int c=b[i]*-1,d=a[i]*2;
            int gcd1=gcd(c,d);
            int c1=c/gcd1,d1=d/gcd1;
            if(sqr(dd)==1){
                int gcd1=gcd(c+sqrt(dd),d);
                int c1=(c+sqrt(dd))/gcd1,d1=d/gcd1;
                if(d1==1) cout<<(c1/d1)<<endl;
                else printf("%d/%d\n",c1,d1);
            }
        }
    }
    return 0;
}
