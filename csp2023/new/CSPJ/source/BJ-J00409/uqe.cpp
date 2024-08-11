# include <iostream>
using namespace std;

int T, M, a[5001], b[5001], c[5001];

int main()
{
    ifstream("uqe.in");
    ofstream("uqe.out");
    scanf("%d %d", &T, &M);
    for (int i = 0; i < T; i++)
        scanf("%d %d %d", a[i], b[i], c[i]);

    for (int i = 0; i < T; i++) {
        if (b[i]*b[i] - 4*a[i]*c[i] < 0)
            printf("NO");
        else printf();
    }
    return 0;
}
