#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> intpair;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= MOD ? x + y - MOD: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}
template<typename T>
T gcd(T a, T b){
    return (!b) ? a: gcd(b, a % b);
}
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/

int n, m, r;
int a[40005], b[40005];
intpair pp[100005];
int f[40005] = {0}, g[40005] = {0};
void init(){
    n = read(), m = read(), r = read();
    REP(i, 1, n) {
        a[i] = read();
    }
    REP(i, 1, m) {
        b[i] = read();
    }
    REP(i, 1, r){
        pp[i].first = read(), pp[i].second = read();
    }
    sort(pp + 1, pp + r + 1);
}
void solve(){
    int ans = 0, cur = 1;
    REP(i, 1, m){
        g[i] = b[i];
    }
    REP(i, 1, n){
        f[i] = a[i];
        while (cur <= r && pp[cur].first == i){
            int v = pp[cur].second;
            int tmpg = g[v];
            g[v] = max(g[v], b[v] + f[i]);
            f[i] = max(f[i], tmpg + a[i]);
            ++cur;
        }
        ans = max(ans, f[i]);
    }
    REP(i, 1, m){
        ans = max(ans, g[i]);
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}