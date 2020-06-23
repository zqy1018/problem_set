#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar(); }
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
bool in[100005] = {0};
int n, k, ans = 0;
pair<int, int> p[200005];
void init(){
    n = read(), k = read();
    char ord[3];
    for(int i = 0, cur = 0; i < n; ++i){
        int st;
        scanf("%d%s", &st, ord);
        if(ord[0] == 'R') 
            p[i << 1].first = cur, p[i << 1 | 1].first = cur + st, cur += st;
        if(ord[0] == 'L') 
            p[i << 1].first = cur, p[i << 1 | 1].first = cur - st, cur -= st;
        p[i << 1].second = p[i << 1 | 1].second = i;
    }
    sort(p, p + n + n);
}
void solve(){
	int cnt = 1, lst = p[0].first;
    in[p[0].second] = 1;
    for(int i = 1; i < n + n; ++i){
        int id = p[i].second;
        if(cnt >= k) ans += p[i].first - lst;
        if(!in[id]) in[id] = 1, cnt++;
        else in[id] = 0, cnt--;
        lst = p[i].first;
    }
    printf("%d\n", ans);
}
int main(){
	init();
	solve();
	return 0;
}