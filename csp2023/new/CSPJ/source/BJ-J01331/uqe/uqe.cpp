#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,n,p,q,l,k,g;
double x1,x2;
void gnt() {
    if (q<0) {
        p=(-1)*p;
        q=(-1)*q;
    }
    int minn=min(abs(p),abs(q));
    for (int i=minn;i>1;i--)
        if (abs(p)%i==0&&abs(q)%i==0) {
            p/=i;
            q/=i;
            return;
        }
}
int gnt2() {
    for (int i=sqrt(n);i>1;i--)
        if (n%(i*i)==0)
            return i;
    return 1;
}
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);
    for (int i=1;i<=t;i++) {
        scanf("%d %d %d",&a,&b,&c);
        n=b*b-4*a*c;
        if (n<0)
            printf("NO\n");
        else if ((int)sqrt(n)==sqrt(n)) {
            l=(-1)*b;
            k=sqrt(n);
            g=2*a;
            if ((l+k)*1.0/g<(l-k)*1.0/g)
                p=l-k;
            else
                p=l+k;
            q=2*a;
            gnt();
            if (q==1)
                printf("%d\n",p);
            else if (p==0)
                printf("%d\n",0);
            else
                printf("%d/%d\n",p,q);
        }
        else {
            p=(-1)*b;
            q=2*a;
            gnt();
            if (q==1)
                printf("%d+",p);
            else if (p!=0)
                printf("%d/%d+",p,q);
            p=gnt2();
            q=2*a;
            if ((p*sqrt(n))*1.0/(q*1.0)<(p*sqrt(n))*(-1.0)/(q*1.0))
                p=-p;
            n/=(p*p);
            gnt();
            if (q==1&&p==1)
                printf("sqrt(%d)\n",n);
            else if (q==1)
                printf("%d*sqrt(%d)\n",p,n);
            else if (p==1)
                printf("sqrt(%d)/%d\n",n,q);
            else
                printf("%d*sqrt(%d)/%d\n",p,n,q);
        }
    }
    return 0;
}
