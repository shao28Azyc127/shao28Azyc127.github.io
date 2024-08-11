#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<char,int> pci;
typedef long long ll;
string s;
stack<pci>p;
void out()
{
    cout << "\nstack:\n";
    stack<pci>k;
    while(!p.empty()){
        cout << p.top().fi << " " << p.top().se << endl;
        k.push(p.top());
        p.pop();
    }
    while(!k.empty()){
        p.push(k.top());
        k.pop();
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    ll ans = 0;
    cin >> n >> s;
    char h = '-';
    int num = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == h)num++;
        else{
            if(num > 2){
                // cout << "num: " << num << endl;
                char kkk[2];
                kkk[0] = h,kkk[1] = '&';
                int now = 0;
                for(int j = i-1-(num&1);j > i-num;j -= 2){
                    s[j] = s[j-1] = kkk[now];
                    now = now^1;
                }
                int ret = 0,nowl = 2;
                while(nowl <= num){
                    ret += (num-nowl+1)/2;
                    nowl += 2;
                }
                ans += ret;
                // cout << i << " " << ans << endl;
            }
            h = s[i],num = 1;
        }
    }
    // cout << "\ndone\n\n";
    if(num > 2){
        char kkk[2];
        kkk[0] = h,kkk[1] = '&';
        int now = 0;
        for(int j = n-1-(num&1);j > n-num;j -= 2){
            s[j] = s[j-1] = kkk[now];
            now = now^1;
        }
        int ret = 0,nowl = 2;
        while(nowl <= num){
            ret += (num-nowl+1)/2;
            nowl += 2;
        }
        ans += ret;
    }
    // cout << s << endl;
    int i = 0,twsum = 0,lsttw = -1,lstonepop = '*';
    while(i < n){
        bool tw = false;
        int lst = -1,ret = 0;
        char onepop = '*';
        bool one = false,yes = true;
        while(!p.empty() && p.top().fi == s[i]){
            if(!one)onepop = s[i],one = true;
            else yes = false;
            lst = p.top().se-1;
            p.pop();
            i++;
            tw = true;
            ret++;
            // cout << "\nclear then: ";
            // out();
        }
        if(onepop != '*' && yes)lstonepop = onepop;
        ans += ret;
        // cout << "ans: " << ans << endl;
        if(tw){
            if(!twsum)lsttw = lst,twsum++;
            else if((lsttw == -1 && p.empty()) || p.top().se == lsttw)twsum++;
            else ans += (ll)twsum*(twsum-1)/2,lsttw = lst,twsum = 1;
        }
        if(lstonepop == s[i] && ((lsttw == -1 && p.empty()) || p.top().se == lsttw)){
            ans += (ll)twsum*(twsum-1)/2;
            twsum = 1;
            // cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
        }
        else p.push(pci(s[i],i));
        i++;
        // out();
        // cout << "twsum: " << twsum << "\nlsttw: " << lsttw << "\nans: " << ans << endl;
    }
    if(twsum)ans += (ll)twsum*(twsum-1)/2;
    cout << ans;
    return 0;
}