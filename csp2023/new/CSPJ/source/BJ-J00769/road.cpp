#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,a[100010][2],now=1,ans=0;
double nowl=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;i++)scanf("%d",&a[i][0]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i][1]);
    while(now<n){
        int i=now+1;
        double S=a[i][0];
        while(a[i][1]>a[now][1]&&i<=n){
            S+=a[i+1][0];
            i++;
        }
        S=max((double)a[now+1][0],S);
        int L=ceil((double)((double)S-nowl*(double)d)/(double)d);
        ans+=L*a[now][1];
        now=i;
        nowl+=L;
        nowl-=S/(double)d;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
