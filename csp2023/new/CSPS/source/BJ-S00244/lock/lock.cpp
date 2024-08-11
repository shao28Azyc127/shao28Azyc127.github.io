#include<cstdio>
using namespace std;
int n,ans,a[7],b[7],f[12][12][12][12][12][10];
bool mark;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
        for(int i=1;i<6;i++)scanf("%d",&a[i]);
        for(int i=1;i<6;i++){
            for(int j=1;j<6;j++){
                for(int k=1;k<6;k++)b[k]=a[k];
                for(int k=1;k<10;k++){
                    b[i]++,b[i]%=10;
                    if(j-i==1||i-j==1)b[j]++,b[j]%=10;
                    f[b[1]][b[2]][b[3]][b[4]][b[5]][t]=true;
                }
            }
        }
    }
    for(int i1=0;i1<10;i1++)
    for(int i2=0;i2<10;i2++)
    for(int i3=0;i3<10;i3++)
    for(int i4=0;i4<10;i4++)
    for(int i5=0;i5<10;i5++){
        mark=true;
        for(int j=1;j<=n;j++){
            if(!f[i1][i2][i3][i4][i5][j]){
                mark=false;
                break;
            }
        }
        if(mark)ans++;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
