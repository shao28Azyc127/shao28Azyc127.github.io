#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
string s;

int n,num,ans = 0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    for(int i = 0;i<n-1;i++){
        if(s[i] == s[i+1]){
            ans++;
            for(int j = 1;i-j>=0&&i+j<n;j++){
                if(s[i-j] == s[i+1+j]){
                        ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
