#include <iostream>

#define ONLINE

using namespace std;

int main()
{
#ifdef ONLINE
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif

	int n, d;
	cin >> n >> d;
	
	long long sum = 0;
	
	for (int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
	}
	
	long long tmp;
	
	cin >> tmp;
	cout << tmp * ceil((double)sum / d) << endl;
	
	return 0;
}
