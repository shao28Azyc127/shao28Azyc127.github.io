#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
long long n,maxt;
long long gcd(long long a,long long b) {
    if(a%b==0) {
        return b;
    }
    return gcd(b,a%b);
}
int main() {
    long long a=0,b=0,c=0;
    ifstream infile("uqe.in");
    ofstream outfile("uqe.out");
    infile>>n>>maxt;
    for(int i=1;i<=n;i++) {
        infile>>a>>b>>c;
        long long de=b*b-4*a*c;
        long long zhengfu=0;
        if(de<0) {
            outfile<<"NO"<<endl;
        }
        else if(de==0) {
            if(b==0 || a==0) {
                outfile<<0<<endl;
                continue;
            }
            else if((a>0 && b>0) || (a<0 && b<0)) {
                zhengfu=-1;
            }
            else if((a>0 && b<0) || (a<0 && b>0)) {
                zhengfu=1;
            }
            long long g=gcd(abs(b),abs(2*a));
            if(abs(2*a)/g==1) {
                outfile<<zhengfu*abs(b)/g<<endl;
            }
            else {
                outfile<<zhengfu*abs(b)/g<<"/"<<abs(-2*a)/g<<endl;
            }
        }
        else {
            long long zzi=0,zmu=0,gzi=0,gmu=0;
            zzi=-b;
            zmu=2*a;
            gmu=2*a;
            if((long long)sqrt(de)*(long long)sqrt(de)==de) {
                gzi=zzi+(long long)sqrt(de);
                long long g1=gcd(abs(gzi),abs(gmu));
                if((gzi>0 && gmu>0) || (gzi<0 && gmu<0)) {
                    zhengfu=-1;
                }
                else if((gzi>0 && gmu<0) || (gzi<0 && gmu>0)) {
                    zhengfu=1;
                }
                if(gmu/g1==1) {
                    outfile<<zhengfu*gzi/g1<<endl;
                }
                else {
                    outfile<<zhengfu*gzi/g1<<"/"<<gmu/g1<<endl;
                }
            }
            else {
                if((a>0 && b>0) || (a<0 && b<0)) {
                    zhengfu=-1;
                }
                else if((a>0 && b<0) || (a<0 && b>0)) {
                    zhengfu=1;
                }
                long long g2=gcd(abs(-b),abs(2*a));
                if(abs(-2*a)/g2==1) {
                    outfile<<zhengfu*abs(-b)/g2;
                }
                else {
                    outfile<<zhengfu*abs(-b)/g2<<"/"<<zhengfu*abs(-2*a)/g2;
                }
                long long qiangen=0;
                for(long long i=1;i<=sqrt(de);i++) {
                    if(de%(i*i)==0) {
                        qiangen=i;
                    }
                }
                long long g3=gcd(qiangen,abs(gmu));
                if(gmu/g3==1) {
                    outfile<<qiangen/g3<<"*sqrt("<<de/(qiangen*qiangen)<<")"<<endl;
                }
                else {
                    outfile<<qiangen/g3<<"*sqrt("<<de/(qiangen*qiangen)<<")"<<gmu/g3<<endl;
                }
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
