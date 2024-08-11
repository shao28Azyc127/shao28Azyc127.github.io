#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("uqe.in");
ofstream fout("uqe.out");
int gcd(int a,int b){
    if(a<0) return gcd(-a,b);
    if(b<0) return gcd(a,-b);
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a-b);
}
void mul(int q3,int d){
    if(q3!=1){
        fout<<q3;
        if(d!=1) fout<<"*";
    }else if(d==1) fout<<"1";
    if(d!=1) fout<<"sqrt("<<d<<")";
}
void fra(int q2,int q3,int d){
    mul(q3/gcd(q2,q3),d);
    if(q2/gcd(q2,q3)!=1) fout<<"/"<<q2/gcd(q2,q3);
}
void plu(int q1,int q2,int q3,int d){
    if(q2<0){
        plu(-q1,-q2,-q3,d);
        return;
    }
    if(d==0){
        if(q1==0){
            fout<<"0";
            return;
        }
        fra(q2,q1,1);
        return;
    }
    if(d==1){
        fra(q2,q1+q3,1);
        return;
    }
    if(q1!=0){
        fra(q2,q1,1);
        if(q3>0) fout<<"+";
        if(q3<0) fout<<"-";
        if(q3==0) return;
    }
    fra(q2,abs(q3),d);
}
void print(int a,int b,int c){
    int delta=b*b-4*a*c,q1=-b,q2=2*a,q3=1;
    if(delta<0){
        fout<<"NO"<<endl;
        return;
    }
    for(int i=int(sqrt(delta));i>=2;--i){
        if(delta%(i*i)==0){
            delta/=i*i;
            q3=i;
            break;
        }
    }
    plu(q1,q2,q3,delta);
    fout<<endl;
}
int main(){
    int T,M,a,b,c;
    fin>>T>>M;
    for(int i=0;i<T;++i){
        fin>>a>>b>>c;
        print(a,b,c);
    }
    fin.close();
    fout.close();
    return 0;
}
