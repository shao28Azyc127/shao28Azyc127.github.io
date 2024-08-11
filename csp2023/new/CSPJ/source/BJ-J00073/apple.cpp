#include <iostream>
using namespace std;
int n, book[1000005], cnt=0, flag=0, ans=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(cnt<n){
        ans++;
		flag=0;
        for(int i=1;i<=n;i++){
            if(book[i]==0){
                if(flag==0) book[i]=ans, cnt++;
                flag++, flag%=3;
            }
        }
    }
    return printf("%d %d",ans,book[n])&0;
}