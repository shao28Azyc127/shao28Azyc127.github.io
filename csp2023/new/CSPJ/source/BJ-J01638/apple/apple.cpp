#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int cnt;
int ncnt = -1;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	
	scanf("%d",&n);
	while(n > 0){
		cnt++;
		if(n%3 == 1){
			if(ncnt == -1)ncnt = cnt;
			n--;
		}
		n -= max(int(ceil(1.0*n/3)),1);
		//cout<<n<<endl;
	}
	printf("%d %d",cnt,ncnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
