# include <vector>
# include <iostream>
using namespace std;

vector <int> val;
vector <bool> tag;
vector <int> tmp;
vector <int> fa;
int rev[3] = {0, -2, -1};
int n, m;

int dfs(int step){
    if (step > n){
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int k = val[i];
            if (k > 0)
                k = tmp[k];
            if (tag[i])
                k = rev[-k];
            if (k != tmp[i])
                return n;
            ans += (k == 0);
        }
        return ans;
    }
    int ans = n;
    tmp[step] = -2;
    ans = min(ans, dfs(step + 1));
    tmp[step] = -1;
    ans = min(ans, dfs(step + 1));
    tmp[step] = 0;
    ans = min(ans, dfs(step + 1));
    return ans;
}

int fd(int x){
    return (fa[x] == x) ? x : (fa[x] = fd(fa[x]));
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if (c <= 2){
        while (t--){
            cin >> n >> m;
            val.clear(), tag.clear();
            val.resize(n + 1), tag.resize(n + 1);
            for (int i = 1; i <= n; i++)
                val[i] = i;
            while (m--){
                char c;
                int x;
                cin >> c >> x;
                if (c == 'T')
                    val[x] = -1, tag[x] = 0;
                else if (c == 'F')
                    val[x] = -2, tag[x] = 0;
                else if (c == 'U')
                    val[x] = 0, tag[x] = 0;
                else {
                    int pos;
                    cin >> pos;
                    val[x] = val[pos], tag[x] = tag[pos] ^ (c == '-');
                }
            }
            tmp.clear();
            tmp.resize(n + 1);
            cout << dfs(1) << endl;
        }
        return 0;
    }
    else if (c <= 4){
        while (t--){
            cin >> n >> m;
            val.clear();
            val.resize(n + 1);
            while (m--){
                char c;
                int x;
                cin >> c >> x;
                if (c == 'U')
                    val[x] = 1;
                else
                    val[x] = 0;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++)
                ans += val[i];
            cout << ans << endl;
        }
        return 0;
    }
    else if (c <= 6){
        while (t--){
            cin >> n >> m;
            val.clear();
            val.resize(n + 1);
            for (int i = 1; i <= n; i++)
                val[i] = i;
            while (m--){
                char c;
                int x;
                cin >> c >> x;
                if (c == 'U')
                    val[x] = 0;
                else {
                    int pos;
                    cin >> pos;
                    val[x] = val[pos];
                }
            }
            int ans = 0;
            fa.clear();
            fa.resize(n + 1);
            for (int i = 1; i <= n; i++)
                fa[i] = i * (val[i] != 0);
            for (int i = 1; i <= n; i++)
                fa[fd(i)] = fd(val[i]);
            for (int i = 1; i <= n; i++)
                ans += (fd(i) == 0);
            cout << ans << endl;
        }
        return 0;
    }
    return 0;
}