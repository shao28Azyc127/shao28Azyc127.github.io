#include <iostream>

using namespace std;

int a[10000000]={};
bool w(int n){
    for(int i = 0;i < n;i++){
        if(a[i]==0) return 0;
    }
    return 1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int s=0,n,t=1,r;
    cin>>n;
    for(int i = 1;;i++){
        for(int j = 0;j < n;j++){
            if(t==1&&a[j]==0){
                a[j]=1;
                t = 0;
            }
            else if(a[j]==0&&s==2) a[j]=1;
            else if(a[j]==0) s++;
        }
        if(a[n-1]==1) r=i;
        if(w(n)){
            cout<<i<<' '<<r;
            return 0;
        }
        s = 0;
        t = 1;
    }
    return 0;
}
