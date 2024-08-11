#include<bits/stdc++.h>
using namespace std;
int n,a[100000][6],s,tmp;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    int k=2,ans=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++){
            cin>>a[j][i];
        }
        int x=j;
        while(true){
            if(a[x][1]==9&&a[x][2]==9&&a[x][3]==9&&a[x][4]==9&&a[x][5]==9&&){
                break;
            }
            for(int i=1;i<=5;i++){
                for(int w=0;w<=9;w++){
                    if(w!=a[x][i]){
                        a[w][i]++;
                    }
                }
            }
            k++;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++){
                if(a[i][j]==a[i+1][j+1]){
                    ans++;
                }
        }
    }
    cout<<ans;
    return 0;
}
