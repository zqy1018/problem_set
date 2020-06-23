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

int n, m, D = 0;
unordered_map<int, int> mp;
vector<int> G[250005];
vector<int> G2[250005];
int cnt[250005] = {0};
queue<int> q;
bool vis[1000005] = {0};
void init(){
    n = read(), m = read();
    REP(i, 1, m){
        int t = read();
        cnt[i] = t;
        REP(j, 1, t){
            int u = read();
            if (!mp.count(u)) mp[u] = ++D;
            G[mp[u]].push_back(i);
            G2[i].push_back(u);
        }
    }
}
int sc(int x){
    for (int t: G2[x]){
        if (!vis[t]) return t;
    }
    return 0;
}
void solve(){
    q.push(1);
    vis[1] = true;
    int ans = 0;
    while (!q.empty()){
        int h = q.front();
        q.pop();
        ++ans;
        auto& v = G[mp[h]];
        for (int x: v){
            --cnt[x];
            if (cnt[x] == 1){
                int t = sc(x);
                if (t > 0)
                    vis[t] = true, q.push(t);
            }
        }
    }
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}