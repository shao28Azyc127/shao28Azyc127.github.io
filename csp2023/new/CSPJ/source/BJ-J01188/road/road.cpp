#include <cstdio>
#include <iostream>
#include <vector>


unsigned int ceilDiv(unsigned int a, unsigned int b){
    if (a%b){  //has mod, +1
        return a/b + 1;
    }
    else{
        return a/b;
    }
}


int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    unsigned int n/*num*/=-1, d/*dis per liter*/=-1; std::cin >> n >> d;
    std::vector<unsigned int> v/*distances*/(n-1, 0), a/*prices*/(n, 0);
    for (unsigned int i=0; i<v.size(); ++i){
        std::cin >> v[i];
    }
    for (unsigned int i=0; i<a.size(); ++i){
        std::cin >> a[i];
    }

    //std::vector<unsigned int> liters(n, 0);
    unsigned long long int totalPrice=0;
    unsigned int minPriceI=0, extraDis=0, liter=-1;
    for (unsigned int i=0; i<n-1; ++i){  //be careful with v, len(v)=n-1, not n.
        if (a[i]<a[minPriceI]){
            minPriceI = i;
        }
        liter = ceilDiv(v[i]-extraDis, d);
        totalPrice += (unsigned long long int)(a[minPriceI])*liter;
        extraDis = d*liter/*~v[i]-extraDis, in U*/-(v[i]-extraDis);
    }
    std::cout << totalPrice << "\n";
    return 0;
}
