//c
#include <bits/stdc++.h>
using namespace std;

int t,m;
int a,b,c;

int gcd(int a,int b){
	int m;
	while (b>0){
		m=a;
		a=b;
		b=m%a;
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> t >> m;
	while (t--)
	{
		cin >> a >> b >> c;
		int delta=b*b-4*a*c;
//		cout << "delta=" << delta << endl;
		if (delta<0){
			cout << "NO" << endl;
		}
		else{
			double s=sqrt(delta);
//			cout << s << endl;
			if ((int)s*(int)s!=delta){//wu li shu
//				cout << "wu li shu" << endl;
			}
			else{
				double fenzi=sqrt(delta)-b;
				double fenmu=2*a;
				int g=gcd(fenzi,fenmu);
//				cout << fenzi 	<< " " << fenmu << " " << g << endl;
				if (fenzi/g==0){
					cout << 0 << endl;
				}
				else if (fenmu/g==1){
					cout << fenzi/g << endl; 
				}
				else if (fenmu/g==-1){
					cout << -fenzi/g << endl;
				}
				else{
					cout << fenzi/g << "/" << fenmu/g << endl;
				}
			}
		}
	}
	return 0;
}