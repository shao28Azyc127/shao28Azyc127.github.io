#include <bits/stdc++.h>
using namespace std;
int delta (int a,int b,int c){
    int d=b*b-4*a*c;
    return d;
}
int gcd (int a,int b){
    a=abs(a);
    b=abs(b);
    if (b==0){
        return a;
    }
    if (b==1){
        return 1;
    }
    return gcd(b,a%b);
}
int sqrt_ (int a){
    for (int i=sqrt(a);i>0;i--){
        if (a%(i*i)==0){
            return i;
        }
    }
}
int main (){
    freopen ("uqe.in","r",stdin);
    freopen ("uqe.out","w",stdout);
    int t,m;
    int a,b,c;
    scanf ("%d%d",&t,&m);
    for (int i=0;i<t;i++){
        scanf ("%d%d%d",&a,&b,&c);
        int d=delta(a,b,c);
        if (d<0){
            printf ("NO\n");
        }else{
            int s=sqrt(d);
            if (s*s==d){
                int f=-1*b+sqrt(d);
                int e=gcd(2*a,f);
                e=abs(e);
                if (2*a==e){
                    //printf ("@1 %d %d %d %d\n",a,b,d,e);
                    printf ("%d\n",f/e);
                }else{
                    if (-2*a==e){
                        printf ("%d\n",-1*f/e);
                    }else{
                        //printf ("@2 %d %d %d %d\n",a,b,d,e);
                        if (a<0){
                            printf ("%d/%d\n",-1*f/e,a*-2/e);
                        }else{
                            printf ("%d/%d\n",f/e,a*2/e);
                        }
                    }
                }
            }else{
                if (b!=0){
                    int e=gcd(2*a,b);
                    e=abs(e);
                    if (2*a==e){
                        //printf ("@3 %d %d %d\n",a,b,e);
                        printf ("%d+",-1*b/e);
                    }else{
                        if (-2*a==e){
                            printf ("%d+",b/e);
                        }else{
                            //printf ("@4 %d %d %d\n",a,b,e);
                            if (a<0){
                                printf ("%d/%d+",b/e,a*-2/e);
                            }else{
                                printf ("%d/%d+",-1*b/e,a*2/e);
                            }
                        }
                    }
                }
                int f=sqrt_(d);
                int e=gcd(2*a,f);
                e=abs(e);
                if (f==a*2||f==a*-2){
                    //printf ("@5 %d %d %d\n",a,d,f);
                    printf ("sqrt(%d)\n",d/f/f);
                }else{
                    if (e==a*2||e==a*-2){
                        //printf ("@6 %d %d %d %d\n",a,d,e,f);
                        printf ("%d*sqrt(%d)\n",f/e,d/f/f);
                    }else{
                        if (f==e){
                            //printf ("@7 %d %d %d %d\n",a,d,e,f);
                            printf ("sqrt(%d)/%d\n",d/f/f,abs(a*2/e));
                        }else{
                            //printf ("@8 %d %d %d %d\n",a,d,e,f);
                            printf ("%d*sqrt(%d)/%d\n",f/e,d/f/f,abs(a*2/e));
                        }
                    }
                }
            }
            /*if (b!=0){
                int e=gcd(2*a,b);
                printf ("%d/%d+",-1*b/e,2*a/e);
            }*/

        }
    }
    return 0;
}
