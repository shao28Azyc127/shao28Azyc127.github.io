#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100010],b[100010],c[100010],h[100010];
bool ans[100010];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=n-1;i++){
        int k;
        scanf("%d",&k);
    }
    int i=1,in=n;
    while(in){
        for(int j=1;j<=min(i,n);j++){
            if(!ans[j])h[j]+=max(1,b[j]+i*c[j]);
            if(h[j]>=a[j]&&!ans[j]){
                ans[j]=1;
                in--;
            }
        }
        i++;
    }
    printf("%d",i-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
