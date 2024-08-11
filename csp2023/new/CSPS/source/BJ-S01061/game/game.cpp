#include <iostream>
#include <set>
#include <string>
#include <vector>

#define ONLINE

using namespace std;

set<string> valid;
vector<char> alphabet;

inline int end_prog()
{
    fclose(stdout);
    return 0;
}

void get_valid_str(int len, string curr = "")
{
    if ((len & 1) == 1)
        --len;

    if (curr.size() > len || valid.find(curr) != valid.end())
		return;

    valid.emplace(curr);
    // fprintf(stderr, ">>> get_valid_str(%d, \"%s\")\n", len, curr.c_str());

    for (char c : alphabet) {
        get_valid_str(len, c + curr + c);
        get_valid_str(len, string(2, c) + curr);
        get_valid_str(len, curr + string(2, c));
    }
}

int main()
{
#ifdef ONLINE
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
#endif

    int n;
    string s;

    cin >> n >> s;

    for (char ch : s)
		alphabet.emplace_back(ch);

    long long cnt = 0;
    get_valid_str(n);

    for (const auto& p : valid) {
		for (const auto& q : valid) {
			if (p.size() + q.size() > n)
				continue;

			valid.emplace(p + q);
		}
	}

    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            if (valid.find(s.substr(i, l)) != valid.end())
                ++cnt;
        }
    }

    cout << cnt << endl;
    return end_prog();
}
