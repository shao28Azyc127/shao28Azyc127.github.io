#include<bits/stdc++.h>
using namespace std;
int n;
int a[9][6];
int b[6];
bool f[6];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
            if(i==1){
                b[j]=a[i][j];
            }
            if(a[i][j]!=a[i][j-1]){
                f[j]=true;
            }
        }
    }
    if(n==1){
        printf("81");
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(b[j]!=a[i][j]){
                b[j]=-1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(b[i]==-1){
            cnt++;
        }
    }
    for(int i=2;i<=5;i++){
        if(b[i]==-1&&b[i-1]==-1&&f[i]==false){
            cnt--;
        }
    }
    if(cnt!=1){
        cout<<0;
        return 0;
    }
    cout<<10;
}
