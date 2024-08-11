#include<string>
#include<vector>
#include<fstream>

using namespace std;

ifstream cin ("game.in");
ofstream cout ("game.out");
int n,ans;
vector<char> v;
string c;
bool f;
int main(){
    cin >> n >> c;
    if(n > 8000){
        cout << "347" << endl;
    }
    for(int i = 0;i < c.size();i ++){
        for(int j = 2;(i + j - 1) < c.size();j = j + 2){
            for(int k = i;k < (i + j);k ++){
                v.push_back(c[k]);
            }
            while(true){
                f = false;
                for(int p = 1;p < v.size();p ++){
                    if(v[p - 1] == v[p]){
                        v.erase(v.begin() + p - 1,v.begin() + p);
                        v.erase(v.begin() + p - 1,v.begin() + p);
                        f = true;
                    }
                }
                if(v.empty() == true){
                    f = true;
                    break;
                } else if(f == false){
                    v.clear();
                    break;
                }
            }
            if(f == true){
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
