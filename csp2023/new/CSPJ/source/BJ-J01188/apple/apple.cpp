#include <cstdio>
#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    unsigned int n=-1; std::cin >> n;
    std::vector<bool> apples(n, 1);
    unsigned int day=0, order=-1, dayPickedLast=-1;
    for (bool finished=0; !finished; ++day){
        finished = 1;
        order = 0;
        for (unsigned int i=0; i<apples.size(); ++i){
            if (apples[i]){
                finished = 0;
                if (!order){
                    if (i == apples.size()-1){
                        dayPickedLast = day+1;
                    }
                    apples[i] = 0;
                }
                ++order;
                order %= 3;
            }
        }
    }
    day -= 1;  //last day: check if empty.
    std::cout << day << " " << dayPickedLast << "\n";
    return 0;
}
