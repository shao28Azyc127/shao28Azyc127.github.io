#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6+2;
int n,a[10][10],st[10][N],f[6],cnt[10];
bool alls[9][M],ok[N];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);int m=5;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    f[1]=1;

    for(int i=2;i<=5;i++) f[i]=f[i-1]*10;
    for(int i=1;i<=n;i++){
        int fir=0;
        for(int p=1;p<=5;p++) fir+=a[i][p]*f[p];
        for(int p=1;p<=5;p++){
            for(int k=0;k<=9;k++)
                if(a[i][p]!=k) st[i][++cnt[i]]=fir-a[i][p]*f[p]+k*f[p];
        }
        for(int p=1;p<=4;p++){
            for(int k=1;k<=9;k++){
                int nw1=(a[i][p]+k)%10,nw2=(a[i][p+1]+k)%10;
                st[i][++cnt[i]]=fir-a[i][p]*f[p]+nw1*f[p]-a[i][p+1]*f[p+1]+nw2*f[p+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        //sort(a[i]+1,a[i]+cnt[i]+1);
        //cnt[i]=unique(a[i]+1,a[i]+cnt[i]+1)-a[i]-1;
        for(int j=1;j<=cnt[i];j++)
            alls[i][st[i][j]]=1;
    }
    int cnt=0;
    for(int i=0;i<=M;i++){
        bool flag=1;//int cn=0;
        for(int j=1;j<=n;j++)
            if(!alls[j][i]){
                flag=0;
                break;
            }
        if(flag) cnt++;
        //if(alls[1][i]&&!flag) printf("%d\n",i);
    }
    printf("%d",cnt);
    return 0;
}
