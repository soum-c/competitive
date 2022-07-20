#include <bits/stdc++.h>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void ran() {
	srand(chrono::steady_clock::now().time_since_epoch().count());
}
long long get_rand() {
	long long a = rand();
	long long b = rand();
	return a * (RAND_MAX + 1ll) + b;
}
void usaco() {
	freopen("problem.in", "r", stdin); 
	freopen("problem.out", "w", stdout);
}
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
#define endl '\n'
#define double long double
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
// const int MOD = 998244353;
// #define cerr if(0) cerr
#define debug(x) cerr << #x << ": " << x << endl;

namespace socho_math {
	
	const long long TOO_LARGE = 1000000000ll * 1000000000ll * 4ll + 1;
	const long long FIT_INT = 1000000000ll;
	
	vector<int> generate_powers(int base, int upto) {
		upto = min(upto, TOO_LARGE);
		vector<int> result;
		if (base == 1) {
			if (1 <= upto) result.push_back(1);
		}
		else {
			for (int i=1; i<=upto; i*=base) {
				result.push_back(i);
			}
		}
		return result;
	}
	
	int gcd(int a, int b) {
		while (b > 0) {
			a %= b;
			swap(a, b);
		}
		return a;
	}
	
	int lcm(int a, int b) {
		if (a == TOO_LARGE || b == TOO_LARGE) return TOO_LARGE;
		int g = gcd(a, b);
		return min(a / g * b, TOO_LARGE);
	}
	
	bool prime(int n) {
		if (n == 1) return false;
		if (n == 2 || n == 3) return true;
		for (int i=2; i*i<=n; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	
	vector<bool> generate_primes(int n) {
		vector<bool> result(n+1, true);
		result[0] = result[1] = false;
		for (int p=2; p<=n; p++) {
			if (result[p]) {
				for (int i=p*2; i<=n; i+=p) {
					result[i] = false;
				}
			}
		}
		return result;
	}
	
	vector<int> generate_factorisations(int n) {
		vector<int> result(n+1, -1);
		vector<bool> x = generate_primes(n);
		result[0] = result[1] = 1;
		for (int p=2; p<=n; p++) {
			if (x[p]) {
				for (int i=p*2; i<=n; i+=p) {
					result[i] = p;
				}
			}
		}
		return result;
	}
	
	vector<int> factors(int n) {
		vector<int> result;
		for (int i=1; i*i<=n; i++) {
			if (n % i == 0) {
				result.push_back(i);
				if (i * i != n) result.push_back(n/i);
			}
		}
		sort(result.begin(), result.end());
		return result;
	}
	
	vector<int> prime_factorise(int n, bool distinct=false) {
		vector<int> result;
		for (int i=2; i*i<=n; i++) {
			if (distinct) {
				result.push_back(i);
				while (n % i == 0) {
					n /= i;
				}
			}
			else {
				while (n % i == 0) {
					n /= i;
					result.push_back(i);
				}
			}
		}
		if (n > 1) {
			result.push_back(n);
		}
		return result;
	}
	
	int factorial(int x, int mod=MOD) {
		if (x == 0) return 1;
		return (x * factorial(x - 1)) % mod;
	}
	
	vector<int> generate_factorials(int n, int mod=MOD) {
		vector<int> result(n+1);
		result[0] = 1;
		for (int i=1; i<=n; i++) {
			result[i] = result[i-1] * i;
			result[i] %= mod;
		}
		return result;
	}
	
	int power(int b, int e, int mod=MOD) {
		if (e == 0) return 1;
		if (e == 1) return b;
		int h = power(b, e/2, mod);
		h *= h;
		h %= mod;
		if (e % 2 == 1) h *= b;
		h %= mod;
		return h;
	}
	
	int mod_inverse(int x, int mod=MOD) {
		return power(x, mod-2, mod);
	}
	
	vector<int> generate_inverses(vector<int> source, int mod=MOD) {
		vector<int> result(source.size());
		for (int i=0; i<source.size(); i++) {
			result[i] = power(source[i], mod-2, mod);
		}
		return result;
	}
	
	int ncr(int n, int r, vector<int> &factorials, vector<int> &inverses, int mod=MOD) {
		if (r < 0 || r > n) return 0;
		int ans = (factorials[n] * inverses[r]) % mod;
		return (ans * inverses[n-r]) % mod;
	}
	
	int ways(int a, int b, vector<int> &factorials, vector<int> &inverses, int mod=MOD) {
		return ncr(a - 1 + b - 1, a - 1, factorials, inverses, mod);
	}
	
	vector<vector<int>> generate_ncr(int n, int r, int mod=MOD) {
		vector<vector<int>> result(n+1, vector<int>(r+1));
		for (int i=0; i<=n; i++) {
			result[i][0] = 1;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=r; j++) {
				result[i][j] = (result[i-1][j-1] + result[i-1][j]) % mod;
			}
		}
		return result;
	} 
	
	int sum(vector<int> input, int mod=TOO_LARGE) {
		int result = 0;
		for (auto x: input) {
			result = (result + x) % MOD;
		}
		return result;
	}
	
	int sum_unrestricted(vector<int> input) {
		int result = 0;
		for (auto x: input) {
			result += x;
		}
		return result;
	}
	
	int product(vector<int> input, int mod=FIT_INT) {
		int result = 1;
		for (auto x: input) {
			result = (result * x) % MOD;
		}
		return result;
	}
	
	int product_unrestricted(vector<int> input) {
		int result = 1;
		for (auto x: input) {
			result *= x;
		}
		return result;
	}
	
	int choose_2(int n) {
		return n * (n - 1) / 2;
	}
	
	int divup(int a, int b) {
		return (a + b - 1) / b;
	}
	
	int ceildiv(int a, int b) {
		return divup(a, b);
	}
	
	int divceil(int a, int b) {
		return divup(a, b);
	}
	
	double distance(pair<double, double> a, pair<double, double> b) {
		return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	}
	
	int square(int x) {
		return x * x;
	}
	
	double calculate_ratio(int a, int b) {
		return ((double) a) / ((double) b);
	}
	
}

namespace socho_utils {
	
