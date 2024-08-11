#include <iostream>
using namespace std;
int a[100];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	int ans = 0, anss = 0;
	cin >> n;
	int m = n;
	for(; n>0; ans++){
		n-=1;
		int temp = n/3;
		n-=temp;
		if(m != -1 && (m-1) % 3 == 0){
			anss = ans;
			m = -1;
		}
		if(m != -1)	{
		m = m - temp - 1;
		}
	}
	cout << ans << " " << anss+1;
	
	return 0;
}
