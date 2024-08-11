#include<bits/stdc++.h>
using namespace std;
struct lock{
    int a,b,c,d,e;
}l[10];
int a1,b1,c1,d1,e1,ans,num,n;
int roll(int a){
    ans=0;
    if(a==1){
        return 81;
    }
    a1=l[a].a;
    b1=l[a].b;
    c1=l[a].c;
    d1=l[a].d;
    e1=l[a].e;
    for(int i=1;i<=a-1;i++){
        if(l[i].a==a1&&l[i].b==b1&&l[i].c==c1&&l[i].d==d1&&l[i].e==e1){
            return roll(a-1);

        }
        for(int j=1;j<=a-1;j++){
            if(a==2){
            if(l[i].a!=a1&&l[i].b==b1&&l[i].c==c1&&l[i].d==d1&&l[i].e==e1){
                ans+=8;
                if(a==2){
                    ans+=2;
                }
                break;
            }else if(l[i].a==a1&&l[i].b!=b1&&l[i].c==c1&&l[i].d==d1&&l[i].e==e1){
                ans+=8;
                if(a==2){
                    ans+=2;
                }
                break;
            }else if(l[i].a==a1&&l[i].b==b1&&l[i].c!=c1&&l[i].d==d1&&l[i].e==e1){
                ans+=8;
                if(a==2){
                    ans+=2;
                }
                break;
            }else if(l[i].a==a1&&l[i].b==b1&&l[i].c==c1&&l[i].d!=d1&&l[i].e==e1){
                ans+=8;
                if(a==2){
                    ans+=2;
                }
                break;
            }else if(l[i].a==a1&&l[i].b==b1&&l[i].c==c1&&l[i].d==d1&&l[i].e!=e1){
                ans+=8;
                if(a==2){
                    ans+=2;
                }
                break;
            }else{
            }
            }else{
                ans+=10-n;
                return ans;
            }//one difference,roll 1 ring
            //one differences roll 2 ring
            //two difference
        }
    }
    return ans;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d",&l[i].a,&l[i].b,&l[i].c,&l[i].d,&l[i].e);
    }
     cout<<roll(n);
    return 0;
}