#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
ifstream fin;
ofstream fout;

int gcd(int p,int q){
    if(p%q==0){
        return q;
    }
    else{
        return gcd(q,p%q);
    }

}
int uqe(){

    int a,b,c;
    fin>>a>>b>>c;
    int delta=b*b-4*a*c;
    if(delta<0){
        fout<<"NO\n";
        return 0;
    }

    double urika=0;
    urika=max((-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
    int m=0;
    if(a<0){
        m=(-b-sqrt(delta));
    }
    else{
        m=(-b+sqrt(delta));
    }
    if(int(sqrt(delta))==sqrt(delta)){
        int urgcd=gcd(m,(2*a));
        int pur,qur;
        pur=m/urgcd;
        qur=(2*a)/urgcd;
        if(qur<0){
            qur*=-1;
            pur*=-1;
        }
        if(qur!=1){
            fout<<pur<<"/"<<qur<<endl;}
        else{
            fout<<pur<<endl;
        }
        return 0;
    }


    int q1=0,q2=0,r=0;
    q1=(-b)/2*a;
    if(q1!=0){
        int q1gcd=gcd(-b,(2*a));
        int pq1,qq1;
        pq1=-b/q1gcd;
        qq1=(2*a)/q1gcd;
        if(qq1<0){
            qq1*=-1;
            pq1*=-1;
        }
        if(qq1!=1){
            fout<<pq1<<"/"<<qq1;}
        else{
            fout<<pq1;
        }
        fout<<"+";
    }

    r=delta;
    int sqp=1;
    for(int i=2;i<=sqrt(r);i++){
        while(r%(i*i)==0){
            r/=(i*i);
            //fout<<"     "<<r<<" "<<sqp<<endl;

            sqp*=i;
        }
    }
    int rgcd=gcd(sqp,2*a);
    int pr,qr;
    pr=sqp/rgcd;
    qr=(2*a)/rgcd;
    //fout<<endl<<pr<<" "<<qr<<endl;
    if(pr<0&&qr>0){
        pr*=-1;
    }
    if(pr>0&&qr<0){
        qr*=-1;
    }
    if(float(pr)/qr!=1){
        //fout<<"t1"<<endl;
        if(qr!=1&&pr!=1){
            fout<<pr<<"*sqrt("<<r<<")/"<<qr<<endl;
            }
        else if(qr==1){
            fout<<pr<<"*sqrt("<<r<<")\n";
        }
        else if(pr==1){
            fout<<"sqrt("<<r<<")/"<<qr<<endl;
        }
    }
    else{
        fout<<"sqrt("<<r<<")\n";
    }

    return 0;
}
int main(){

    fout.open("uqe.out");
    fin.open("uqe.in");
    int n,maxi;
    fin>>n>>maxi;
    for(int i=0;i<n;i++){
        uqe();
    }
    return 0;
}
