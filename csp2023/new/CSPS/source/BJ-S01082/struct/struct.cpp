#include <fstream>

using namespace std;

ifstream cin("struct.in");
ofstream cout("struct.out");

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << "ERR" << endl;
	return 0;
}