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
int n, k, a[200005];
void init(){
    n = read(), k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve(){
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] == k){
            int j = i;
            while (j <= n && j < i + k && a[i] - a[j] == j - i)
                ++j;
            if (j == i + k)
                ++ans, i = j - 1;
        }
    }
    printf("%d\n", ans);
}
int main(){
    int T = read();
    for (int i = 1; i <= T; ++i){
        printf("Case #%d: ", i);
        init();
        solve();
    }
    return 0;
}