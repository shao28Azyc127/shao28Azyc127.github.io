#include<iostream>
#include<string>
#include<stack>
#include<cstdio>
#include<map>
using namespace std;

int n,cnt,cur;
int c[30];
string s;
string t[1000002];
map<string,bool> mp;
struct stac{
    int v=0;
    char val[2000005];
    bool empt(){
        return v==0;
    }
    char top(){
        return val[v];
    }
    void push(char x){
        val[++v]=x;
    }
    void pop(){
        v--;
    }
};
/*
bool check(string t){
    if(t.size()%2) return 0;
    stac st;
    int len=t.size();

    for(int i = 0;i < len;i++){
        if(st.empt()||t[i]!=st.top()){
            st.push(t[i]);
        }
        else{
            st.pop();
        }
    }

    if(st.empt()) return 1;
    else return 0;
}*/

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;

    for(int i = 0;i < n;i++){
       c[s[i]-'a']++;
    }

    for(int i = 0;i < n;i++){
        if(c[s[i]-'a']==1) continue;
        for(int j = i+1;j < n;j++){
            if(c[s[j]-'a']==1) break;
            if((j-i+1)%2==1) continue;
            string temp=s.substr(i,j-i+1);
            if(mp[temp]==1){
                 cnt++;
                 continue;
            }
            t[++cur]=temp;


        }
    }

    for(int i = 1;i <= cur;i++){
            string k=t[i];
            if(mp[k]==1){
                 cnt++;
                 continue;
            }
            stac st;
            for(int p = 0;p < k.size();p++){
                if(st.empt()||k[p]!=st.top()){
                    st.push(k[p]);
                }
                else st.pop();
            }

            if(st.empt()){
                cnt++;
                mp[k]=1;
            }
    }

    cout << cnt << endl;
    return 0;
}
