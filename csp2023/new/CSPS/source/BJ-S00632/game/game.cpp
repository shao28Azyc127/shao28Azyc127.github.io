#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10000;
const int MAXN = 2000000 + 10;
int n;
string s;
bool f[maxn][maxn];
unordered_map<long long, int> cnt;
unordered_map<long long, vector<int>> pos;
long long h[MAXN];
int sufcnt[MAXN], chcnt[MAXN][26];
stack<pair<int, int>> os[26];
int _last[MAXN];
long long myhash(int a[]) {
	const long long base = 9999997;
	const long long MOD = 1000000007;
	long long h = 0;
	for(int i = 0; i < 26; i++) {
		h = h * base + a[i];
		h %= MOD;
	}
	return h;
}
long long check() {
	for(int i = 0; i < n; i++) f[i][i] = false;
        for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[i+1]) f[i][i+1] = true;
                else f[i][i+1] = false;
        }       
        for(int len = 3; len <= n; len++) {
                for(int st = 0; st <= n - len; st++) {
			int ed = st + len - 1;
			if(s[st] == s[ed] && f[st+1][ed-1]) f[st][ed] = true;
			for(int mid = st; mid < ed; mid++) {
				if(f[st][mid] && f[mid+1][ed]) f[st][ed] = true;
			}
		}
	}
	long long chans = 0;
	for(int st = 0; st < n; st++) {
		for(int ed = st + 1; ed < n; ed++) {
			if(f[st][ed]) chans++;
		}
	}
	return chans;
}	
int myfind(int i) {//find chcnt[last][some] < chcnt[i][some]
	int last = n + 1;
	for(int j = 0; j < 26; j++) {
		//cout << os[j].size() << endl;
		//cout << i << " " << j << " " << chcnt[i][j] << " " << os[j].top().first << endl;
		while(os[j].top().first >= chcnt[i][j]) os[j].pop();
		if(os[j].empty()) cerr << "EMPTY!" << endl;
		last = min(last, os[j].top().second);
		os[j].push({chcnt[i][j], i});
	}
	return last;
}
int checkcnt(int i) {
	int ret;
	for(int j = i + 1; j < n; j++) {
		bool flag = true;
		for(int k = 0; k < 26; k++) {
			if(chcnt[i][k] > chcnt[j][k]) {
				flag = false;
				//if(i == 575) cout << "checkcnt-j: " << j  << " " << char('a' + k) << endl;
				break;
			}
		}
		if(!flag) break;
		if(h[i] == h[j]) ret++;
	}
	return ret;
}
int checkcntf(int i) {
	int ret = 0;
	for(int j = i + 1; j <= n; j++) {
		if(f[i][j]) ret++;
		//if(i == 575 && f[i][j]) cout << "cntf-j: " << j << endl;
	}
	return ret;
}
long long solve() {
	long long ans = 0;
	stack<char> st;
	h[0] = 0;
	for(int i = 1; i <= n; i++) {
		char ch = s[i-1];
		for(int j = 0; j < 26; j++) chcnt[i][j] = chcnt[i-1][j];
		if(!st.empty() && st.top() == ch) {
			chcnt[i][ch-'a']--;
			st.pop();
			h[i] = myhash(chcnt[i]);
		}
		else {
			st.push(ch);
			chcnt[i][ch-'a']++;
			h[i] = myhash(chcnt[i]);
		}
	}
	_last[n] = _last[n+1] = n + 1;
	for(int i = n - 1; i >= 1; i--) {
		if(s[i-1] == s[i]) {
			_last[i] = _last[i + 2];
		}
		else {
			if(_last[i+1] == n + 1) _last[i] = n + 1;
			else if(s[_last[i+1]-1] == s[i-1]) _last[i] = _last[_last[i + 1] + 1];
			else _last[i] = _last[i+1];
		}
	}

	//for(int i = 0; i <= n; i++) cout << h[i] << " "; cout << endl;
	for(int i = 0; i <= n; i++) pos[h[i]].push_back(i);
	/*
	for(auto h : pos) {
		cout << h.first << ": ";
		for(int pos : h.second) cout << " " << pos;
		cout << endl;
	}
	*/
	for(int i = 0; i < 26; i++) os[i].push({-1, n+1});
	//myfind(n);
	//long long ans2 = 0;
	for(int i = n - 1; i >= 0; i--) {
		cnt[h[i+1]]++;
		sufcnt[i+1] = cnt[h[i+1]];
		
		long long hi = h[i];
		//int last = myfind(i);
		int last = _last[i];
		//if(i == 575) for(int j = 573; j <= 590; j++) cout << s[j]; cout << endl;
		//if(i == 575) cout << "last = " << last << endl;
		//cout << i << " " << last << endl;
		//the end should be [i+1, last-1]
		auto ind = upper_bound(pos[hi].begin(), pos[hi].end(), last - 1);
		if(ind == pos[hi].end()) {
			ans += cnt[hi];
			//int chcnt = checkcnt(i);
			//int chcntf = checkcntf(i);
			//ans2 += chcnt;
			//cout << "i= " << i << " ans = " << ans << "  +" << cnt[hi] << " " << chcnt << " " << chcntf << endl;
			continue;
		}
		int lastpos = *ind;
		ans += cnt[hi] - sufcnt[lastpos];
		//cout << i << " " << cnt[hi] << " " << sufcnt[lastpos] << " " << lastpos << endl;
		//int chcnt = checkcnt(i);
		//int chcntf = checkcntf(i);
		//ans2 += chcnt;
		//if(i == 575) cout << lastpos << " " << last << endl;
                //cout << "i= " << i << " ans = " << ans << "  +" << cnt[hi] - sufcnt[lastpos] << " " << chcnt << " " << chcntf << endl;

	}
	//for(int i = 0; i <= n; i++) cout << sufcnt[i] << " "; cout << endl;
	//cout << "ans2 = " << ans2 << endl;
	return ans;
}
long long solve2() {
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		stack<char> st;
		for(int j = i; j < n; j++) {
			if(!st.empty() && st.top() == s[j]) {
				st.pop();
				if(st.empty()) ans++;
			}
			else {
				st.push(s[j]);
			}
		}
	}
	return ans;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	//long long chans = check();
	long long ans = solve();
	//long long ans2 = solve2();
	//cout << chans << " " << ans << " " << ans2 << endl;
	cout << ans << endl;
	return 0;
}