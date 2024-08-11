#include <cmath>
#include <iostream>

#define ONLINE

using namespace std;

int main()
{
#ifdef ONLINE
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	
	int tot = 0, lst = 0;
	bool not_lst = true;
	
	while (n > 0) {
		++tot;
		
		if (not_lst)
			++lst;
			
		if (n % 3 == 1)
			not_lst = false;
			
		n -= ceil(n / 3.0);
	}
	
	printf("%d %d\n", tot, lst);
	fclose(stdout);
	
	return 0;
}