	template<typename T>
	int count(vector<T> items, T item) {
		int a = 0;
		for (auto x: items) {
			if (x == item) a++;
		}
		return a;
	}
	
	int count(vector<int> items, signed item) {
		int a = 0;
		for (auto x: items) {
			if (x == item) a++;
		}
		return a;
	}
	
	int max(int a, signed b) {
		if (a > b) return a;
		return b;
	}
	
	int max(signed a, int b) {
		if (a > b) return a;
		return b;
	}
	
	template<typename T>
	T max(T a, T b, T c) {
		if (a > b && a > c) return a;
		if (b > c) return b;
		return c;
	}
	
	int min(int a, signed b) {
		if (a < b) return a;
		return b;
	}
	
	int min(signed a, int b) {
		if (a < b) return a;
		return b;
	}
	
	template<typename T>
	T min(T a, T b, T c) {
		if (a < b && a < c) return a;
		if (b < c) return b;
		return c;
	}
	
	template<typename T>
	int count_distinct(vector<T> s) {
		set<T> e;
		for (auto x: s) e.insert(x);
		return e.size();
	}
	
	int count_distinct(string s) {
		set<char> e;
		for (auto x: s) e.insert(x);
		return e.size();
	}
	
	void printif(bool e, string yes="Yes", string no="No") {
		if (e) cout << yes << endl;
		else cout << no << endl;
	}
	
