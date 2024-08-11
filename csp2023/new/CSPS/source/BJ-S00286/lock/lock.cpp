#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],b[10],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    for(int num=0;num<=99999;num++){
        int num1=num,check=1;
        for(int i=1;i<=5;i++) b[i]=num1%10,num1/=10;
        for(int i=1;i<=n;i++){
            int c[10],ok=0;
            for(int j=1;j<=5;j++) c[j]=(a[i][j]-b[j]+10)%10;
            for(int j=1;j<=5;j++){
                int flag=0;
                for(int k=1;k<=5;k++)
                    if(j!=k)
                        flag|=c[k];
                if(!flag&&c[j]){ok=1;break;}
            }
            if(ok) continue;
            for(int j=2;j<=5;j++){
                int flag=0;
                for(int k=1;k<=5;k++)
                    if(j!=k&&(j-1)!=k)
                        flag|=c[k];
                if(!flag&&c[j]==c[j-1]&&c[j]){ok=1;break;}
            }
            if(!ok) {check=0;break;}
        }
        ans+=check;
    }
    printf("%d",ans);
    return 0;
}
