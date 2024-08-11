#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c,dat,cyd,wyc,pfs[2505],cz,r;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    for(int i=1;i<=2500;++i){
        pfs[i]=i*i;
    }
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        dat=b*b-4*a*c;
        if(dat<0){
            printf("NO\n");
            continue;
        }
        if(dat==0){
            cyd=__gcd(a*2,b);

            if(abs(a*2/cyd)==1){
                if(a*2*b*-1>=0){
                    printf("%d",abs(b/cyd));
                }else{
                    printf("-%d",abs(b/cyd));
                }
            }else{
                if(a*2*b*-1>=0){
                    printf("%d/%d",abs(b/cyd),abs(a*2/cyd));
                }else{
                    printf("-%d/%d",abs(b/cyd),abs(a*2/cyd));
                }
            }
            printf("\n");
            continue;
        }

        for(int i=2500;i>=1;--i){
            if(dat%pfs[i]==0){
                wyc=i;
                break;
            }
        }
        //cout<<wyc<<endl;

        if(wyc*wyc==dat){
            if(a>0){
                b=-1*b;
                cyd=__gcd(a*2,b+wyc);
                if(b+wyc==0){
                    printf("0\n");
                    continue;
                }
                if(abs(a*2/cyd)==1){
                    if(a*2*(b+wyc)>0){
                        printf("%d",abs((b+wyc)/cyd));
                    }else{
                        printf("-%d",abs((b+wyc)/cyd));
                    }
                }else{
                    if(a*2*(b+wyc)>0){
                        printf("%d/%d",abs((b+wyc)/cyd),abs(a*2/cyd));
                    }else{
                        printf("-%d/%d",abs((b+wyc)/cyd),abs(a*2/cyd));
                    }
                }
                printf("\n");
                continue;
            }else{
                b=-1*b;
                cyd=__gcd(a*2,b-wyc);
                if(b-wyc==0){
                    printf("0\n");
                    continue;
                }
                if(abs(a*2/cyd)==1){
                    if(a*2*(b-wyc)>0){
                        printf("%d",abs((b-wyc)/cyd));
                    }else{
                        printf("-%d",abs((b-wyc)/cyd));
                    }
                }else{
                    if(a*2*(b-wyc)>0){
                        printf("%d/%d",abs((b-wyc)/cyd),abs(a*2/cyd));
                    }else{
                        printf("-%d/%d",abs((b-wyc)/cyd),abs(a*2/cyd));
                    }
                }
                printf("\n");
                continue;
            }

        }else{

            cyd=__gcd(a*2,b);
            if(b!=0){
                if(abs(a*2/cyd)==1){
                    if(a*2*b*-1>0){
                        printf("%d",abs(b/cyd));
                    }else{
                        printf("-%d",abs(b/cyd));
                    }
                }else{
                    if(a*2*b*-1>0){
                        printf("%d/%d",abs(b/cyd),abs(a*2/cyd));
                    }else{
                        printf("-%d/%d",abs(b/cyd),abs(a*2/cyd));
                    }
                }
                printf("+");
            }

            r=dat/wyc/wyc;
            cyd=__gcd(a*2,wyc);
            if(abs(a*2/cyd)==1){
                if(abs(wyc)/cyd==1){
                    printf("sqrt(%d)",r);
                }else{
                    printf("%d*sqrt(%d)",abs(wyc/cyd),r);
                }

            }else{
                if(abs(wyc)/cyd==1){
                    printf("sqrt(%d)/%d",r,abs(a*2/cyd));
                }else{
                    printf("%d*sqrt(%d)/%d",abs(wyc/cyd),r,abs(a*2/cyd));
                }


            }
            printf("\n");

        }



    }
    return 0;
}
