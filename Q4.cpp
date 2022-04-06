/*Q4: In this question, you are given a binary string of length T. Now you need to create two
permutations of this string: S1 and S2 such that the ‘longest common subsequence’ between the two
newly created strings is smallest.
Ex: Given string: 101, you can find S1: 110 and S2: 011, The longest common subsequence between
S1 and S2 is 11 and the length is 2. There cannot be any two permutations of the given string where
the LCS is less than 2
Ex: Given 0111, then S1 should be: 1101, and S2: 0111, the smallest LCS will be 2 char long.*/




 //This code demonstrates the use of strings//

#include "bits/stdc++.h"
using namespace std;
 
#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rloop(i, a, b) for (int i = (b); i > a; --i)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define print(var) cout << var << "\n"
#define nline "\n"
#define vll vector<ll>

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;

//custom hash function for unordered_map to make it better.
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
   }
};
 
 
ll LCSubStr(string s, string t, ll n, ll m)
{

   ll dp[2][m + 1];
   memset(dp, 0, sizeof(dp));
   ll ans = 0;

   loop(i, 1, n + 1)
   {
      loop(j, 1, m + 1)
      {
         if (s[i - 1] == t[j - 1])
         {
            dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            if (dp[i % 2][j] > ans) ans = dp[i % 2][j];
         }
         else dp[i % 2][j] = 0;
      }
   }
   return ans;
}

void solve()
{
   ll n; cin >> n;
   string s; cin >> s;

   ll one = 0, zero = 0;
   loop(i, 0, n)
   {
      if (s[i] == '1') ++one;
      else ++zero;
   }

   if (n <= 2)
   {
      cout << s << nline;
      reverse(all(s));
      cout << s << nline;
      return;
   }

   string k = "", p = "";
   sort(all(s));
   k = s;
   ll x = min(one, zero) + 1;
   ll a[x];
   memset(a, 0, sizeof(a));

   if (one >= zero)
   {
      ll i = 0;
      while (one > 0)
      {
         ++a[i % x];
         ++i;
         --one;
      }
      loop(i, 0, x)
      {
         while (a[i] > 0)
         {
            p += '1';
            --a[i];
         }
         p += '0';
      }
   }
   else {
      ll i = 0;
      while (zero > 0)
      {
         ++a[i % x];
         ++i;
         --zero;
      }

      loop(i, 0, x)
      {
         while (a[i] > 0)
         {
            p += '0';
            --a[i];
         }
         p += '1';
      }
   }
   p.pop_back();
   string s1, s2;
   s1 = p;
   reverse(all(p));
   s2 = p;
   if (LCSubStr(k, s1, n, n) < LCSubStr(k, s2, n, n))
      p = s1;
   else p = s2;
   cout << k << nline;
   cout << p << nline;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // cout << fixed << setprecision(9);

   int tc = 1;
   cin >> tc;
   for (int t = 1; t <= tc; t++)
   {
      // cout << "Case #" << t << ": ";
      solve();
   }
}

