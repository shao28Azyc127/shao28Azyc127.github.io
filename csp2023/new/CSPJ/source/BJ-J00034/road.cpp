#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct station {
    int price;
    int number;
    int vtonext;
};

vector<station> stations;
vector<int> dvs;

int getStaOrder(int number) {
    for(int i = 0; i < stations.size(); i++) {
        if(stations[i].number == number) return i;
    }
    return -1;
}

int getNerStaNum(int curorder) {
    if(curorder == 0) return -1;
    for(int i = stations[curorder].number; i < stations.size(); i++) {
        if(getStaOrder(i) < curorder) {
            
            return i;
        }
    }
    return -1;
}

int dissum(int stan, int endn) {
    int sum = 0;

    for(int i = stan; i < endn; i++) {
        sum += stations[getStaOrder(i)].vtonext;
    }
    return sum;
}

bool staCmp(station a, station b) {
    return a.price < b.price;
}

inline int divideplus(int a, int b) {
    int c = a/b;
    if(c*b != a) return c + 1;
    return c;
}

inline int sswr(float n) {
    if(n < 0.5f) return (int)n;
    return (int)n + 1;
}

int main() {
    station cs;
    int n, d, ci = 0;
    ifstream is("road.in");
    ofstream os("road.out");

    is >> n >> d;
    for(int i = 1; i < n; i++) {
        is >> ci;
        dvs.push_back(ci);
    }

    for(int i = 0; i < n; i++) {
        is >> ci;
        cs.price = ci;
        if(i == n - 1) cs.vtonext = 0;
        else cs.vtonext = dvs[i];
        cs.number = i;
        stations.push_back(cs);
    }

    sort(stations.begin(), stations.end(), staCmp);

    float curo= 0;
    int totpl, tmp = 0;
    
    for(int i = 0; i < n; i++) {
        if(i != 0) curo -= (float)stations[getStaOrder(i - 1)].vtonext / (float)d;
        //cout << "OILMINUS" << curo << endl;
        if(curo >= (float)stations[getStaOrder(i)].vtonext / (float)d) continue;
        if(getStaOrder(i + 1) <= getStaOrder(i)) { //cur sta much expensive
            tmp = (divideplus(stations[getStaOrder(i)].vtonext, d) - sswr(curo));
            if(tmp + curo < (float)stations[getStaOrder(i)].vtonext / (float)d)tmp++;
            curo += tmp;
            totpl += tmp * stations[getStaOrder(i)].price;
            //cout << "1ON STA " << i << "[[[" << curo << "]]]" << " , new oil " << tmp << " costs " << totpl << " price: " << stations[getStaOrder(i)].price << endl;
        }
        if(getStaOrder(i + 1) > getStaOrder(i)) { //cur sta cheap
            if(getNerStaNum(getStaOrder(i)) == -1) {
                tmp = (divideplus(dissum(i, n - 1), d) - sswr(curo));
                if(tmp + curo < (float)dissum(i, n - 1) / (float)d)tmp++;
                curo += tmp;
                totpl += tmp * stations[getStaOrder(i)].price;
                //cout << "2ON STA " << i << "[[[" << curo << "]]]" << " , new oil " << tmp << " costs " << totpl << " price: " << stations[getStaOrder(i)].price << endl;
                continue;
            }
            else {
                tmp = (divideplus(dissum(i, getNerStaNum(getStaOrder(i))), d) - sswr(curo));
                if(tmp + curo < (float)dissum(i, getNerStaNum(getStaOrder(i))) / (float)d)tmp++;
                //cout << dissum(i, getNerStaNum(getStaOrder(i))) << endl;
                curo += tmp;
                totpl += tmp * stations[getStaOrder(i)].price;
                //cout << "3ON STA " << i << "[[[" << curo << "]]]" << "MOVING TO STA " << getNerStaNum(getStaOrder(i)) << "WAY " << dissum(i, getNerStaNum(getStaOrder(i))) << " , new oil " << tmp << " costs " << totpl << " price: " << stations[getStaOrder(i)].price << endl;
            }
            
        }
    }
    os << totpl << endl;
    is.close();
    os.close();
    return 0;
}