#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
string S;
bool f;//true:sqrt(d) % 1 == 0
//-b + sqrt(d);
string izc(int n){
	string s;
	if(n == 0){
		return "0";
	}
	stack <char> ss;
	if(n < 0){
		s += '-';
		n *= -1;
	}
	while(n){
		ss.push(char(n % 10 + '0'));
		n /= 10;
	}
	while(!ss.empty()){
		s += ss.top();
		ss.pop();
	}
	return s;
}

int czib8(string s){
	bool f = false;
	int n = 0, i = 0;
	if(s[0] == '-'){
		f = true;
		i ++;
	}
	while(s[i] >= '0' && s[i] <= '9'){
		n *= 10;
		n += int(s[i] - '0');
		i ++;
	}
	if(f){
		n *= -1;
	}
	return n;
}

int czi(string s){
	bool f = false;
	int n = 0, i = 0;
	if(s[0] == '-'){
		cout<<s<<" "<<s[0]<<endl;
		f = true;
		i ++;
	}
	while(i < s.size()){
		n *= 10;
		n += int(s[i] - '0');
		i ++;
	}
	if(f){
		n *= -1;
	}
	return n;
}

int ping(int n){
	int p = 1;
	for(int i = 2; i <= sqrt(n); i ++){
		if(n % (i * i) == 0){
			p = i;
		}
	}
	return p;
}

string Sq(int n){
	string s;
	if(n == 0){
		return "0";
	}
	if(sqrt(n) * sqrt(n) == n){
	f = true;
		n = sqrt(n);
		s += izc(n);
		return s;
	}
	else{
		if(ping(n) != 1){
			int p = ping(n);
			n /= p * p;
			s += izc(p);
			s += '*';
		}
		s += "sqrt(";
		s += izc(n);
		s += ")";

	}
	return s;
}

string Chu(string s, int chu){
	if(chu == 1){
		return s;
	}
	int beichu = czi(s);
	int shu = 1;
	s = "";
	if(beichu < 0){
		cout<<"b";
		shu *= -1;
		beichu *= -1;
	}
	if(chu < 0){
		shu *= -1;
		chu *= -1;
	}
	if(beichu % chu == 0){
		return izc(beichu / chu * shu);
	}
	else{
		for(int i = 2; i <= sqrt(beichu); i ++){
			if(beichu % i == 0 && chu % i == 0){
				beichu /= i;
				chu /= i;
			}
		}
		beichu *= shu;
		s += izc(beichu);
		s += '/';
		s += izc(chu);
	}
	return s;
}

string sqrtchu(string s, int chu){
	if(f){
		return Chu(s, chu);
	}
	else{
		
		int ssl = izc(czib8(s)).size();
		int ss = abs(czib8(s));
		chu = abs(chu);
		for(int i = 2; i <= sqrt(ss); i ++){
			if(ss % i == 0 && chu % i == 0){
				ss /= i;
				chu /= i;
			}
		}
		string SS = izc(ss);
		for(int i = ssl; i < s.size(); i ++){
			SS += s[i];
		}
		SS += '/';
		SS += izc(chu);
		return SS;
	}
}

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	for(int asdf = 0; asdf < T; asdf ++){
		S = "";
		cin >> a >> b >> c;
		d = b * b - 4 * a * c;
		if(d < 0){
			cout << "NO" <<endl;
			continue;
		}
		else{
			S += izc(-1 * b);
			string ss;
			ss = Sq(d);
			if(f){
				ss = izc(czi(ss) + czi(S));
				S = Chu(ss, 2 * a);
				if(S == ""){
					S = "0";
				}
			}
			else{
				S = Chu(S, 2 * a);
				if(S[0] == '0'){
					S = "";
				}
				ss = sqrtchu(ss, 2 * a);
				if(ss[0] == '0'){
					ss = "";
				}
				if(S != "" && ss != ""){
					S += '+';
				}
				S += ss;
				if(S == ""){
					S = "0";
				}
			}
			cout << S << endl;
		}
	}
	return 0;
}