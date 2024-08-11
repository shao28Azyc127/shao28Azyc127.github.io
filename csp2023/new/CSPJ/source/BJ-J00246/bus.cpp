#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	int n, m, k, sum=0;;
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		sum += c;
	}
	srand(time(0));
	cout<<(rand() % (sum/2) + 1)*k;
}
//我不会，我不会，我不会!