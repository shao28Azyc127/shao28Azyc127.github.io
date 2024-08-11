#include <fstream>
#include <vector>

using namespace std;

vector<int> apples;

bool isnull(vector<int> aa) {
    for(int i = 1; i < aa.size(); i++) {
        if(aa[i] != -1) return false;
    }
    return true;
}

int main() {
    int n = 0;
    ifstream is("apple.in");
    ofstream os("apple.out");
    is >> n;
    is.close();
    apples.push_back(0);
    for(int i = 1; i <= n; i++) {
        apples.push_back(i);
    }
    int days = 1;
    int res = 0;
    while(!isnull(apples)) {
        for(int i = 1; i < apples.size(); ){
            if(i > apples.size()) break;
            while(apples[i] == -1 && i < apples.size()) i++;
            if(i > apples.size()) break;
            if(apples[apples.size() - 1] == n) res = days;
            apples[i] = -1;
            i++;
            while(apples[i] == -1 && i < apples.size()) i++;
            i++;
            while(apples[i] == -1 && i < apples.size()) i++;
            i++;
        }
        days++;
    }

    os << days - 1 << " " << res << endl;
    os.close();
    return 0;
}