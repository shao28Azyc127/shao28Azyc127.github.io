#include <bits/stdc++.h>
using namespace std;

class Apple {
    public:
    int num;
    Apple *next;
};

int main() {
    freopen("./apple.in", "r", stdin);
    freopen("./apple.out", "w", stdout);

    int n;
    scanf("%d", &n);
    Apple *header = new Apple(), *current = header;
    for (int i = 1; i <= n; i++) {
        Apple *a = new Apple;
        a->num = i;
        current->next = a;
        current = a;
    }

    int days = 0, nDay = 0;
    while(header->next != NULL) {
        days++;
        current = header->next;
        Apple *prev = header;
        while(current) {
            if (current->num == n) {
                nDay = days;
            }
            prev->next = current->next;

            if (prev->next == NULL || prev->next->next == NULL || prev->next->next->next == NULL) {
                break;
            }
            prev = prev->next->next;
            current = prev->next;
        }
    }
    printf("%d %d", days, nDay);
}
