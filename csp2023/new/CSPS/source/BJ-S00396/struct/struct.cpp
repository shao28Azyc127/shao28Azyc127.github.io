#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream cin("struct.in");
ofstream cout("struct.out");

const int N = 105;
int n;
int opt[N];
string s1[N];
int k[N];
string t1[N][N], n1[N][N];
string t2[N], n2[N];
string s3[N];
long long addr[N];
map<string, int> mp;

int main() {
	int cnt = 0;
	mp.clear();
	mp["byte"] = 1, mp["short"] = 2, mp["int"] = 4, mp["long"] = 8;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> opt[i];
		if (opt[i] == 1) {
			cnt++;
			cin >> s1[i] >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				cin >> t1[i][j] >> n1[i][j];
			}
		} else if (opt[i] == 2) {
			cin >> t2[i] >> n2[i];
		} else if (opt[i] == 3) {
			cin >> s3[i];
		} else {
			cin >> addr[i];
		}
	}
	
	if (cnt == 0) {
		long long top = 0;
		for (int i = 1; i <= n; i++) {
			if (opt[i] == 2) {
				cout << top << endl;
				top += mp[t2[i]];
			} else if (opt[i] == 3) {
				long long tp = 0;
				for (int j = 1; j <= i; j++) {
					if (opt[j] == 2) {
						if (n2[j] == s3[i]) {
							break;
						}
						tp += mp[t2[j]];
					}
				}
				cout << tp << endl;
			} else {
				if (addr[i] >= top) cout << "ERR" << endl;
				long long w = 0;
				for (int j = 1; j <= i; j++) {
					if (opt[j] == 2) {
						w += mp[t2[j]];
						if (w > addr[i]) {
							cout << n2[j] << endl;
							break;
						}
					}
				}
			}
		}
	} else if (cnt == 1) {
		long long dx = 0;
		int yq = 0, kk;
		string type, name;
		long long top = 0;
		for (int i = 1; i <= n; i++) {
			if (opt[i] == 1) {
				kk = i;
				for (int j = 1; j <= k[i]; j++) {
					yq = max(yq, mp[t1[i][j]]);
				}
				dx = yq * k[i];
				mp[s1[i]] = dx;
				type = s1[i];
				cout << dx << " " << yq << endl;
			} else if (opt[i] == 2) {
				cout << top << endl;
				top += mp[t2[i]];
				if (t2[i] == type) name = n2[i];
			} else if (opt[i] == 3) {
				bool flag = false;
				string str = "";
				for (int j = 0; j < s3[i].size(); j++) {
					if (s3[i][j] == '.') {
						flag = true;
					}
					if (flag) {
						str = str + s3[i][j];
					}
				}
				long long tp = 0;
				if (flag) {
					for (int j = 1; j <= i; j++) {
						if (opt[j] == 2) {
							if (n2[j] == name) {
								break;
							}
							tp += mp[t2[j]];
						}
					}
					for (int j = 1; j <= k[kk]; j++) {
						if (n1[kk][j] == str) {
							cout << tp << endl;
							break;
						}
						tp += yq;
					}
				} else {
					for (int j = 1; j <= i; j++) {
						if (opt[j] == 2) {
							if (n2[j] == s3[i]) {
								break;
							}
							tp += mp[t2[j]];
						}
					}
					cout << tp << endl;
				}
			} else {
				long long w = 0;
				if (addr[i] >= top) cout << "ERR" << endl;
				for (int j = 1; j <= i; j++) {
					if (opt[j] == 2) {
						w += mp[t2[j]];
						if (w > addr[i]) {
							if (t2[j] == type) {
								w -= mp[t2[j]];
								int ww = w;
								for (int p = 1; p <= k[kk]; p++) {
									w += yq;
									ww += mp[t1[i][p]];
									if (addr[i] < w) {
										if (addr[i] >= ww) cout << "ERR" << endl;
										else cout << name << "." << n1[i][p]; 
										break;
									}
								}
							} else {
								cout << n2[j] << endl;
								break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}