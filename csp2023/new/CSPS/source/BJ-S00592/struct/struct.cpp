#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int n;

const int N = 110;

map<string> id;
string na[N];
int idx = 0;

struct node {
    int to;
    string name;
};

vector<node> adj[N];

int get (string s) {
    if (!id[s]) id[s] = ++ idx, na[idx] = s;
    return id[s];
}

int sz (int k) {
    if (k == 1) return 1;
    if (k == 2) return 2;
    if (k == 3) return 4;
    if (k == 4) return 8;
}

int st[N], cnt;

int main () {
    freopen ("struct.in", "r", stdin);
    freopen ("struct.out", "w", stdout);

    ios::sync_with_stdio(false);
    
    cin >> n;
    
    id["byte"] = ++ idx;
    id["short"] = ++idx;
    id["int"] = ++ idx;
    id["long"] = ++ idx; 
    
    
    int now = -1;
    while (n -- )
     {
         int opt;
         cin >> opt;
         if (opt == 1) {
            string s;
            int k;
            cin >> k;
            while (k -- ){
                string t, n;
                cin >> t >> n;
                adj[get (s)].push_back({get(t), n});
            }
         }
         if (opt == 2) {
            string t, n;
            cin >> t >> n;
            
            adj[0].push_back (get (n));
            
            cout << now + 1 << endl;
            st[get (t)] = now + 1;
            cnt ++ ;
            now += sz (get (t));
         }
         if (opt == 3) {
            string s;
            int x = get (s);
            for (int i = 0; i < adj[0].size(); i ++ ) {
                int to = adj[0][i];
                if (x == to) {
                    cout << st[x] << endl;
                    break;
                }
            }
         }
         if (opt == 4) {
            int x;
            cin >> x;
            int l = 0, r = cnt;
            while (l < r) {
                int mid = (l + r) >> 1;
            
                if (st[mid] <= x) r = mid;
                else l = mid + 1;
            }
            
            cout << na[l] << endl;
         }
     }
    return 0;
}
