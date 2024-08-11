//zyc AK IOI
#include<bits/stdc++.h>
using namespace std;
int n;
int ans,f,i;
bool flag=false;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for (i=1;n/3!=0;i++){
        if (!flag&&n%3==1){
            f=i;
            flag=true;
        }
        if (n%3==0)n=n-n/3;
        else n=n-n/3-1;
        ans++;
    }
    if (flag==false){
        for(int j=i;n>0;j++){
            if (!flag&&n%3==1){
                f=j;
                flag=true;
            }
            ans++;
            n--;
        }
    }
    else ans+=n;
    cout << ans << " " << f;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
