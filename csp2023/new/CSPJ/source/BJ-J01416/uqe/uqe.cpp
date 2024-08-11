#include<bits/stdc++.h>
using namespace std;
int t, m;
int sq[1010];
int gcd(int x,int y){
    if(x%y==0){
        return y;
    }
    else{
        return gcd(y,x%y);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d", &t, &m);
    for(int i=1;i<=m;i++){
        sq[i]=i*i;
    }
    for(int i=1;i<=t;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int del=b*b-4*a*c;
        a=a*2;
        b=b*-1;
        if(del<0){
            printf("NO\n");
            continue;
        }
        if(del==0){
            if(b==0){
                printf("0\n");
                continue;
            }
            if(b%a==0){
                if(a==1){
                    printf("%d\n", b);
                    continue;
                }
                else{
                    printf("%d\n",b/a);
                    continue;
                }
            }
            else{
                int bb=abs(b);
                int aa=abs(a);
                int g;
                if(bb>aa) g=gcd(bb,aa);
                else g=gcd(aa,bb);
                a=a/g;
                a=b/g;
                if(a<0&&b>0){
                    printf("%d/%d\n", -1*b, -1*a);
                }
                else{
                    printf("%d/%d", b, a);
                }
            }
        }
        if(del>0){
            int r=1;
            for(int i=1;i<=m;i++){
                if(del%sq[i]==0){
                    r=r*i;
                    del=del/sq[i];
                }
                if(del==1) break;

            }
            if(del==1){
                int k=b+r;
                if(k%a==0){
                    if(a==1){
                        printf("%d\n", k);
                        continue;
                    }
                    else{
                        printf("%d\n", k/a);
                        continue;
                    }
                }
                else{
                    int kk=abs(k);
                    int aa=abs(a);
                    int g;
                    if(kk>aa) g=gcd(kk,aa);
                    else g=gcd(aa,kk);
                    a=a/g;
                    k=k/g;
                    printf("%d/%d\n", k, a);
                    continue;
                }
            }
            else{
                if(b%a==0){
                    if(a==1&&b!=0){
                        printf("%d+", b);
                    }
                    else{
                        printf("%d+", b/a);
                    }
                }
                else{
                        if(r%a!=0){
                            int bb=abs(b);
                    int aa=abs(a);
                    int g;
                    if(bb>aa) g=gcd(bb,aa);
                    else g=gcd(aa,bb);
                    a=a/g;
                    b=b/g;
                    printf("%d/%d+", b, a);
                        }

                }
                if(r%a==0){
                        if(r/a==1){
                            printf("sqrt(%d)\n", del);
                            continue;
                        }
                        else{
                            printf("%d*sqrt(%d)\n", r/a, del);
                            continue;
                        }

                }
                else{
                    int rr=abs(r);
                    int aa=abs(a);
                    int g;
                    if(rr>aa) g=gcd(rr,aa);
                    else g=gcd(aa,rr);
                    a=a/g;
                    r=r/g;
                    if(r==1){
                        printf("sqrt(%d)/%d\n", del, a);
                    continue;
                    }
                    else{
                        printf("%d*sqrt(%d)/%d\n", r, del, a);
                    continue;
                    }
                }
            }
        }
    }
    return 0;
}
