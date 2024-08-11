#include<iostream>
using namespace std;
int book[1000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t,ans,cnt;
    bool flag;
    cin>>n;
    for(t=1;;t++){
        cnt=0;
        flag=true;
        for(int i=1;i<=n;i++){
            if(!book[i]){
                flag=false;
                if(cnt==3){
                    cnt=0;
                }
                if(!cnt){
                    book[i]=true;
                    if(i==n){
                        ans=t;
                    }
                }
                cnt++;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<t-1<<' '<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
