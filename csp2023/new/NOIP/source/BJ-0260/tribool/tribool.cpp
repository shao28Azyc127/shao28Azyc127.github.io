#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int num;
    int type;
    int flag;
    Node* val;
};

int c, t, n, m;
Node* g[100005];
int vis[100005];

void change(int x, int s){
    if (s == 0)
        g[x] -> type = 0, g[x] -> val = NULL;
    else if (s < 0){
        g[x] -> type = -1;
        g[x] -> val = g[-s];
    }
    else {
        g[x] -> val = g[s];
    }
}

bool mf(Node* no, int v){
    Node* head = no;
    int flag = 1;
    if (no -> val == NULL) return false;
    if (no -> flag != 0) return false;
    int op = no -> val -> num;
    while ((head -> val || head -> type == 0) && vis[head -> num] != v){
        flag *= head -> type;
        if (head -> type == 0){
            no -> type = 0;
            no -> val = NULL;
            break;
        }
        if (head -> flag != 0){
            no -> flag = head -> flag * flag;
            no -> val = NULL;
            no -> type = 1;
            break;
        }
        vis[head -> num] = v;
        head = head -> val;
        no -> type = flag;
        no -> val = head;
    }
    if (no -> val == no && no -> type == -1){
        no -> type = 0, no -> val = NULL;
        return true;
    }
    if (no -> val == NULL) return true;
    if (no -> val -> num == op) return false;
    return true;
}

int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            g[i] = new Node();
            g[i] -> type = 1;
            g[i] -> num = i;
            g[i] -> flag = 0;
            vis[i] = 0;
        }
        for (int i = 1; i <= m; i++){
            char s;
            int x, y;
            cin >> s;
            if (s == 'T' || s == 'F' || s == 'U'){
                cin >> x;
                if (s == 'T') {
                    g[x] -> flag = 1, g[x] -> val = NULL; }
                if (s == 'F') g[x] -> flag = -1, g[x] -> val = NULL;
                if (s == 'U') change(x, 0);
            }
            else if (s == '+'){
                cin >> x >> y;
                change(x, y);
            }
            else{
                cin >> x >> y;
                change(x, -y);
            }
        }
        bool flag = true;
        while (flag){
            flag = false;
            for (int i = 1; i <= n; i++)
                flag = flag || mf(g[i], i);
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (g[i] -> type == 0);
        cout << cnt << endl;
    }
    return 0;
}
