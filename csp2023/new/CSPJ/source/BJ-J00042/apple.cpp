include <iostream>
#include <fstream>
using namespace std;
bool f(int a[],int n){
    for(int k=1;k<=n;k++){
        if(a[k]!=0)return false;
        if(k==n){
            return true;
        }
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=3,a[1500000],ans1=-1,ans2=-1;
    bool con=false;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==0){
                if(j==n&&!con){
                    ans2=i-1;
                    con=true;
                }

                continue;
            }else{


                if(cnt>=3){
                cnt=1;
                a[j]=0;
                }else{cnt++;}
            }

        }


        if(f(a,n)){
            ans1=i;
            if(ans2==-1){
                ans2=ans1;
            }
            cout<<ans1<<' '<<ans2;
            return 0;
        }
        cnt=3;
    }

    return 0;
}