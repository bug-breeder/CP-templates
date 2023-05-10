inline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
  assert(/* 0 <= x and */ x < (uint_fast64_t)MOD);
  uint_fast64_t y = 1;
  for (; k; k >>= 1) {
    if (k & 1)
      (y *= x) %= MOD;
    (x *= x) %= MOD;
  }
  assert(/* 0 <= y and */ y < (uint_fast64_t)MOD);
  return y;
}

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
  assert(0 <= value and value < MOD);
  if (value == 0)
    return -1;
  int64_t a = value, b = MOD;
  int64_t x = 0, y = 1;
  for (int64_t u = 1, v = 0; a;) {
    int64_t q = b / a;
    x -= q * u;
    std::swap(x, u);
    y -= q * v;
    std::swap(y, v);
    b -= q * a;
    std::swap(b, a);
  }
  if (not(value * x + MOD * y == b and b == 1))
    return -1;
  if (x < 0)
    x += MOD;
  assert(0 <= x and x < MOD);
  return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
  int32_t y = modinv_nocheck(x, MOD);
  assert(y != -1);
  return y;
}

template <int32_t MOD = MOD> struct mint {
  int32_t value;
  mint() : value() {}
  mint(int64_t value_)
      : value(value_ < 0      ? value_ % MOD + MOD
              : value_ >= MOD ? value_ % MOD
                              : value_) {}
  mint(int32_t value_, std::nullptr_t) : value(value_) {}
  explicit operator bool() const { return value; }
  inline mint<MOD> operator+(mint<MOD> other) const {
    return mint<MOD>(*this) += other;
  }
  inline mint<MOD> operator-(mint<MOD> other) const {
    return mint<MOD>(*this) -= other;
  }
  inline mint<MOD> operator*(mint<MOD> other) const {
    return mint<MOD>(*this) *= other;
  }
  inline mint<MOD> &operator+=(mint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD)
      this->value -= MOD;
    return *this;
  }
  inline mint<MOD> &operator-=(mint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  inline mint<MOD> &operator*=(mint<MOD> other) {
    this->value = (uint_fast64_t)this->value * other.value % MOD;
    return *this;
  }
  inline mint<MOD> operator-() const {
    return mint<MOD>(this->value ? MOD - this->value : 0, nullptr);
  }
  inline bool operator==(mint<MOD> other) const { return value == other.value; }
  inline bool operator!=(mint<MOD> other) const { return value != other.value; }
  inline mint<MOD> pow(uint64_t k) const {
    return mint<MOD>(modpow(value, k, MOD), nullptr);
  }
  inline mint<MOD> inv() const {
    return mint<MOD>(modinv(value, MOD), nullptr);
  }
  inline mint<MOD> operator/(mint<MOD> other) const {
    return *this * other.inv();
  }
  inline mint<MOD> &operator/=(mint<MOD> other) { return *this *= other.inv(); }
};
template <int32_t MOD> mint<MOD> operator+(int64_t value, mint<MOD> n) {
  return mint<MOD>(value) + n;
}
template <int32_t MOD> mint<MOD> operator-(int64_t value, mint<MOD> n) {
  return mint<MOD>(value) - n;
}
template <int32_t MOD> mint<MOD> operator*(int64_t value, mint<MOD> n) {
  return mint<MOD>(value) * n;
}
template <int32_t MOD> mint<MOD> operator/(int64_t value, mint<MOD> n) {
  return mint<MOD>(value) / n;
}
template <int32_t MOD>
std::istream &operator>>(std::istream &in, mint<MOD> &n) {
  int64_t value;
  in >> value;
  n = value;
  return in;
}
template <int32_t MOD>
std::ostream &operator<<(std::ostream &out, mint<MOD> n) {
  return out << n.value;
}
