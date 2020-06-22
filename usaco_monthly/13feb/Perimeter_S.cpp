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

int n, ans = 0;
unordered_set<ull> st;
unordered_set<ull> st2;
queue<int> qx, qy;
inline ull encode(int x, int y){
    return (x + 1) * 1000000ull + (y + 1);
}
void init(){
    n = read();
    int lx = INT_MAX, ly = 0;
    REP(i, 1, n){
        int x = read(), y = read();
        st.insert(encode(x, y));
        if (x < lx) lx = x, ly = y;
        else if (x == lx) ly = min(ly, y);
    }
    qx.push(lx - 1), qy.push(ly);
    st2.insert(encode(lx - 1, ly));
}
void solve(){
    while (!qx.empty()){
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        for (int i = 0; i < 4; ++i){
            ull p = encode(x + dx[i], y + dy[i]);
            if (st.count(p)){
                ++ans;
            }else if (!st2.count(p)){
                bool flag = false;
                for (int j = 0; j < 8; ++j)
                    if (st.count(encode(x + dx[i] + ddx[j], y + dy[i] + ddy[j]))){
                        flag = true;
                        break;
                    }
                if (flag) qx.push(x + dx[i]), qy.push(y + dy[i]), st2.insert(p);
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