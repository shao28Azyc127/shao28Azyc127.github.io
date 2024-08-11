#include<bits/stdc++.h>
using namespace std;
unsigned long long n,ans;
char a[2000001];
void game(int m){
    char b[2000001];
    for(int i=1;i+m-1<=n;i++){
        int slay=0;
        for(int j=1;j<=n;j++){
            b[j]=a[j];
        }
        for(int j=i;j<=i+m-1;j++){
            while(b[j]==0&&j<i+m-1){
                j++;
            }
            int k=j+1;
            while(b[k]==0&&k<i+m-1){
                k++;
            }
            if(b[j]==b[k]){
                slay++;
                if(slay==m/2){
                    ans++;
                    break;
                }
                b[j]=0;
                b[k]=0;
                j=i;
            }
        }
    }
    if(m+2<=n){
        game(m+2);
    }
    return;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    game(2);
    cout<<ans;
    return 0;
}
