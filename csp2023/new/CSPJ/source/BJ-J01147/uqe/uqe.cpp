#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct uqes{
	int a;
	int b;
	int c;
	int result_delta(int a,int b,int c){
		return b*b - 4*a*c;
	}
};
bool is_Prime(int n){
	if(n == 0)
		return false;
	if(n == 1)
		return false;
	if(n == 2)
		return true;
	for(int i = 1; i <= n / i; i++)
		if(n % i == 0)
			return false;
	return true;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin >> T >> M;
	uqes uqe[T+5];
	long long prime[1000+5],j = 1;
	for(int i = 1; i <= 1e3; i++)
		if(is_Prime(i)){
			prime[j] = i;
			j++;
		}
	for(int i = 1; i <= T; i++){
		cin >> uqe[i].a >> uqe[i].b >> uqe[i].c;
		if(uqe[i].result_delta(uqe[i].a,uqe[i].b,uqe[i].c) < 0){
            cout << "NO" << endl;
            break;
		}
		if(uqe[i].result_delta(uqe[i].a,uqe[i].b,uqe[i].c)  == 0){
			cout << "-" << uqe[i].b << "/" << 2 * uqe[i].a << endl;
			break;
		}
		if(uqe[i].result_delta(uqe[i].a,uqe[i].b,uqe[i].c) >= 0){
			long long ab[10000] = {0},delta = uqe[i].result_delta(uqe[i].a,uqe[i].b,uqe[i].c),len = 1,j,multi = 1;
			for(int i = 1; i * i <= delta; i++){
                if(delta % (i*i) == 0){
                    delta /= i*i;
                    multi *= i;
                }
			}
			if(multi * (-1 * uqe[i].b) % 2*uqe[i].a == 0)
				cout << multi * (-1 * uqe[i].b) / 2*uqe[i].a << "*" << "sqrt(" << delta << ")" << endl;
			else
				cout << (-1 * uqe[i].b) << "/" << 2 * uqe[i].a << "+" << multi << "*sqrt(" << delta << ")" << endl;
		}
	}
	return 0;
}
