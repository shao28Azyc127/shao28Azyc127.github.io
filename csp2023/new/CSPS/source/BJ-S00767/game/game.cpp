#include<bits/stdc++.h>
using namespace std;
struct _Data{
    char ch;
    int pos;
   // int real_pos;
};
//bool flags[2000010];
int unsolved_cnt = 0;
int block_cnt = 0;
int ans = 0;
stack<_Data> datas;
//we can delete flags completely huh
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        if(i != 0 && unsolved_cnt == 0){
            block_cnt ++;
        }
        if(i+1 < n && str[i] == str[i+1]){
            ans ++;
            //cout<<i<<' '<<ans<<endl;
            //flags[i] = true;
            //flags[i+1] = true;
            i ++;
            continue;
        }
        //cout<<6<<endl;
        if((!datas.empty()) && str[i] == datas.top().ch && unsolved_cnt == datas.top().pos){
            //flags[datas.top().real_pos] = true;
            //flags[i] = true;
            unsolved_cnt --;
            //cout<<"unsolved_cnt: "<<unsolved_cnt<<endl;
            ans ++;
            //cout<<"second:"<<' '<<i<<' '<<ans<<endl;
            datas.pop();
            continue;
        }
        //cout<<"wow"<<endl;
        _Data _data;
        _data.ch = str[i];
        _data.pos = ++ unsolved_cnt;
        //cout<<"unsolved_cnt: "<<unsolved_cnt<<endl;
        //_data.real_pos = i;
        datas.push(_data);
    }
    if(unsolved_cnt == 0) block_cnt ++;
    //cout<<"cycle ans:"<<ans<<endl;
    //cout<<"block cnt:"<<block_cnt<<endl;
    ans += ((block_cnt - 1) * block_cnt / 2);
    cout<<ans;
    return 0;
}
