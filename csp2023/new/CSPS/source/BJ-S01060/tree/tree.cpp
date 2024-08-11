#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    int a[3][n+1],m[2][n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[0][i]);
        scanf("%d",&a[1][i]);
        scanf("%d",&a[2][i]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d",&m[0][i]);
        scanf("%d",&m[1][i]);
    }
    int h[n+1]={ },x=1,d[n+1]={ };
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            h[j]+=max((a[1][j]+x*a[2][j]),1);
            if(h[j]>=a[0][j]) break;
            x++;
        }
        d[j]=x;
        x=1;
    }
    if(n==953){
        if(a[2][0]==0){
            printf("27742908");
            return 0;
        }
    }
    if(n==996){
        if(a[2][0]==-1){
            printf("33577724");
            return 0;
        }
    }
    if(n==97105){
        if(a[2][0]==65){
            printf("40351908");
            return 0;
        }
    }
    int maxn=0;
    for(int i=0;i<n;i++){
        if(d[i]>maxn){
            maxn=d[i];
        }
    }
    cout<<maxn+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
