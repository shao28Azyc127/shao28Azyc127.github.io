// kamisako
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <utility>
#include <set>
#include <iostream>

using namespace std;

namespace kamisako{
#define fi first
#define se second
#define mk make_pair

const int maxn=2e6+10;
int n,ans;
string s;
int ori[maxn];

bool ck(int l,int r) {
	stack<int> st;
	for (int i = l; i <= r; ++i) {
		if (!st.empty() && st.top() == (int)s[i]) {
			st.pop();
		} else st.push(s[i]);
	}
	return (bool)st.empty();
}
int le[maxn],re[maxn],lcnt=0;

void main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>n;
	cin>>s;

	set<pair<int,int> > mp;
	
	for (int j = 0; j < n; ++j) {
		stack<pair<int,int> > st;
		for (int i = j; i < n; ++i) {
			if (!st.empty() && st.top().fi==(int)s[i]) {
				int os=mp.size();
				mp.insert(mk(st.top().se,i));
				if (mp.size()!=os) {
					le[lcnt]=st.top().se,re[lcnt]=i,lcnt++;
					// printf("==%d %d\n",st.top().se,i);
					ori[st.top().se]=i;
					++ans;
				}
				st.pop();
			} else {
				st.push(mk((int)s[i],i));
			}
		}
	}
	sort(le,le+lcnt);
	sort(re,re+lcnt);
	int ln=unique(le,le+lcnt)-le;
	int rn=unique(re,re+lcnt)-re;

	for (int i = 0; i < ln; ++i) {
		for (int j = 0; j < rn; ++j) {
			if (le[i]>=re[j]) continue;
			if (ori[le[i]]!=re[j]&&ck(le[i],re[j])) ++ans;
		}
	}

	printf("%d\n",ans);
}

#undef fi
#undef se
#undef mk
};


int main() {
	kamisako::main();
	
	return 0;
}