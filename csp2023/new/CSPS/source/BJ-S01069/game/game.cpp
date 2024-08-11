#include<iostream>
#include<queue>
using namespace std;
int n;
queue<char> q;
int cnt;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    q.push(s[1]);
    int k=0;
    for(int i=2;i<=n;i++){
        char c=q.front();
        q.push(s[i]);
        char t=q.front();
        if(c==t){
            q.pop();
            q.pop();
            cnt++;
        }
    }
    if(q.empty()){
        cnt++;
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
