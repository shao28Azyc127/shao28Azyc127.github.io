include <iostream>
using namespace std;

int d(int a,int b,int c){
	return b * b - 4 * a * c;
}

int quality(int delta){
	int i = 0;
	while(i * i <= delta){
		if (i * i == delta){
			return i;
		}
		i++;
	}
	return -1;
}

int Qout(int p,int q){
	if (q < 0){
		p *= -1;q *= -1;
	}
	for (int i = 2;i < q;i++){
		if (q % i == 0){
			if (p % i == 0);
			p /= i;
			q /= i;
			i--;
		}
	}
	if (q == 1){
		cout << p;
		return 0;
	}	
	cout << p << '/' << q;
	return 0;
}

int sq(int delta){
	int ans = 1;
	for (int i = delta;i > 1;i--){
		if (delta % (i * i)){
			ans *= i;
			delta /= (i * i);
			if (delta < i){
				i = delta;
			}
		}
	}
	return ans;
}

int main(){
	int T,M,a,b,c,delta,q2,q3,qualityDelta;
	cin >> T >> M;
	for (int i = 0;i < T;i++){
		cin >> a >> b >> c;
		delta = d(a,b,c);
		if (delta < 0){
			cout << "NO" << endl;
		}else{
			qualityDelta = quality(delta);
			if (qualityDelta >= 0){
				p = -1 * b + qualityDelta;
				q = 2 * a;
				Qout(p,q);
				cout << endl;
			}else{
				if (b != 0){
					Qout(-1 * b;2 * a);
					cout << '+';
				}
				q2 = sq(delta);
				q3 = 2 * a;
				delta /= (q2 * q2);
				if (q3 < 0){
					q2 *= -1;
					q3 *= -1;
				}
				if (q2 == q3){
					cout << "sqrt(" << delta << ')' << endl;
				}else{
					if (q2 % q3 == 0){
						cout << q2 / q3 << "sqrt(" << delta << ')' << endl;
					}else{
						for (int i = 2;i < q3;i++){
							if (q3 % i == 0){
								if (q2 % i == 0){
									q3 /= i;
									q2 /= i;
									i--;
								}
							}
						}
						if (q2 == 1 && (q2 == -1)){
							cout << "sqrt(" << delta << ")/" << q3 * q2 << endl;
						}else{
							cout << q2 << "*sqrt(" << delta << ")/" << q3 << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}