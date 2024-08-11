# include <iostream>
using namespace std;

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int seed;
	srand(seed = time(NULL));
	cout << rand() % int(1e9 + 1);
	return 0;
}