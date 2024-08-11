#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int c,t,n,q,x,num[100005];
char opt;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(num,0x3f,sizeof(num));
        cin >> n >> q;
        for(int i = 1;i <= q;i++){
            cin >> opt >> x;
            if(opt == 'T') num[x] = 1;
            else if(opt == 'F') num[x] = 0;
            else num[x] = -1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(num[i] == -1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}