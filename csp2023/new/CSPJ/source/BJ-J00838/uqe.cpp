#include<cstdio>
#include<cmath>
using namespace std;
const int MAXM=1e3+5;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    freopen("uqe1.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m,a,b,c,tri,root,p,q,g,rt;
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        tri=b*b-4*a*c;
        //no answer
        if(tri<0)printf("NO");
        //have answer
        else{
            root=sqrt(tri);
            //able to be p/q
            if(root*root==tri){
                p=-b+root,q=2*a;
                g=gcd(p,q);
                p/=g,q/=g;
                if(q<0)p=-p,q=-q;
                if(q==1)printf("%d",p);
                else printf("%d/%d",p,q);
            }
            //unable to be p/q
            else{
                //part1
                p=-b,q=2*a;
                g=gcd(p,q);
                p/=g,q/=g;
                if(q<0){
                    p=-p;
                    q=-q;
                }
                if(p!=0){
                    if(q==1)printf("%d",p);
                    else printf("%d/%d",p,q);
                    printf("+");
                }
                //part2
                rt=2,q=2*a;
                while(!((tri%rt==0)&&(sqrt(tri/rt)*sqrt(tri/rt)==tri/rt)))rt++;
                p=sqrt(tri/rt);
                g=gcd(p,q);
                p/=g,q/=g;
                if(q<0){
                    p=-p;
                    q=-q;
                }
                if(p==1&&q==1)printf("sqrt\(%d\)",rt);
                else if(p==1)printf("sqrt\(%d\)/%d",rt,q);
                else if(q==1)printf("%d*sqrt\(%d\)",p,rt);
                else printf("%d*sqrt\(%d\)/%d",p,rt,q);
            }
        }
        printf("\n");
    }
    return 0;
}
