#include<iostream>
#include<cstdio>
using namespace std;
int out=0,n,m,i;
bool a[10000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(i=0;out<n;){
        i++;
        for(int j=i;j<=n;){
            while(a[j]&&j<n)j++;
            if(j>n)break;
            int in=0;
            if(j==n)m=i;
            a[j]=1;out++;
            while(in<=2&&j<=n){
                j++;
                if(!a[j])in++;
            }
        }
    }
    printf("%d %d",i,m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
