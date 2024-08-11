#include <cmath>
#include <cstdio>
#include <iostream>


//use special: C
int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    unsigned int t=-1, m=-1; std::cin >> t >> m;
    int a=-1, b=-1, c=-1;
    long double delta=-1;
    for (unsigned int i=0; i<t; ++i){
        std::cin >> a >> b >> c;
        delta = std::pow((long double)(b), 2) - (long double)(4)*a*c;
        if (delta>=0){
            std::cout << (long long int)std::round(((long double)(-b)+std::sqrt(delta))/(2*a)) << "\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
    return 0;
}
