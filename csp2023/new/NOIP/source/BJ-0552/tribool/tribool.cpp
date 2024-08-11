#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct tribool{
    short k;
    tribool (){
        k = -2;
    }
    int n() {
        if ((*this).k == -2){
            return 2;
        }
        if ((*this).k == -1){
            return -1;
        }
        if ((*this).k == 0){
            return 1;
        }
        if ((*this).k == 1){
            return 0;
        }
        if ((*this).k == 2){
            return -2;
        }
    }
};

struct varible{
    int debug_n;
    varible* root;
    varible* last_root;
    bool is_root;
    tribool value;
    bool state, last_state;// 0 - 1 +
    varible(){
        root = NULL;
        last_root = NULL;
        is_root = 1;
        value = tribool();
        state=1;
        last_state = 1;
    }
    // void set_root(varible* root){
    //     if (!(*root).is_root){
            
    //     }
    // }
    varible* get_root(){
        if ((*this).root == NULL){
            return this;
        }
        if (!(*(*this).root).is_root){
            // cout << this->debug_n << " " << this->root->get_root()->debug_n << endl;
            if ((*this).root == (*(*this).root).get_root()){
                // cout << this->debug_n << endl;
                this->root = NULL;
                return this;
            }
            (*this).root = (*(*this).root).get_root();
            // cout << this->debug_n << " " << this->root->debug_n << endl;
        }
        return (*this).root;
    }
    tribool* get_value(){
        return &(*(*this).get_root()).value;
    }
};

namespace _1_2{
    int main(){
        int t;
        cin >> t;
        while (t--){
            int n,m;
            cin >> n >> m;
            varible x[n+5];
            ////// debug
            for (int i=0;i<n+5;i++){
                x[i].debug_n = i;
            }
            /////// debug
            while (m--){
                char op;
                int i;
                cin >> op >> i;
                if (op == '+'){
                    int j;
                    cin >> j;
                    if (i == j){
                        continue;
                    }
                    x[i].is_root = 0;
                    x[i].last_root = x[i].root;
                    x[i].last_state = x[i].state;
                    if (x[j].is_root){
                        x[i].root = &x[j];
                    }
                    else{
                        x[i].root = x[j].get_root();
                    }
                    x[i].state = x[j].state;
                    // cout << i << " " << j << " " << x[i].get_root()->debug_n << " " << x[j].get_root()->debug_n << endl;
                    if (((x[i].root == x[i].last_root) || (x[i].last_root == NULL && x[i].root ==  &x[i])) && x[i].state != x[i].last_state){
                        (*x[i].get_value()).k = -1;
                    }
                }
                else if (op == '-'){
                    int j;
                    cin >> j;
                    if (i == j){
                        goto flag1;
                    }
                    x[i].is_root = 0;
                    x[i].last_root = x[i].root;
                    x[i].last_state = x[i].state;
                    if (x[j].is_root){
                        x[i].root = &x[j];
                    }
                    else{
                        x[i].root = x[j].get_root();
                    }
                    x[i].state = !x[j].state;
                    if (((x[i].root == x[i].last_root) || (x[i].last_root == NULL && x[i].root == &x[i])) && x[i].state != x[i].last_state){
                        flag1:;
                        (*x[i].get_value()).k = -1;
                    }
                }
                else if (op == 'T'){
                    x[i].is_root = 1;
                    x[i].root = NULL;
                    x[i].value = tribool();
                    x[i].value.k = 1;
                }
                else if (op == 'F'){
                    x[i].is_root = 1;
                    x[i].root = NULL;
                    x[i].value = tribool();
                    x[i].value.k = 0;
                }
                else{
                    x[i].is_root = 1;
                    x[i].root = NULL;
                    x[i].value = tribool();
                    x[i].value.k = -1;
                }
            }
            // if (x[i].get_root() == &x[i] && x[i].state != x[i].get_root()->state){
            //     (*x[i].get_value()).k = -1;
            // }
            int ans=0;
            for (int i=1;i<=n;i++){
                if ((*x[i].get_value()).k == -1){
                    ans++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
}

namespace _3_4{
    int main(){
        int t;
        cin >> t;
        while (t--){
            int n,m;
            cin >> n >> m;
            tribool x[n+5];
            while (m--){
                char op;
                int i;
                cin >> op >> i;
                if (op == 'T'){
                    x[i].k = 1;
                }
                else if (op == 'F'){
                    x[i].k = 0;
                }
                else{
                    x[i].k = -1;
                }
            }
            int ans=0;
            for (int i=1;i<=n;i++){
                if (x[i].k == -1){
                    ans++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
}

int main(){
    int c;
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c;
    if (c == 3 || c == 4){
        _3_4::main();
    }
    else{
        _1_2::main();
    }
}