#include <iostream>
using namespace std;
int T,M,a,b,c;
/*
int sqyl(int numbr) {
    int l=1,r=M;
    while (l<r) {
        int mid=(r-l)/2+l;
        //r=mid l=mid+1
        if (mid*mid<numbr)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}
*/
int gcd(int numb1,int numb2) {
    while (numb2) {
        int tmpb2=numb2;
        numb2=numb1%numb2;
        numb1=tmpb2;
    }
    return numb1;
}
inline void hjoyl(unsigned int ylp,unsigned int ylq,bool zf) {
    int gcdylpq=gcd(ylp,ylq);
    ylp/=gcdylpq;
    ylq/=gcdylpq;

    if (ylp==0) cout<<0;
    else {
        if (!zf)
            cout<<'-';
        if (ylq==1)
            cout<<ylp;
        else
            cout<<ylp<<'/'<<ylq;
    }
}
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while (T) {
        cin>>a>>b>>c;
        int drt=b*b-4*a*c;
        if (drt<0) {
                cout<<"NO"<<endl;
                T--;
                continue;
        }
        int i=2,i2,tq2p=1,r=drt;
        while ((i2=i*i)<=r) {
            while (r%i2==0) {
                tq2p*=i;
                r/=i2;
            }
            i++;
        }
        if (r==0) {
            int p,q;
            bool zf;
            p=-b;
            q=2*a;
            if (p==0) q=1;
            if ((p>=0&&q>0)||(p<=0&&q<0))
                zf=true;
            else
                zf=false;
            p=max(p,-p);
            q=max(q,-q);
            hjoyl(p,q,zf);cout<<endl;
            T--;
            continue;
        }
        else if (r==1) {
            int p,q;
            bool zf;
            if ((a>=0&&tq2p>=0)||(a<0&&tq2p<=0)) p=-b+tq2p;
            else p=-b-tq2p;
            q=2*a;
            if (p==0) q=1;
            if ((p>=0&&q>0)||(p<=0&&q<0))
                zf=true;
            else
                zf=false;
            p=max(p,-p);
            q=max(q,-q);
            hjoyl(p,q,zf);cout<<endl;
            T--;
            continue;
        }
        else {
            int q1p,q1q,q2p,q2q;
            bool zfq1;

            q1p=-b;
            q1q=2*a;
            if ((q1p>=0&&q1q>0)||(q1p<=0&&q1q<0)) zfq1=true;
            else zfq1=false;
            q1p=max(q1p,-q1p);
            q1q=max(q1q,-q1q);
            if (q1p!=0) {hjoyl(q1p,q1q,zfq1);}

            q2p=tq2p;
            q2q=2*a;

            q2q=max(q2q,-q2q);


            int gcdq2pq=gcd(q2p,q2q);
            q2p/=gcdq2pq;
            q2q/=gcdq2pq;

            if (r==0) cout<<endl;
            else {
                if (q1p!=0) cout<<"+";
                if (q2p==1&&q2q==1) cout<<"sqrt("<<r<<")"<<endl;
                else if (q2q==1) cout<<q2p<<"*sqrt("<<r<<")"<<endl;
                else if (q2p==1) cout<<"sqrt("<<r<<")/"<<q2q<<endl;
                else cout<<q2p<<"*sqrt("<<r<<")/"<<q2q<<endl;
            }
            T--;
        }
    }
    return 0;
}
