#include <bits/stdc++.h>
using namespace std;
bool wuli(double c){
    if(c-int(c)!=0){
        return true;
    }
    return false;
}
void prt(int a,int b,int deerta){
    int q2=1;
    a*=2;
    int a1=a;
    int gcdab=__gcd(a1,b);
    a1/=gcdab;
    b/=gcdab;
    b=-1*b;
    if(b%a1==0&&b!=0){
        printf("%d+",b/a1);
    }
    else if(b!=0){
        printf("%d/%d+",b,a1);
    }
    for(int i=2;i<=sqrt(deerta);i++){
        if(deerta%i!=0){
            continue;
        }
        else{
            int j=deerta/i;
            if(wuli(sqrt(i))==false){
                deerta/=i;
                q2*=sqrt(i);
                i=1;
            }
            if(wuli(sqrt(j))==false){
                deerta/=j;
                q2*=sqrt(j);
                i=1;
            }
        }
    }
    int gcdaq=__gcd(q2,a);
    q2/=gcdaq;
    a/=gcdaq;
    if(q2<0){
        q2=-q2;
    }
    if(a<0){
        a=-a;
    }
    if(q2==1&&a==1){
        //cout<<"sqrt("<<deerta<<")";
        //printf("\n");
        printf("sqrt(%d)\n",deerta);
    }
    else if(q2==1){
        //cout<<"sqrt("<<deerta<<")/"<<a;
        //printf("\n");
        printf("sqrt(%d)/%d\n",deerta,a);
    }
    else if(a==1){
        //cout<<q2<<"*sqrt("<<deerta<<")";
        //printf("\n");
        printf("%d*sqrt(%d)\n",q2,deerta);
    }
    else{
        //cout<<q2<<"*sqrt("<<deerta<<")/"<<a;
        //printf("\n");
        printf("%d*sqrt(%d)/%d\n",q2,deerta,a);
    }
    return ;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d %d",&t,&m);
    for(int i=1;i<=t;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int deerta=b*b-4*a*c;
        double ddd=sqrt(deerta);
        if(deerta>=0){
            if(wuli(ddd)){
                prt(a,b,deerta);
            }
            else{
                if(-b==0){
                    printf("0\n");
                }
                else{
                    a*=2;
                    b=-b;
                    b+=ddd;
                    int gcdab=__gcd(a,b);
                    a/=gcdab;
                    b/=gcdab;
                    if(a>0&&b<0&&b%a!=0){
                        a=-a;
                        b=-b;
                    }
                    if(a<0&&b<0){
                        a=-a;
                        b=-b;
                    }
                    if(b%a==0){
                        printf("%d\n",b);
                        continue;
                    }
                    cout<<b<<"/"<<a;
                    printf("\n");
                    //printf("%d/%d\n",b,2*a);
                }
            }
        }
        if(deerta<0){
            printf("NO\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}