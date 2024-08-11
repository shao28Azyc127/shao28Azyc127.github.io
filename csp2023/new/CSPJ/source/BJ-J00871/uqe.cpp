#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
int is(int x){
    if((int)(sqrt(x))*(int)(sqrt(x))==x){
        return 1;
    }
    return 0;
}
int hs(int x){
    int ans=1;
    for(int i=2;i*i<=x;i++){
        if(x%(i*i)==0){
            ans*=i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        int x=b*b-4*a*c,cnt1,cnt2;
        if(x<0){
            cout<<"No"<<endl;
            continue;
        }
        cnt1=(-b+sqrt(x))/(2*a);
        cnt2=(-b-sqrt(x))/(2*a);
        if(cnt1>=cnt2){
            if(is(x)==1){
                int q=sqrt(x)-b,w=2*a,e=gcd(q,w);
                if(w/e==1){
                    printf("%d\n",q/e);
                }else{
                    if(w/e<0){
                        printf("%d/%d\n",(-q)/e,(-w)/e);
                    }else{
                        printf("%d/%d\n",q/e,w/e);
                    }
                }
            }else{
                int q=-b,w=2*a;
                if(q!=0){
                    int e=gcd(q,w);
                    if(w/e==1){
                        printf("%d+",q/e);
                    }else{
                        if(w/e<0){
                            printf("%d/%d+",(-q)/e,(-w)/e);
                        }else{
                            printf("%d/%d+",q/e,w/e);
                        }
                    }
                }
                int r=hs(x),s=x/hs(x)/hs(x),t=gcd(r,w);
                if(r/t==1){
                    if(w/t==1){
                        printf("sqrt(%d)\n",s);
                    }else{
                        printf("sqrt(%d)/%d\n",s,w/t);
                    }
                }else{
                    if(w/t==1){
                        printf("%d*sqrt(%d)\n",r/t,s);
                    }else{
                        printf("%d*sqrt(%d)/%d\n",r/t,s,w/t);
                    }
                }
            }
        }else{
            if(is(x)==1){
                int q=-sqrt(x)-b,w=2*a,e=gcd(q,w);
                if(w/e==1){
                    printf("%d\n",q/e);
                }else{
                    if(w/e<0){
                        printf("%d/%d\n",(-q)/e,(-w)/e);
                    }else{
                        printf("%d/%d\n",q/e,w/e);
                    }
                }
            }else{
                int q=-b,w=2*a;
                if(q!=0){
                    int e=gcd(q,w);
                    if(w/e==1){
                        printf("%d+",q/e);
                    }else{
                        if(w/e<0){
                            printf("%d/%d+",(-q)/e,(-w)/e);
                        }else{
                            printf("%d/%d+",q/e,w/e);
                        }
                    }
                }
                int r=-hs(x),s=-x/hs(x)/hs(x),t=gcd(r,w);
                if(r/t==1){
                    if(w/t==1){
                        printf("sqrt(%d)\n",s);
                    }else{
                        printf("sqrt(%d)/%d\n",s,w/t);
                    }
                }else{
                    if(w/t==1){
                        printf("%d*sqrt(%d)\n",r/t,s);
                    }else{
                        printf("%d*sqrt(%d)/%d\n",r/t,s,w/t);
                    }
                }
            }
        }
    }
    return 0;
}
