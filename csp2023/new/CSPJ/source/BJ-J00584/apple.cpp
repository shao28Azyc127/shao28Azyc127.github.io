#include <iostream>
#include <cmath>
using namespace std;
int a[100000005]={};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.ans","w",stdout);
    int n,ans=0,cnt=0,m=0;;
    cin>>n;
    a[0]=-1;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=1;i<=n;i++){
        m=i;
        for(int j=1;j<=n;j++){
            if(a[4]==-1){
                m+=3;
                for(int k=1;k<=3;k++){
                    a[k]=-1;
                }
                break;
            }
            if(j%3==1&&a[j]!=-1){
                if(a[j]==n){
                    ans=m;
                }
                a[j]=-1;
            }

        }
        for(int j=1;j<=n;j++){
            if(a[j]==-1){
                cnt++;
            }
            if(cnt==n){
                cout<<m<<" "<<ans;
                return 0;
            }

        }
        cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]==-1){
                for(int k=j;k<=n;k++){
                    if(a[k]!=-1){
                        a[j]=a[k];
                        a[k]=-1;
                        break;
                    }
                }
            }
        }

    }
    return 0;
}
