#include <iostream>
using namespace std;
int n,cnt,tmp,ans,ansn;
bool a[1000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cnt=3;
    cin >> n;
    while (tmp!=n){
        cnt=2;
        for (int i=1;i<=n;i++){
            if (!a[i]){
                cnt++;
            }
            if (cnt==3){
                a[i]=true;
                cnt=0;
                tmp++;
                if (i==n) ansn=ans;
            }
        }
        ans++;
    }
    cout << ans << " " << ansn+1 << endl;
    return 0;
}
