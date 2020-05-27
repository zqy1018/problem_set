#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, q;
int a[200005], siz1, siz, _a, _b;
ll seg0[400005][2], seg1[400005][2];
char opr[3];
void maintain(int id, ll seg[][2]){
    seg[id][0] = seg[id << 1][0] + seg[id << 1 | 1][0];
    seg[id][1] = seg[id << 1][1] + seg[id << 1 | 1][1];
}
void update(int k, int ori_k, int v, int ori_v, ll seg[][2]){
    int p = k + siz1 - 1;
    ll orv = 1ll * ori_k * ori_v, nwv = 1ll * ori_k * v;
    while (p > 0){
        seg[p][0] -= orv, seg[p][0] += nwv;
        seg[p][1] -= ori_v, seg[p][1] += v;
        p >>= 1;
    }
}
ll query1(int id, int l, int r, ll seg[][2]){
    if (l > _b || r < _a) return 0;
    if (l >= _a && r <= _b) return seg[id][0];
    int mid = (l + r) >> 1;
    return query1(id << 1, l, mid, seg) + query1(id << 1 | 1, mid + 1, r, seg);
}
ll query(int id, int l, int r, ll seg[][2]){
    if (l > _b || r < _a) return 0;
    if (l >= _a && r <= _b) return seg[id][1];
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, seg) + query(id << 1 | 1, mid + 1, r, seg);
} 
void init(){
    n = read(), q = read();
    memset(seg0, 0, sizeof(seg0));
    memset(seg1, 0, sizeof(seg1));
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    if (n & 1) a[++n] = 0;
    for (siz1 = 1; siz1 < (n >> 1); siz1 <<= 1)
        ;
    for (int i = 1; i <= n; i += 2)
        seg1[((i + 1) >> 1) + siz1 - 1][0] = 1ll * i * a[i], 
        seg1[((i + 1) >> 1) + siz1 - 1][1] = a[i], 
        seg0[((i + 1) >> 1) + siz1 - 1][0] = 1ll * (i + 1) * a[i + 1], 
        seg0[((i + 1) >> 1) + siz1 - 1][1] = a[i + 1];
    for (int i = siz1 - 1; i >= 1; --i)
        maintain(i, seg0), maintain(i, seg1);
}
void solve(){
    ll ans = 0;
    while (q--){
        scanf("%s", opr);
        int u = read(), v = read();
        if (opr[0] == 'U'){
            if (u & 1){
                update((u + 1) >> 1, u, v, a[u], seg1);
            }else {
                update(u >> 1, u, v, a[u], seg0);
            }
            a[u] = v;
        }else {
            ll res2, res3;
            int len = v - u + 1;
            int len1 = (len + 1) >> 1;
            int len2 = len - len1;
            if (u & 1){
                _a = (u + 1) >> 1, _b = _a + len1 - 1;
                res2 = query1(1, 1, siz1, seg1) - 1ll * (u - 1) * query(1, 1, siz1, seg1);
                _a = (u + 1) >> 1, _b = _a + len2 - 1;
                res3 = 1ll * (u - 1) * query(1, 1, siz1, seg0) - query1(1, 1, siz1, seg0);
            }else {                
                _a = u >> 1, _b = _a + len1 - 1;
                res2 = query1(1, 1, siz1, seg0) - 1ll * (u - 1) * query(1, 1, siz1, seg0);
                _a = (u + 2) >> 1, _b = _a + len2 - 1;
                res3 = 1ll * (u - 1) * query(1, 1, siz1, seg1) - query1(1, 1, siz1, seg1);
            }
            ans += res2 + res3;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    int T = read();
    for (int i = 1; i <= T; ++i){
        printf("Case #%d: ", i);
        init();
        solve();
    }
}