# include <iostream>
# include <ctime>
using namespace std;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	unsigned long long seed;
	srand(seed = time(NULL));
	cout << rand() % int(1e10 + 1);
	return 0;
}