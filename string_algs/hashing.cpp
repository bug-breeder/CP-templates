class HashedString {
	private:
		// change M and P if you want
		static const long long M = 1e9 + 7;
		static const long long P = 9973;

		// pow[i] contains P^i % M
		static vector<long long> pow;

		// p_hash[i] is the hash of the first i characters of the given string
		vector<long long> p_hash;
	public:
		HashedString(const string& s) : p_hash(s.size() + 1) {
			while (pow.size() < s.size()) {
				pow.push_back((pow.back() * P) % M);
			}

			p_hash[0] = 0;
			for (int i = 0; i < s.size(); i++) {
				p_hash[i + 1] = ((p_hash[i] * P) % M + s[i]) % M;
			}
		}

		long long getHash(int start, int end) {
			long long raw_val = (
				p_hash[end + 1] - (p_hash[start] * pow[end - start + 1])
			);
			return (raw_val % M + M) % M;
		}
};
vector<long long> HashedString::pow = {1};
