#include<bits/stdc++.h>
using namespace std;
int n,ans;
int m[1000000];
void cha(int a,int b,int c,int d,int f){
    int cnt=0;
    cnt=a*10000+b*1000+c*100+d*10+f;
    m[cnt]++;
    if(m[cnt]==n){
        ans++;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    //printf("%d",n);
    for(int i=1;i<=n;i++){
        int a,b,c,d,f;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&f);
        int cnt=a*10000+b*1000+c*100+d*10+f;
        m[cnt]=-1;
        for(int j=1;j<=9;j++){
            int a2=a;
            a2=(a+j)%10;
            int b2=b;
            b2=(b+j)%10;
            int c2=c;
            c2=(c+j)%10;
            int d2=d;
            d2=(d+j)%10;
            int f2=f;
            f2=(f+j)%10;
            cha(a2,b,c,d,f);
            cha(a,b2,c,d,f);
            cha(a,b,c2,d,f);
            cha(a,b,c,d2,f);
            cha(a,b,c,d,f2);
            cha(a2,b2,c,d,f);
            cha(a,b2,c2,d,f);
            cha(a,b,c2,d2,f);
            cha(a,b,c,d2,f2);
        }
    }
    printf("%d",ans);
    return 0;
}