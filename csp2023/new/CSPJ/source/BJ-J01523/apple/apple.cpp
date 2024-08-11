#include<bits/stdc++.h>

using namespace std;

int main(){

	//TO NAME
	int p = 0, n, m = 1, ans1 = 1, len;
	queue<int> q[2];
	//TO DO
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
    while(ans1 < n){
        ans1 += m;
        m++;
    }printf("%d 1", m);

	return 0;
}

