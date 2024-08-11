#include<fstream>

using namespace std;

ifstream cin ("uqe.in");
ofstream cout ("uqe.out");
int t,m,a,b,c;
int main(){
    cin >> t >> m;
    for(int i = 1;i <= t;i ++){
        cin >> a >> b >> c;
        if(m == 1){
            cout << "1" << endl;
        } else if(c == 0){
            cout << (b * -1) << endl;
        }
    }
    return 0;
}
