#include<cstdio>
using namespace std;
const int N=15;
int n,stat[N][6],mp[N][N][N][N][N],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&stat[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)
            for(int pt=1;pt<=9;pt++){
                int c[N];
                for(int tt=1;tt<=5;tt++)c[tt]=stat[i][tt];
                c[j]=(c[j]+pt)%10;
                mp[c[1]][c[2]][c[3]][c[4]][c[5]]++;
            }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++)
            for(int pt=1;pt<=9;pt++){
                int c[N];
                for(int tt=1;tt<=5;tt++)c[tt]=stat[i][tt];
                c[j]=(c[j]+pt)%10;
                c[j+1]=(c[j+1]+pt)%10;
                mp[c[1]][c[2]][c[3]][c[4]][c[5]]++;
            }
    }
    for(int i1=0;i1<=9;i1++)
        for(int i2=0;i2<=9;i2++)
            for(int i3=0;i3<=9;i3++)
                for(int i4=0;i4<=9;i4++)
                    for(int i5=0;i5<=9;i5++)
                        if(mp[i1][i2][i3][i4][i5]==n)
                            ans++;
    printf("%d\n",ans);
    return 0;
}
//Workingmen of all countries, unite!
