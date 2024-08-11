#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string s;
long long ans=0;

bool check(int l,int r){
    stack<char> st;
    for (int i=l;i<=r;i++){
        if (st.empty()) st.push(s[i]);
        else if (st.top()==s[i]) st.pop();
        else st.push(s[i]);
    }
    return st.empty();
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    for (int i=0;i<s.size();i++){
        for (int j=i;j<s.size();j++){
            if (check(i,j)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
