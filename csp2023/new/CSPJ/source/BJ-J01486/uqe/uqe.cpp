#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int p,q,x;
bool isReal(int a,int b,int c){
    if((b*b-4*a*c)>=0)return 1;
    return 0;
}
bool isSquart(int n){
    double i=sqrt(n);
    if(n/i==i)return 1;
    return 0;
}
int gcd(int a,int b){
    int maxy=1;
    for(int i=2;i<=a;++i){
        if(b%i==0&&a%i==0&&i>maxy)maxy=i;
    }
    return maxy;
}
void outQ(){
    int g=gcd(p,q);
    if(q>0){
        if(g==1){
            if(q==1)cout<<p;
            else cout<<p<<"/"<<q;
        }
        else{
            p/=g;
            q/=g;
            if(q==1)cout<<p;
            else cout<<p<<"/"<<q;
        }
    }
}
int main(){
    freopen("uqe.in",r,stdin);
    freopen("uqe.ans",w,stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(!isReal(a,b,c))cout<<"NO"<<endl;//unReal
        else{
            if(isSquart(b*b-4*a*c)){//youli
                if(((-b+sqrt(b*b-4*a*c))/(2*a))>((-b-sqrt(b*b-4*a*c))/(2*a))){
                    p=(-b+sqrt(b*b-4*a*c));
                    q=2*a;
                    outQ();
                }else{
                    p=(-b-sqrt(b*b-4*a*c));
                    q=2*a;
                    outQ();
                }
            }else{//wuli
                if((-b/(2*a))!=0){
                    p=-b;
                    q=2*a;
                    outQ();
                    cout<<"+";
                }
                cout<<"sqrt("<<b*b-4*a*c<<")/"<<2*a<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}