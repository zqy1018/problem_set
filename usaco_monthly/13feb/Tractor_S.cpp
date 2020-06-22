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
 
int n, a[505][505], maxi, mini;
bool vis[505][505];
queue<int> qx, qy;
int bfs(int x, int y, int d){
    int cnt = 0;
    vis[x][y] = true;
    qx.push(x), qy.push(y);
    while (!qx.empty()){
        x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        ++cnt;
        for (int i = 0; i < 4; ++i){
            int cx = x + dx[i], cy = y + dy[i];
            if (cx <= 0 || cy <= 0 || cx > n || cy > n)
                continue;
            if (vis[cx][cy] || abs(a[x][y] - a[cx][cy]) > d)
                continue;
            vis[cx][cy] = true;
            qx.push(cx), qy.push(cy);
        }
    }
    return cnt;
}
void init(){
    n = read();
    maxi = INT_MIN, mini = INT_MAX;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            a[i][j] = read();
            maxi = max(maxi, a[i][j]);
            mini = min(mini, a[i][j]);
        }
}
void solve(){
    int l = 0, r = maxi - mini;
    int hf = (n * n + 1) >> 1;
    while (r > l){
        int mid = (l + r) >> 1;
        memset(vis, 0, sizeof(vis));
        bool flag = false;
        for (int i = 1; i <= n && !flag; ++i)
            for (int j = 1; j <= n && !flag; ++j){
                if (!vis[i][j]){
                    flag = (bfs(i, j, mid) >= hf) || flag;
                }
            }
        if (flag) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
}
int main(){
    init();
    solve();
    return 0;
}