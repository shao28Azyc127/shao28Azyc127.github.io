#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt,res=0;
    int r[1000005],ans[1000005];
    cin>>n;
    cnt=n;
    for(long long i=1;i<=n;i++){
        r[i]=0;
        if(cnt%3==0){
            r[i]=cnt/3;
        }else if(cnt%3==1){
            r[i]=(cnt+2)/3;
        }else if(cnt%3==2){
            r[i]=(cnt+1)/3;
        }
        cnt-=r[i];
        res++;
        if(cnt==0) break;
    }
    cnt=n;
    cout<<res<<" "<<"1"<<endl;
    return 0;
}
