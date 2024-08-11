#include<bits/stdc++.h>
using namespace std;
long long n,m,i=0,j,s=1;
bool f=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n>=1)
    {
		i++;
		if(n%3==1&&f)
		{
			s=i;
			f=false;
			//cout << n << '\n';
		}
		long long k=(n-1)/3+1;
		//cout << k;
		n-=k;
	}
	cout << i << ' ' << s ;
    return 0;
}
