#include<bits/stdc++.h>
using namespace std;
int T,m;
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
struct node{
    int p,q;
};
node chan(node x){
    int o=gcd(x.p,x.q);
    x.p/=o,x.q/=o;
    return x;
}
int eas(int x){
    if(x==0)return x;
    int ans=1;
    for(int i=2;i<=sqrt(x);i++)
        while(x>0&&x%(i*i)==0){
            x/=(i*i);
            ans*=i;
        }
    return ans;
}
void print(node x){
    if(x.q<0)x.q=-x.q,x.p=-x.p;
    if(x.q==1){
        printf("%d",x.p);
    }else{
        printf("%d/%d",x.p,x.q);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&m);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b*b<4*a*c)printf("NO");
        else{
            int k=b*b-4*a*c;
            int l=eas(k);
            if(a<0)l=-l;
            if(l*l==k){
                l-=b;
                node t={l,2*a};
                print(chan(t));
            }else{
                k/=(l*l);
                if(b!=0){
                    node t1=chan({-b,2*a});
                    print(t1);
                    printf("+");
                }
                node t=chan({l,2*a});
                if(t.p==1&&t.q==1)
                    printf("sqrt(%d)",k);
                else if(t.q==1)
                    printf("%d*sqrt(%d)",t.p,k);
                else if(t.p==1)
                    printf("sqrt(%d)/%d",k,t.q);
                else
                    printf("%d*sqrt(%d)/%d",t.p,k,t.q);
            }
        }
        printf("\n");
    }
    return 0;
}
