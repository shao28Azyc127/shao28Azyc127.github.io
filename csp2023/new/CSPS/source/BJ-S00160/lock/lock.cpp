#include<bits/stdc++.h>
using namespace std;
int n,ans=50;
int a[10][10];
int f[10][10],tail;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	f[1][1]=f[1][2]=f[1][3]=f[1][4]=f[1][5]=1;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >> a[i][j];
            if(i!=1 && a[i][j] != a[i-1][j]){
                if(f[i-1][j] != 1){
                    cout << 0;
                    return 0;
                }
                f[i][j]=1;
                tail++;
            }
            //else ans-=1;
        }
	}
	if(tail == 0){
        cout << 81;
        return 0;
    }
    if(tail == n-1){
        cout << 12-n;
        return 0;
    }
	if(tail == n*2-2){
        cout << 10-n;
        return 0;
	}
	cout << 0;
	return 0;
}
