#include<bits/stdc++.h>
using namespace std;
struct node{
    int op,x,y;
}b[100001];

int c,t,n,m;
int a[100001],e[100001];
int ans,sum;

void fun(){
    while(t--){
        ans = INT_MAX;
        cin>>n>>m;
        for(int i = 1;i <= n;i++){
            a[i] = 1;
            e[i] = 1;
        }
        char x;
        for(int i = 0;i < m;i++){
            cin>>x;
            if(x == 'T'){
                b[i].op = 1;
                cin>>b[i].x;
            }
            if(x == 'F'){
                b[i].op = 2;
                cin>>b[i].x;
            }
            if(x == 'U'){
                b[i].op = 3;
                cin>>b[i].x;
            }
            if(x == '+'){
                b[i].op = 4;
                cin>>b[i].x>>b[i].y;
            }
            if(x == '-'){
                b[i].op = 5;
                cin>>b[i].x>>b[i].y;
            }
        }
        int t = pow(3,n);
        for(int k = 0;k < t;k++){
            for(int j = 0;j < m;j++){
                if(b[j].op == 1){
                    e[b[j].x] = 1;
                }
                if(b[j].op == 2){
                    e[b[j].x] = 2;
                }
                if(b[j].op == 3){
                    e[b[j].x] = 3;
                }
                if(b[j].op == 4){
                    e[b[j].x] = e[b[j].y];
                }
                if(b[j].op == 5){
                    if(e[b[j].y] == 1){
                        e[b[j].x] = 2;
                    }else if(e[b[j].y] == 2){
                        e[b[j].x] = 1;
                    }else if(e[b[j].y] == 3){
                        e[b[j].x] = 3;
                    }
                }
            }
            bool f = true;
            for(int i = 1;i <= n;i++){
                if(e[i] != a[i]){
                    f = false;
                }
            }
            if(f == true){
                ans = min(ans,sum);
            }
            a[1]++;
            sum = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] == 4){
                    a[i] = 1;
                    a[i+1]++;
                }
                if(a[i] == 3){
                    sum++;
                }
                e[i] = a[i];
            }
        }
        cout<<ans<<'\n';
    }
    return ;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c <= 2 || c >= 7){
        fun();
    }
    if(c == 3 || c == 4){
        while(t--){
            ans = 0;
            cin>>n>>m;
            for(int i = 1;i <= n;i++){
                a[i] = 0;
            }
            char x;
            int y;
            for(int i = 0;i < m;i++){
                cin>>x>>y;
                if(x == 'T'){
                    a[y] = 1;
                }
                if(x == 'F'){
                    a[y] = 2;
                }
                if(x == 'U'){
                    a[y] = 3;
                }
            }
            for(int i = 1;i <= n;i++){
                if(a[i] == 3){
                    ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    if(c == 5 || c == 6){
        while(t--){
            ans = 0;
            cin>>n>>m;
            for(int i = 1;i <= n;i++){
                a[i] = 0;
            }
            for(int i = 0;i < m;i++){
                char c;
                int x,y;
                cin>>c;
                if(c == 'U'){
                    cin>>x;
                    a[x] = 3;
                }
                if(c == '+'){
                    cin>>x>>y;
                    a[x] = a[y];
                }
            }
            for(int i = 1;i <= n;i++){
                if(a[i] == 3){
                    ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
