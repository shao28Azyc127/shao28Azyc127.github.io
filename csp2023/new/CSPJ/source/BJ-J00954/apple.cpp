#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    node* ft = nullptr;
    node* lt = nullptr;
    ll vel;
};

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    cin >> n;
    //cout << n;

    //scanf("%lld",&n);
    node* ding = new node;
    node* nw = ding;
    for (ll i = 1; i <= n; i++){
        node* t = new node;
        t->lt = nw;
        nw->ft = t;
        nw = nw->ft;
        nw->vel = i;
    }
    //p = p->ft;
    /*for (ll i = 1; i <= n; i++){
        cout << p->vel;
        p = p->ft;
    }
    */
    ll day = 1;
    ll use;
    while (1){
    //for (ll i = 1; i <= 2; i++){
        node* p = ding->ft;
        //cout << p->vel << endl;
        if (p == nullptr) break;
        ll t = 3;
        while (p != nullptr){
            if (t == 3){
                if (p->ft != nullptr){
                    p->ft->lt = p->lt;
                }
                p->lt->ft = p->ft;
                //printf("%lld ",n);
                if (p->vel == n){
                    //printf("%lld ",day);
                    use = day;
                }
                t = 1;
            } else {
                t++;
            }
            p = p->ft;
        }
        day++;
    }
    printf("%lld %lld",--day,use);
return 0;
}
