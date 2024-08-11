#include<iostream>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    char a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    while (true){
        char b[n];
        for (int i=0;i<n;i++) b[i]=a[i];
        for (int i=0;i<n;i++){
            int j=i+1;
            while (j<n&&a[j]==0) j++;
            if (a[i]==a[j]&&a[i]){
                a[i]=0;
                a[j]=0;
                cnt++;
            }
        }
        bool boo=true;
        for (int i=0;i<n;i++) if (a[i]-b[i]) boo=false;
        if (boo) break;
    }
    cout<<cnt+1;
    return 0;
}