#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1=0,ans2=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=0;j<n;j++){
            if(a[j]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout << ans1 << " " << ans2;
            return 0;
        }
        int j=0;
        while(a[j]==-1) j++;
        while(j<n){
            a[j]=-1;
            int cnt=0;
            if(j==n-1){
                ans2=i+1;
            }
            while(cnt<3){
                j++;
                if(a[j]==0) cnt++;

            }
        }
        ans1++;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
