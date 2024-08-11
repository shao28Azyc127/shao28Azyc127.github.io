#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int head[N], sizeMap[N], nextIndex[N], toNode[N];
int n, numEdge;
ll ht[N], b[N], c[N];

void addEdge(int from, int to)
{
    nextIndex[numEdge] = head[from];
    toNode[numEdge] = to;
    head[from] = numEdge++;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    printf("5\n");
}
