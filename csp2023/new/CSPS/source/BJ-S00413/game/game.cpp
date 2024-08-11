#include <iostream>

using namespace std;

char s[8005];
long long n,ans;
bool er[20002][20002];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    ans = 0;
    for(int j = 0;j<n-1;j++){
         if(s[j]==s[j+1]){
            er[j][2] = true;
            ans++;
         }
    }
    for(int i = 4;i<=n;i+=2){
        for(int j = 0;j+i<=n;j++){
            if(er[j+1][i-2]&&s[j] == s[j+i-1]){
                er[j][i] = true;
                ans++;
            }
            else{
                for(int k = 2;k<i;k+=2){
                    if(er[j][k]&&er[j+k][i-k]){
                        er[j][i] = true;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
