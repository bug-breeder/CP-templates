vector<vector<long long>> mul(vector<vector<long long>> &a,
                              vector<vector<long long>> &b) {
  vector<vector<ll>> res(a.size(), vector<long long>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      res[i][j] = 0;
      for (int k = 0; k < b.size(); k++) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= MOD;
      }
    }
  }
  return res;
}

vector<vector<long long>> pow(vector<vector<long long>> mat, long long k) {
  if (k == 1)
    return mat;
  vector<vector<long long>> res = pow(mat, k / 2);
  res = mul(res, res);
  if (k & 1)
    res = mul(res, mat);
  return res;
}
