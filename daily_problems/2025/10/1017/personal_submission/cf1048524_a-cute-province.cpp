#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
void solve()
{
   int n;
    cin >> n;
   set<int> all;
   all.insert(0);
   auto dfs = [&](auto &dfs, int num, int fl)->void{
    if(num > n)return ;
    all.insert(num);
    if(!fl){
        int x = num%10;
        for(int j = 0; j < 10; j ++){
            if(j != x)dfs(dfs, num*10 + j, 1);
            else dfs(dfs, num*10 + j, 0);
        }
    }
    else{
        set<int> now;
        int x = num;
        while(x){
            now.insert(x%10);
            x /= 10;
        }
        dfs(dfs, num*10 + *now.begin(), 1);
        dfs(dfs, num*10 + *now.rbegin(), 1);
    }
   };
   for(int i = 1; i < 10; i ++)
   dfs(dfs, i, 0);
   int ans = 0;
   for(auto u : all){
    if(2*u > n)break;
    auto w = all.lower_bound(n-u);
    if(w != all.end() && *w == n-u){
        //cout << u <<' ' << n-u << '\n';
        ans ++ ;
    }
   }
   cout << ans << '\n';

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
