#include <bits/stdc++.h>
using namespace std;
int n,a[100000050],b[100000050];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int y=n;
    for(int i=1;i<=n;i++)a[i]=i;
    int num=0;
    for(int i=1;;i++){
        for(int j=1;j<=n;j+=3){
            if(a[j]==y)num=i;
            a[j]=0;
        }
        for(int j=1;j<=n;j++)b[j]=a[j];
        int p=0,o=1;
        for(int j=1;j<=n;j++){
            if(b[j]==0)p++;
            else {
                a[o]=b[j];
                o++;
            }
        }
        n-=p;
        if(n==0){
            cout<<i<<' '<<num<<endl;
            return 0;
        }
    }
}
