#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool a[100010];
int n,b[10],ans=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,p=0;
        for(int j=0;j<5;j++){
            scanf("%d",&x);
            p+=x*pow(10,j);
        }
        b[i]=p;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            int k=(b[1]/(int)pow(10,i-1))%10+j;
            if(k>=10)k-=10;
            a[b[1]-(b[1]/(int)pow(10,i-1)%10)*(int)pow(10,i-1)+k*(int)pow(10,i-1)]=1;
            ans++;
        }

    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
            int k=(b[1]/(int)pow(10,i-1))%100+j*10;
            if(k>=100)k-=100;
            int k1=k+j;
            if(k1%10<k%10)k1-=10;
            a[b[1]-(b[1]/(int)pow(10,i-1)%100)*(int)pow(10,i-1)+k1*(int)pow(10,i-1)]=1;
            ans++;
        }
    }
    for(int t=2;t<=n;t++){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=9;j++){
                int k=(b[t]/(int)pow(10,i-1))%10+j;
                if(k>=10)k-=10;
                int x=b[t]-(b[t]/(int)pow(10,i-1)%10)*(int)pow(10,i-1)+k*(int)pow(10,i-1);
                if(!a[x])ans--;
            }
        }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=9;j++){
                int k=(b[t]/(int)pow(10,i-1))%100+j*10;
                if(k>=100)k-=100;
                int k1=k+j;
                if(k1%10<k%10)k1-=10;
                int x=b[t]-(b[t]/(int)pow(10,i-1)%100)*(int)pow(10,i-1)+k1*(int)pow(10,i-1);
                if(!a[x])ans--;
            }
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
