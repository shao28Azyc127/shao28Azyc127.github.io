#include <iostream>

using namespace std;
int a[100][10],ans=0,b[10];
 int n;
int f(){
    for(int i=2;i<=n;i++){
        int z=0;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=b[j])z++;
        }
        if(z!=1){
            if(z!=2)return 0;
            z=0;
            for(int j=1;j<5;j++){
                if(a[i][j]!=b[j]&&(a[i][j+1]-b[j+1])==(a[i][j]-b[j]))z++;
            }
            if(z!=1)return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
    }
    int ans=0;
    for(int i=1;i<=5;i++){
        b[i]=a[1][i]+1;
        for(int j=1;j<=9;j++){
           if(f()){
            ans++;
           }
        b[i]++;
        b[i]%=10;
        }
    }
    for(int i=1;i<5;i++){
        b[i]=a[1][i]+1;
        b[i+1]=a[1][i+1]+1;
        for(int j=1;j<=9;j++){
           if(f()){
            ans++;
           }
            b[i]++;
            b[i]%=10;
            b[i+1]++;
            b[i+1]%=10;
        }
    }
    cout<<ans;
    return 0;
}
