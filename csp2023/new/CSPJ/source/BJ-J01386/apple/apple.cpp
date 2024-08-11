#include <iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=2,a[100005],day=0,ans2;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    while(1){
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                flag=1;
                break;
            }else{
                continue;
            }
        }
        if(flag==1){
            day++;
            cnt=2;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    continue;
                }else{
                    if(cnt==2){
                        if(i==n){
                            ans2=day;
                        }else{
                            a[i]=0;
                            cnt=0;
                        }
                    }else{
                        cnt++;
                    }
                }
            }
        }else{
            break;
        }
    }
    cout<<day<<" "<<ans2;
    return 0;
}