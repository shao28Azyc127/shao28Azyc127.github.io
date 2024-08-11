#include<bits/stdc++.h>
#define maxn 100001
using namespace std;

char x[maxn], initial_x[maxn];
int c, t;
int n, m;
int ans;
char instruction[maxn];
int oprand[maxn][2];

char reverse(char a){
    if(a == 'T') return 'F';
    if(a == 'F') return 'T';
    if(a == 'U') return 'U';
    return 'U';
}

void addtion(int a, int b){
    x[a] = x[b];
}

void subtraction(int a, int b){
    x[a] = reverse(x[b]);
}


void dfs(int index){
    if(index == n+1){
        for(int i = 1; i <= n ;i++){
            x[i] = initial_x[i];
        }
        for(int i = 1; i <= m; i++){
            if(instruction[i] == '+') addtion(oprand[i][0], oprand[i][1]);
            else if(instruction[i] == '-') subtraction(oprand[i][0], oprand[i][1]);
            else x[i] = instruction[i];
        }
        int unknown = 0;
        for(int i = 1; i <= n; i++){
            if(x[i] == 'U') unknown++;
            if(x[i] != initial_x[i]) return;
        }
        /*if(ans > unknown){
            for(int i = 1; i <= n; i++){
                cout << x[i];
            }
            cout << endl;
            for(int i = 1; i <= n; i++){
                cout << initial_x[i];
            }
            cout << endl << endl;
        }*/
        ans = min(ans, unknown);
        return;
    }
    initial_x[index] = 'T';
    dfs(index+1);
    initial_x[index] = 'F';
    dfs(index+1);
    initial_x[index] = 'U';
    dfs(index+1);
}

int main(){

    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    cin >> c >> t;
    while(t > 0){
        ans = 9999999;
        cin >> n >> m;
        
        for(int i = 1; i <= m; i++){
            cin >> instruction[i];
            if(instruction[i] == '+' || instruction[i] == '-') cin >> oprand[i][0] >> oprand[i][1];
            else cin >> oprand[i][0];
        }
        dfs(1);

        t--;
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}