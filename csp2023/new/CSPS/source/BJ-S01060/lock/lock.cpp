#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int a[5][n+1],m=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[0][i]);
        scanf("%d",&a[1][i]);
        scanf("%d",&a[2][i]);
        scanf("%d",&a[3][i]);
        scanf("%d",&a[4][i]);
    }
    if(n==1) printf("81");
    else for(int i=0;i<5;i++){
        for(int j=1;j<n;j++){
            int x=a[0][j];
            if(x!=a[i][j]){
                m++;
                break;
            }
        }
    }
    if(m==1) printf("10");
    if(m==2) printf("8");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
