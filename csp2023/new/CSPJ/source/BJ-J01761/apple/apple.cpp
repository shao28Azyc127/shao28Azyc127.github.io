#include <iostream>
#include <cstdlib>
using namespace std;

bool arr[1000005];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,time=0,ans;
    bool flag=true;
    cin>>n;
    int cur=1;
    while(cnt<n){
        for(int i=0;i<2;i++){
            while(cur<=n && arr[cur] && !flag) ++cur;
            if(!flag) ++cur;
        }while(cur<=n && arr[cur]) ++cur;
        if(cur<=n){
            flag=false;
            ++cnt;//cout<<cur<<endl;
            if(cur==n) ans=time+1;
            arr[cur]=true;
        }else{
            cur=1;
            ++time;
            flag=true;
        }
    }cout<<time+1<<' '<<ans;
    return 0;
}
