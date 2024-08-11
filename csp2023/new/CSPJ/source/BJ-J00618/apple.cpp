#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,ans1,ans2;
bool flag=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int a[n+1];
    bool b[n+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        a[i]=i;
        b[i]=1;
    }
    for(int i=1;i<=n;i++){
        int k;
        k=a[1];
        while(k<=n&&a[k]!=0){
            a[k]=0;
            k+=3;
        }
        for(int j=1;j<=n;j++){
            if(a[j]!=0){
                flag=0;
                b[j]=0;
            }
            if(b[j]){
                a[i]=a[j];
            }
        }
        if(flag){
            ans1=i;
            break;
        }
        if(a[n]==0){
            ans2=i;
            break;
        }

    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
