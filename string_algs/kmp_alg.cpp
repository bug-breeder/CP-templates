vector<int> prefix_function(string s) {
// lps[i] = the longest proper prefix of s[0..i] which is also a suffix of s[0..i].
// Start at index 0
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
