#include<bits/stdc++.h>
using namespace std;
int s, a, b, c, T, M, e, f;
bool zhe(double d){
    return d==(int)d;
}
void you(double d){
    int i=1;
    while(!zhe((int)d)){
        //printf("%lf %d\n", d, d==(int)d);
        //break;
        i*=10;
        d*=10;
    }
    int c=__gcd(i, (int)d);
    i/=c;
    d/=c;
    e=d;
    f=i;
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while(T--){
        //scanf("%d %d %d", &a, &b, &c);
        cin >> a >> b >> c;
        s=b*b-4*a*c;
        //printf("%d %d %d %d\n",a, b, c, s);
        double d=sqrt(s);
        if(s>=0){
            if(d==(int)d){
                d=(double)(0-b+(int)d)/(2*a);
                if(d==(int)d)
                    printf("%d\n", (int)d);
                else{
                    you(d);
                    printf("%d/%d\n", e, f);
                }
            }else{
                double q1=(0-(double)b)/(2*a), q2=1.0/(2*a);
                you(q1);
                printf("%lf %lf\n", q1, q2);
                if(q1!=0)printf("%d/%d+", e, f);
                if(q2==1)printf("sqrt(%d)\n", s);
                else if(zhe(q2))printf("%d*sqrt(%d)\n", q2, s);
                else if(zhe(1/q2))printf("sqrt(%d)/%d\n", s, (int)(1/q2), q2);
                else{
                    you(q2);
                    printf("%d*sqrt(%d)/%d\n", e, s, f);
                }
            }
        }else printf("NO\n");
    }
    return 0;
}
