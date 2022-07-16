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
	
	vector<int> calculate_factorials(int n, int mod=MOD) {
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
	
	vector<int> calculate_inverses(vector<int> source, int mod=MOD) {
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
	
}
namespace socho_graph {
	
	const int INFDIST = 1000000000ll * 1000000000ll;
	const int MXK = 20;
	
	struct graph {
		
		bool dir;
		int index;
		int n, m;
		bool wgt;
		vector<vector<pair<int, pair<int, int>>>> adj; // other, distance, index
		vector<pair<pair<int, int>, pair<int, int>>> edges; // distance, index, a, b
		
		void read_n() {
			cin >> n;
			adj.resize(n + index);
		}
		
		void set_index(int i) {
			index = i;
			adj.resize(n + index);
		}
		
		void set_weighted(bool x) {
			wgt = x;
		}
		
		void read_m() {
			cin >> m;
		}
		
		void read_edge() {
			int i = edges.size();
			int a, b, w=1;
			if (wgt) cin >> a >> b >> w;
			else cin >> a >> b;
			edges.push_back({{w, i}, {a, b}});
			adj[a].push_back({b, {w, i}});
			if (!dir) adj[b].push_back({a, {w, i}});
		}
		
		void read_edges() {
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		graph() {
			// blank graph with nothing.
			dir = index = n = m = 0;
		}
		
		graph(int indexing, bool weighted=false, bool directed=false) {
			// graph from indexing based input
			read_n();
			read_m();
			index = indexing;
			dir = directed;
			wgt = weighted;
			adj.resize(n + indexing);
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		graph(graph &copyfrom) {
			dir = copyfrom.dir;
			index = copyfrom.index;
			n = copyfrom.n;
			m = copyfrom.m;
			adj = copyfrom.adj;
			edges = copyfrom.edges;
		}
		
		graph inverse() {
			assert(dir == true); // graph must be directed! make a copy from the constructor otherwise
			graph other;
			other.dir = dir;
			other.index = index;
			other.n = n;
			other.m = m;
			other.adj.resize(n + index);
			for (int i=index; i<index+n; i++) {
				for (auto x: adj[i]) {
					int ot = x.first;
					int ow = x.second.first;
					int oi = x.second.second;
					other.adj[ot].push_back({i, {ow, oi}});
					other.edges.push_back({{ow, oi}, {ot, i}});
				}
			}
			return other;
		}
		
		void set_n(int ne, int indexing=0) {
			index = indexing;
			n = ne;
			adj.resize(n + index);
		}
		
		void add_edge(int a, int b, int w=1) {
			int e = edges.size();
			edges.push_back({{w, e}, {a, b}});
			m++;
			adj[a].push_back({b, {w, e}});
			if (!dir) {
				adj[b].push_back({a, {w, e}});
			}
		}
		
		vector<int> distances(int from) {
			vector<int> dist(n+index, INFDIST);
			min_pq<pair<int, int>> proc;
			proc.push({0, from});
			while (!proc.empty()) {
				auto x = proc.top(); proc.pop();
				int di = x.first, no = x.second;
				if (dist[no] < di) continue;
				dist[no] = di;
				for (auto x: adj[no]) {
					int ot = x.first;
					int od = x.second.first + di;
					if (dist[ot] > od) {
						dist[ot] = od;
						proc.push({od, ot});
					}
				}
			}
			return dist;
		}
		
		int distance(int x, int y) {
			return distances(x)[y];
		}
		
		vector<vector<int>> distances_all() {
			vector<vector<int>> dist(n+index);
			for (int k=index; k<index+n; k++) {
				dist[k] = distances(k);
			}
			return dist;
		}
		
	};
	
	struct tree: graph {
		
		int tree_root;
		
		tree() {
			// blank graph with nothing.
			dir = index = n = m = tree_root = 0;
		}
		
		void read_n() {
			cin >> n;
			m = n - 1;
		}
		
		void set_index(int i) {
			index = i;
			tree_root = index;
			adj.resize(n + index);
		}
		
		tree(int indexing, bool weighted=false, bool directed=false) {
			// tree from indexing based input
			index = indexing;
			read_n();
			m = n-1;
			dir = directed;
			tree_root = indexing;
			adj.resize(n + indexing);
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		void set_root(int newroot) {
			tree_root = newroot;
		}
		
		vector<int> parents;
		vector<vector<int>> distance_util;
		vector<int> depths;
		
		void dfs_distance_setup(int node, int par, int depth) {
			depths[node] = depth;
			distance_util[node][0] = par;
			for (int i=1; i<MXK; i++) {
				distance_util[node][i] = distance_util[distance_util[node][i-1]][i-1];
			}
			for (auto x: adj[node]) {
				if (x.first == par) continue;
				dfs_distance_setup(x.first, node, depth+x.second.first);
			}
		}
		
		void setup_distances(int root) {
			tree_root = root;
			distance_util.resize(n+index, vector<int>(MXK, root));
			parents.resize(n+index, index);
			depths.resize(n+index, 0);
			dfs_distance_setup(root, root, 0);
		}
		
		int kth(int n, int k) {
			if (distance_util.empty()) setup_distances(tree_root);
			for (int i=0; i<MXK; i++) {
				if (k & (1 << i)) {
					n = distance_util[n][i];
				}
			}
			return n;
		}
		
		int lca(int a, int b) {
			if (distance_util.empty()) setup_distances(tree_root);
			if (depths[a] > depths[b]) swap(a, b);
			b = kth(b, depths[b] - depths[a]);
			for (int i=MXK-1; i>=0; i--) {
				if (distance_util[a][i] != distance_util[b][i]) {
					a = distance_util[a][i];
					b = distance_util[b][i];
				}
			}
			return distance_util[a][0];
		}
		
		int dist(int a, int b) {
			if (distance_util.empty()) setup_distances(tree_root);
			int l = lca(a, b);
			int m = 0;
			if (l != tree_root) m = depths[parents[l]];
			return depths[a] + depths[b] - depths[l] - m;
		}
		
		pair<int, pair<int, int>> find_diameter() {
			vector<int> dists = distances(tree_root);
			int far = tree_root;
			for (int i=index; i<index+n; i++) {
				if (dists[i] > dists[far]) {
					far = i;
				}
			}
			dists = distances(far);
			int sec = far;
			for (int i=index; i<index+n; i++) {
				if (dists[i] > dists[sec]) {
					sec = i;
				}
			}
			return {dists[sec], {far, sec}};
		}
		
		int diameter() {
			return find_diameter().first;
		}
		
	};
	
	struct ufds {
		
		int n, index;
		int components;
		vector<int> parents;
		
		ufds() {
			n = 0;
			components = 0;
		}
		
		ufds(graph a) {
			set_n(a.n);
			for (auto edge: a.edges) {
				int a = edge.second.first;
				int b = edge.second.second;
				connect(a, b);
			}
		}
		
		void set_n(int newn) {
			n = newn;
			parents.resize(n+index);
			for (int i=0; i<n+index; i++) parents[i] = i;
		}
		
		int parent(int n) {
			if (parents[n] == n) return n;
			return parents[n] = parent(parents[n]);
		}
		
		void connect(int a, int b) {
			a = parent(a);
			b = parent(b);
			if (a == b) return;
			parents[a] = b;
		}
		
		bool are_connected(int a, int b) {
			return parent(a) == parent(b);
		}
		
		vector<vector<int>> get_components() {
			vector<vector<int>> v(n+index);
			vector<vector<int>> results;
			for (int i=index; i<n+index; i++) {
				v[parent(i)].push_back(i);
			}
			for (auto x: v) {
				if (!x.empty()) results.push_back(x);
			}
			return results;
		}
		
	};
	
}


using namespace socho_math;
using namespace socho_graph;


// END TEMPLATE



signed main() {

	ran(); fast();
	
	
	
}
