#include<bits/stdc++.h>
using namespace std;
int n;
char a[100010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    }
    cin>>a;
    int sum=0;

    while(1){
    int f;
    f=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            if(i<n-2){
                if(a[i]==a[i+1]&&a[i]==a[i+2]) sum++;
            }
            f=1;
            sum++;
            for(int j=i;j<n-2;j++){
                a[j]=a[j+2];
            }
            n-=2;
        }
    }
    if(f==0) break;
    }
    if(n==0) sum++;
    cout<<sum;
return 0;
}
