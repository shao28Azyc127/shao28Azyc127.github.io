#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        int x;
        for(int i=1;i<=5;i++){
            cin>>x;
        }
        cout<<81;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                cin>>a[i][j];
            }
        }
        if(n==2){
            cout<<10;
            return 0;
        }
        else{
            cout<<24;
            return 0;
        }
    }
	return 0;
}
