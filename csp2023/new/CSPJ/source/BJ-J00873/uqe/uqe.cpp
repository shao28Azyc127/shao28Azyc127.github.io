#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
int t, m;
long long a, b, c;
pair<long long, long long> f(long long fz, long long fm) {
	if(fm < 0) {
		fm = -fm;
		fz = -fz;
	}
	long long g = gcd(abs(fz), fm);
	fz /= g;
	fm /= g;
	return {fz, fm};
}
void solve(long long a, long long b, long long c) {
	long long delta = b * b - 4 * a * c;
	if(delta < 0) {
		cout << "NO" << endl;
		return;
	}
	long long q = 1, r = delta;
        for(long long i = 2; i * i <= r; i++) {
                while(r % (i * i) == 0) {
                        q *= i;
                        r /= (i *i);
                }
        }
	pair<long long, long long> q1;
	if(r == 0 || r == 1) {
		if(r == 1) {
			if(a < 0) q1 = f(-b - q, 2 * a);
			else q1 = f(-b + q, 2 * a);
		}
		else q1 = f(-b, 2 * a);

	        if(q1.first != 0) {
	                if(q1.second == 1) cout << q1.first;
	                else cout << q1.first << "/" << q1.second;
      		}
		else cout << "0";
		cout << endl;
		return;
	}

	q1 = f(-b, 2 * a);
	if(q1.first != 0) {
		if(q1.second == 1) cout << q1.first;
		else cout << q1.first << "/" << q1.second;
		cout << "+";
	}
	pair<long long, long long> q2;
	if(a < 0) q2 = f(-q, 2 * a);
	else q2 = f(q, 2 * a);
	if(q2.first == 1 && q2.second == 1) cout << "sqrt(" << r << ")";
	else if(q2.second == 1) cout << q2.first << "*sqrt(" << r << ")";
	else if(q2.first == 1) cout << "sqrt(" << r << ")/" << q2.second;
	else cout << q2.first << "*sqrt(" << r << ")/" << q2.second;
	cout << endl;
	return;
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while(t--) {
		cin >> a >> b >> c;
		solve(a, b, c);
	}
	return 0;
}