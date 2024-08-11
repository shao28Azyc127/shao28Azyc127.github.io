#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string str[3001];
string min_string[3001];
string max_string[3001];

bool smaller_than(string& a, string& b) {
    for(int i = 0; i < m; i++) {
        if(a[i] < b[i]) return true;
    }
    return false;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    int last_max_id, last_min_id, first_max_id, first_min_id;
    char last_max, last_min, first_max, first_min;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        last_max = 'a';
        last_min = 'z';
        last_max_id = m - 1;
        last_min_id = m - 1;
        first_max_id = 0;
        first_min_id = 0;
        for(int j = m - 1; j >= 0; j--) {
            if(str[i][j] > last_max) {
                last_max = str[i][j];
                last_max_id = j;
            }
            if(str[i][j] < last_min) {
                last_min = str[i][j];
                last_min_id = j;
            }
        }
        for(int j = 0; j < m; j++) {
            if(str[i][j] > last_min) {
                first_max_id = j;
                break;
            }
        }
        for(int j = 0; j < m; j++) {
            if(str[i][j] < last_max) {
                first_min_id = j;
                break;
            }
        }
        //cout << first_max_id << " " << first_min_id << endl;
        //cout << last_max_id << " " << last_min_id << endl;
        min_string[i] = str[i];
        max_string[i] = str[i];
        if(first_max_id < last_min_id) {
            swap(min_string[i][first_max_id], min_string[i][last_min_id]);
        }
        if(first_min_id < last_max_id) {
            swap(max_string[i][first_min_id], max_string[i][last_max_id]);
        }
        //cout << min_string[i] << endl;
        //cout << max_string[i] << endl;
    }
    for(int i = 0; i < n; i++) {
        int flag = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(!smaller_than(min_string[i], max_string[j])) {
                cout << 0;
                flag = 0;
                break;
            }
        }
        if(flag == 1) cout << 1;
    }
    cout << endl;
    return 0;
}
