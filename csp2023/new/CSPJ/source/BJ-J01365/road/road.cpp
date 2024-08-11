#include <iostream>
using namespace std;


int n,a,b, d, list[100000]; 
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=0;i<n-1;i++)
	{
		cin >> a;
		b+=a;
	} 
    for(int i=0;i<n;i++) cin >> list[i];
    cout << list[0]*(b/d);
	return 0;
}