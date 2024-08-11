#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string Input[10];
multiset<string> st;
multiset<string>::iterator it;
ll cnt;
ll Record[100005];

void Change(ll x){
	string s = Input[x];
	char stmp, stmp2;

	if(x != 1){
		for(int i = 0; i < 5; i++){
			for(int j = 1; j <= 9; j++){
				
				stmp = s[i];
				s[i] = ((((s[i] - '0') + j + 10) % 10) + '0');
				
				//cout << cnt << " ";
				st.insert(s);
				
				//cout << s << " " << tcnt << "\n";

				
				s[i] = stmp;
			}
		}
		
		s = Input[x];
		
		for(int i = 0; i < 4; i++){
			for(int j = 1; j <= 9; j++){
				
				stmp = s[i];
				stmp2 = s[i + 1];
				
				s[i] = ((((s[i] - '0') + j + 10) % 10) + '0');
				s[i + 1] = ((((s[i + 1] - '0') + j + 10) % 10) + '0');
				
				
				st.insert(s);
				
				//cout << s << " ";
				
				
				s[i] = stmp;
				s[i + 1] = stmp2;
			}
		}
		return ;
	}
	
	for(int i = 0; i < 5; i++){
		for(int j = 1; j <= 9; j++){
			stmp = s[i];
			
			s[i] = ((((s[i] - '0') + j + 10) % 10) + '0');
			
			st.insert(s);
			//cout << s << " ";
			s[i] = stmp;
		}
		//cout << endl;
	}
	
	s = Input[x];
	
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= 9; j++){
			stmp = s[i];
			stmp2 = s[i + 1];
			
			s[i] = ((((s[i] - '0') + j + 10) % 10) + '0');
			s[i + 1] = ((((s[i + 1] - '0') + j + 10) % 10) + '0');
			st.insert(s);
			//cout << s << " ";
			s[i] = stmp;
			s[i + 1] = stmp2;
		}
		//cout << endl;
	}
	return ;
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	memset(Record, -1, sizeof(Record));
	scanf("%lld", &n);
	ll a, b, c, d, e;
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
		Input[i] += (a + '0');
		Input[i] += (b + '0');
		Input[i] += (c + '0');
		Input[i] += (d + '0');
		Input[i] += (e + '0');
		//cout << Input[i];
	}
	Change(1);
	if(n == 1){
		printf("81");
	} else {
		for(int i = 2; i <= n; i++){
			Change(i);
		}
		string Stemp;
		ll Ltemp = 0;
		for(it = st.begin(); it != st.end(); it++){
			Stemp = (*it);
			Ltemp = (Stemp[0] - '0') * 10000 + (Stemp[1] - '0') * 1000 + (Stemp[2] - '0') * 100 + (Stemp[3] - '0') * 10 + (Stemp[4] - '0') * 1;
			Record[Ltemp]++;
			Ltemp = 0;
		}
		for(int i = 0; i <= 99999; i++){
			if(Record[i] == n - 1){
				//cout << i << " " << Record[i] << "\n";
				cnt++;
			}
		}
		printf("%lld", cnt);
	}
	return 0;
}
