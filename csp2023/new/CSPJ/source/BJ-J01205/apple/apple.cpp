#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
bool a[100000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1 = -1,ans2 = -1,js = 1;
    cin >> n;
    memset(a,true,sizeof(a));
    int p,s = 2;
    while(js<n){
        s = 2;
        for(int i = 0;i<n;i++){
            if(a[i]){
                s++;
            }
            if(s == 3){
                if(i == n-1)ans2 = js;
                a[i] = false;
                s = 0;
            }
        }
        for(int i = 0;i<=n;i++){
            if(i == n){
                ans1 = js;
                break;
            }
            if(a[i])break;
        }
        if(ans1 != -1&&ans2 != -1){
            break;
        }
        js++;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}