	vector<int> digits(int x) {
		assert(x >= 0);
		vector<int> result;
		while (x > 0) {
			result.push_back(x % 10);
			x /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
	
	int in_range(int a, int b) {
		if (a > b) return 0;
		return b - a + 1;
	}
	
	bool endswith(string a, string b) {
		if (a.size() < b.size()) return false;
		int x = b.size();
		for (int i=0; i<b.size(); i++) {
			if (a[a.size()-x] != b[i]) return false;
			x--;
		}
		return true;
	}
	
	void doubleprint(int precision=10) {
		cout << fixed << setprecision(precision);
	}
	
	string pad_left(string x, int len, char c='0') {
		string s = x;
		reverse(s.begin(), s.end());
		while (s.length() < len) s += c;
		reverse(s.begin(), s.end());
		return s;
	}
	
	
	
	
	template<typename T>
	vector<T> vector_input(int n, T x) {
		vector<T> t;
		for (int i=0; i<n; i++) {
			T x;
			cin >> x;
			t.push_back(x);
		}
		return t;
	}
	
	vector<int> vector_input(int n) {
		vector<int> t;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			t.push_back(x);
		}
		return t;
	}
	
	bool is_uppercase(char x) {
		return 'A' <= x && x <= 'Z';
	}
	
	bool is_lowercase(char x) {
		return 'a' <= x && x <= 'z';
	}
	
	template<typename T>
	map<T, int> frequency(vector<T> x) {
		map<T, int> s;
		for (auto a: x) {
			s[a]++;
		}
		return s;
	}
	
	template<typename T>
	map<T, int> inverse(vector<T> x, int indexing=0, bool first=false) {
		map<T, int> s;
		int j = indexing;
		for (auto a: x) {
			if (first) {
				if (s.find(a) != s.end()) {}
				else s[a] = j;
			}
			else {
				s[a] = j;
			}
			j++;
		}
		return s;
	}
	
	template<typename T>
	map<T, vector<int>> inverses(vector<T> x, int indexing=0) {
		map<T, vector<int>> s;
		int j = indexing;
		for (auto a: x) {
			s[a].push_back(j);
			j++;
		}
		return s;
	}
	
	template<typename T>
	vector<T> in_any(vector<T> a, vector<T> b) {
		for (auto x: b) a.push_back(x);
		auto r = frequency(a);
		vector<T> res;
		for (auto x: r) {
			res.push_back(x.first);
		}
		return res;
	}
	
	template<typename T>
	vector<T> in_both(vector<T> a, vector<T> b) {
		auto r = frequency(a);
		vector<T> j;
		for (auto x: b) {
			if (r[x]) j.push_back(x);
		}
		return j;
	}
	
	int xor_all(vector<int> e) {
		int a = 0;
		for (auto x: e) a ^= x;
		return a;
	}
	
	string copies(string x, int copy) {
		string r = "";
		for (int i=0; i<copy; i++) r += x;
		return r;
	}
	
	bool substring(string x, string y) {
		for (int i=0; i<x.size(); i++) {
			bool ok = true;
			for (int j=0; j<y.size(); j++) {
				if (i + j >= x.size()) ok = false;
				else if (x[i + j] != y[j]) ok = false;
			}
			if (ok) return true;
		}
		return false;
	}
	
	template<typename T>
	T min(vector<T> a) {
		if (a.empty()) return T();
		T x = a[0];
		for (auto y: a) {
			if (y < x) x = y;
		}
		return x;
	}
	
	template<typename T>
	T max(vector<T> a) {
		if (a.empty()) return T();
		T x = a[0];
		for (auto y: a) {
			if (y > x) x = y;
		}
		return x;
	}
	
	template<typename T>
	T max_key(map<T, int> a) {
		T Tx;
		int e = LLONG_MIN;
		for (auto x: a) {
			if (x.second > e) {
				Tx = x.first;
				e = x.second;
			}
		}
		return Tx;
	}
	
	vector<int> frequency_alphabet(string s) {
		vector<int> result(26, 0);
		for (auto x: s) {
			if (x >= 'a' && x <= 'z') result[x - 'a']++;
			else if (x >= 'A' && x <= 'Z') result[x - 'A']++;
		}
		return result;
	}
	
	map<char, int> frequency(string s) {
		map<char, int> r;
		for (auto x: s) r[x]++;
		return r;
	}
	
	int mex(vector<int> items, int from=0) {
		auto r = frequency(items);
		while (true) {
			if (r[from] == 0) {
				return from;
			}
			from++;
		}
	}
	
	bool is_superset(vector<int> a, vector<int> b) {
		auto r = frequency(a), s = frequency(b);
		for (auto x: s) {
			if (r[x.first] < x.second) return false;
		}
		return true;
	}
	
	bool is_subset(vector<int> a, vector<int> b) {
		return is_superset(b, a);
	}
	
	void sort(string &s) {
		sort(s.begin(), s.end());
	}
	
	template<typename T>
	void sort(vector<T> &s) {
		sort(s.begin(), s.end());
	}
	
	vector<pair<int, int>> interval_union(vector<pair<int, int>> intervals) {
		int op = 0, c = 0;
		vector<pair<int, int>> eve, res;
		for (auto x: intervals) {
			eve.push_back({x.first, -1});
			eve.push_back({x.second, 1});
		}
		sort(eve);
		for (auto x: eve) {
			x.second *= -1;
			if (c > 0 && c + x.second == 0) {
				res.push_back({op, x.first});
			}
			else if (c == 0 && c + x.second == 1) {
				op = x.first;
			}
			c += x.second;
		}
		return res;
	}
	
	char to_upper(char a) {
		if (a >= 'a' && a <= 'z') a += 'A' - 'a';
		return a;
	}
	
	string to_upper(string a) {
		string x = "";
		for (auto b: a) x += to_upper(b);
		return x;
	}
	
	char to_lower(char a) {
		if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
		return a;
	}
	
	string to_lower(string a) {
		string x = "";
		for (auto b: a) x += to_lower(b);
		return x;
	}
	
}

using namespace socho_math;
using namespace socho_utils;
// END TEMPLATE


signed main() {
 
	ran(); fast(); doubleprint();
	
	
	
}
