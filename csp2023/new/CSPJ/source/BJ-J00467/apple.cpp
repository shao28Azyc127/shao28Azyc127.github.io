#include<bits/stdc++.h>
using namespace std;
#define int long long
bool s[1000010];
int t[1000010];
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=1,k=0;
    for(int i=1;i<=n;i++){
        if(!s[i]){
            t[i]=cnt;
            for(int j=i+1;j<=n;j++){
                    //cout<<j<<" "<<s[j]<<" "<<k<<" "<<endl;
                if(!s[j]){
                    //cout<<j<<" "<<s[j]<<" "<<k<<endl;
                    k++;
                    if(k==3){
                    t[j]=cnt;
                    k=0;
                    s[j]=true;
                 }
                 }

            }
            cnt++;
            k=0;
        }
    }
    //for(int i=1;i<=n;i++)cout<<i<<" "<<t[i]<<endl;
    //cout<<endl;
    cout<<cnt-1<<" "<<t[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
