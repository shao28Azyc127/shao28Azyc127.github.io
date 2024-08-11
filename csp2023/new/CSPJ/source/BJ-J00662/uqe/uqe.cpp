#include <bits/stdc++.h>
using namespace std;
int t,m,ans1,ans2,ans;
bool f[100005]={};
void zhi(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(!f[i]){
            f[i]=1;
            for(int j=2;j*i<=n;j++){
                f[i*j]=1;
            }
        }
    }
}
bool Q(int a){
    double b=sqrt(a);
    if(b==sqrt(a))
        return 1;
    return 0;
}
bool Z(int a,int b){
    double c=a;
    c/=b;
    a/=b;
    return c==a;
}
int p,q=1;
void li(int a){
    p=1;
    for(int i=a-1;i>=2;i--){
        if(a/i*i==0){
            p*=i;
        }
    }
    q=a/p;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    zhi(m);
    for(int ii=0;ii<t;ii++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b*b-4*a*c==0){
            printf("0\n");
        }
        else if(b*b-4*a*c>0){
            if(c==0){
                ans1=0;
                ans2=b*-1;
                printf("%d\n",max(ans1,ans2));
            }
            if(b==0){
                c*=-1;
                ans1=sqrt(c);
                ans2=sqrt(c)*-1;
                ans=max(ans1,ans2);
                double a=max(sqrt(c),sqrt(c)*-1);
                if(a==ans){
                    printf("%d\n",ans);
                }
                else{
                    printf("s");
                    printf("qrt");
                    cout<<"("<<c<<")"<<endl;
                }
            }
            else{
                int d=b*b-4*a*c;
                int e=2*a;
                if(Q(b*b-4*a*c)){
                    if(Z(d-b,e)){
                        printf("%d",(d-b)/e);
                    }
                    else{
                        li(d);
                        if(!Z(p,e)&&0){
                            int j=1;
                            for(int i=max(p,e);i>0;i--){
                                if(p%i==0&&e%i==0){
                                    j=i;
                                    break;
                                }
                            }
                            int k=1;
                            for(int i=max(b,e);i>0;i--){
                                if(b%i==0&&e%i==0){
                                    k=i;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            printf("No");
        }
    }
    return 0;
}
