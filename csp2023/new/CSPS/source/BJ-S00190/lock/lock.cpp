#include<iostream>
#include<fstream>
#include<map>
using namespace std;
int n;
int a[10][6],num[10];
map<int,bool> m[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
        for(int j=1;j<=5;j++)
            for(int k=0;k<10;k++)
                if(k!=a[i][j]){
                    int num=0;
                    for(int l=1;l<=5;l++)
                        if(l!=j)num=num*10+a[i][l];
                        else num=num*10+k;
                    m[i][num]=1;
                }
        for(int j=1;j<5;j++)
            for(int k=1;k<10;k++){
                int num=0;
                for(int l=1;l<=5;l++)
                    if(l!=j&&l!=j+1)num=num*10+a[i][l];
                    else num=num*10+(a[i][l]+k)%10;
                m[i][num]=1;
            }
    }
    int ans=0;
    for(int i=0;i<=99999;i++){
        bool flag=0;
        for(int j=1;j<=n;j++)
            if(!m[j][i]){
                flag=1;
                break;
            }
        if(!flag){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
