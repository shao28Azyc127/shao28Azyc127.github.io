#include<iostream>
using namespace std;
int a[100001];
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<n;
        return 0;
    }
    int cnt=1;
    int num=0;
    int ans=0;
    a[1]=1;
    for(int i=1;;i++){
        if(cnt==n){
            cout<<ans+1;
            return 0;
        }
        for(int j=cnt+1;j<=n;j++){

            if(a[j]==0){
                num++;
            }
            if(num==3&&j==n){
                cout<<ans+1;
                return 0;
            }
            if(num==3){
                a[j]=1;
                cnt=j;
                num=0;
            }
        }
        num=0;
        ans++;
        for(int j=1;j<=n;j++){
            if(a[j]==0){
                cnt=j;

                a[j]=1;
                break;
            }
        }

    }
    return 0;
}
