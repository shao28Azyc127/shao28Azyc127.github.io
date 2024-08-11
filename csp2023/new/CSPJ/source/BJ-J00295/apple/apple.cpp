#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int cnt=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            cnt++;
            a[i]=cnt;
            int d=0;
            for (int j=i+1;j<=n;j++){
                if (a[j]==0 && d==2){
                    d=0;
                    a[j]=cnt;
                }else if (a[j]==0){
                    d++;
                }
            }
        }
    }
    cout<<cnt<<" "<<a[n];
    return 0;
}
