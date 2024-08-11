#include<iostream>
#include<cstdio>
using namespace std;

const int N=2e6+5;

long long n,ans;
string s;
bool yes[N];

bool is_huiwen(string str) {
    long long len=str.length();
    if(len%2) return false;
    for(long long i=0;i<len/2;i++) {
        if(str[len/2-1-i]!=str[len/2+i]) return false;
    }
    return true;
}

bool _double(string str) {
    long long len=str.length();
    if(len%2) return false;
    for(long long i=0;i<len-1;i+=2) {
        if(str[i]!=str[i+1]) return false;
    }
    return true;
}

string cut(string str,long long l,long long r) {
    string s0;
    for(long long i=l;i<=r;i++) {
        s0+=str[i];
    }
    return s0;
}

bool can(long long l,long long r) {
    if((r-l+1)%4) return false;
    for(long long i=l;i<=r;i++) {
        if(!yes[i]) return false;
    }
    return true;
}

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    for(long long i=1;i<n;i++) {
        for(long long j=i-1;j>=0;j--) {
            string s0=cut(s,j,i);
            if(is_huiwen(s0) || _double(s0) || can(j,i)) {
                //cout << s0 << endl;
                ans++;
                for(int k=j;k<=i;k++) yes[k]=true;
            }
        }
    }
    cout << ans;
    return 0;
}
