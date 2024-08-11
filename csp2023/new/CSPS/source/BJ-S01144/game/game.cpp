#include<bits/stdc++.h>

using namespace std;

long long n,ans = 0,maxl = -1;
string s;
map<string,bool> m;

bool check(long long a,long long b){
    if(b == 2){
        return s[a]==s[a+1]?true:false;
    }
    if(b<=maxl){
        string ss = "";
        for(long long i = a;i<=a+b-1;i++){
            ss+=s[i];
        }
        return m[ss]?true:false;
    }
    bool flag = true;
    for(long long aa = a;aa<=a+b-1;aa+=2){
        for(long long i = maxl;i>=2;i--){
            flag = true;
            if(check(aa,i)){
                flag = check(aa+i-1,b-i);
                if(!flag){
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    for(long long i = 2;i<=n;i+=2){
        for(long long j = 0;j<s.length()&&(j+i-1)<s.length();j++){
            bool flag = true;
            for(long long l = j,r = j+i-1;l<=r;l++,r--){
                if(s[l]!=s[r]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
                maxl = max(maxl,i);
                string ss = "";
                for(long long k = j;k<=j+i-1;k++){
                    ss+=s[k];
                }
                m[ss] = true;
            }
        }
    }
    for(long long i = maxl+2;i<=n;i+=2){
        for(long long j = 0;j<s.length()&&(j+i-1)<s.length();j++){
            bool flag = check(j,i);
            if(flag){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
