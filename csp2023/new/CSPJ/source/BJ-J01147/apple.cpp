#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool check(int a[][],int len,int n){
	bool flag = true;
	for(int i = 1; i <= n; i++)
		if(a[len][n] != 0){
			flag = false;
			break;
		}
	return flag
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int a[n+5][n+5] = {0},len = 1,last;
    for(int i = 1; i <= n; i++)
    	a[1][i] = i;
    while(!check(a,len,n)){
    	for(int i = 0; i <= n / 3; i++){
    		if(i * 3 + 1 == n)
    			last = len;
    		a[len][i * 3 + 1] = 0;
    	}
    	len++;
    	for(int i = 1; i <= n; i++){
    		if(a[len-1][i*3+1] != 0)
    			a[len][i] = a[len - 1][i * 3 + 1];
    	}
    }
    cout << len << " " << last;
	return 0;
}
