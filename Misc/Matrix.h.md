---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1722/
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Misc/Matrix.h\"\n\n// AC: https://cses.fi/problemset/task/1722/\n\
    \ntemplate<typename T>\nstruct Matrix {\n    vector<vector<T>> matrix;\n\n   \
    \ Matrix() = default;\n\n    Matrix(int32_t _row, int32_t _col): matrix(_row,\
    \ vector<T>(_col)) {}\n\n    Matrix(const vector<vector<T>> &_matrix): matrix(_matrix)\
    \ {}\n\n    Matrix &operator = (const Matrix &b) {\n        matrix = b.matrix;\n\
    \        return *this;\n    }\n\n    Matrix &operator = (const vector<vector<T>>\
    \ &mat) { \n        matrix = mat;\n        return *this;\n    }\n\n    Matrix\
    \ &operator += (const Matrix &b) {\n        assert(row() == b.row() && col() ==\
    \ b.col());\n        for (size_t i = 0; i < row(); i++) {\n            for (size_t\
    \ j = 0; j < col(); j++) {\n                matrix[i][j] += b[i][j];\n       \
    \     }\n        }\n        return *this;\n    }\n\n    Matrix &operator -= (const\
    \ Matrix &b) {\n        *this += (-b);\n        return *this;\n    }\n\n    Matrix\
    \ &operator *= (const Matrix &b) {\n        Matrix a = *this;\n        assert(a.col()\
    \ == b.row());\n        Matrix c(a.row(), b.col());\n        for (size_t i = 0;\
    \ i < a.row(); i++) {\n            for (size_t j = 0; j < b.col(); j++) {\n  \
    \              for (size_t k = 0; k < a.col(); k++) {\n                    c[i][j]\
    \ += a[i][k] * b[k][j];\n                }\n            }\n        }\n       \
    \ return *this = c;\n    }\n\n    Matrix &operator *= (const T &x) {\n       \
    \ for (size_t i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col();\
    \ j++) {\n                (*this)[i][j] *= x;\n            }\n        }\n    \
    \    return *this;\n    }\n\n    Matrix &operator %= (const T &mod) {\n      \
    \  for (size_t i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col();\
    \ j++) {\n                (*this)[i][j] %= mod;\n            }\n        }\n  \
    \      return *this;\n    }\n\n    // ------------------------ Operator ------------------------\n\
    \    Matrix operator - () const {\n        Matrix res = *this;\n        for (size_t\
    \ i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col(); j++) {\n\
    \                res[i][j] *= -1;\n            }\n        }\n        return res;\n\
    \    } // -a\n\n    // Matrix = Matrix + Matrix\n    Matrix operator + (const\
    \ Matrix &b) const { return Matrix(*this) += b; }\n    Matrix operator - (const\
    \ Matrix &b) const { return Matrix(*this) -= b; }\n    Matrix operator * (const\
    \ Matrix &b) const { return Matrix(*this) *= b; }\n\n    // Matrix = Matrix *\
    \ Int\n    Matrix operator * (const T &t) const { return Matrix(*this) *= t; }\n\
    \    Matrix operator % (const T &t) const { return Matrix(*this) %= t; }\n\n \
    \   // Matrix = Int * Matrix\n    friend Matrix operator * (const T &t, const\
    \ Matrix &b) { return Matrix(b) *= t; }\n\n    const vector<T> &operator [] (size_t\
    \ i) const { assert(i < row()); return matrix[i]; }\n    vector<T> &operator []\
    \ (size_t i) { assert(i < row()); return matrix[i]; }\n\n    // -------------------------\
    \ Comparison ---------------------\n    bool operator == (const Matrix &b) const\
    \ {\n        for (size_t i = 0; i < row(); i++) {\n            for (size_t j =\
    \ 0; j < col(); j++) {\n                if ((*this)[i][j] != b[i][j]) return false;\n\
    \            }\n        }\n        return true;\n    }\n\n    // -------------------------\
    \ Misc ---------------------------\n    size_t row() const { return matrix.size();\
    \ }\n\n    size_t col() const { return isEmpty() ? 0 : matrix[0].size(); }\n\n\
    \    bool isEmpty() const { return matrix.empty(); }\n\n    static Matrix identity(size_t\
    \ n) {\n        Matrix res(n, n);\n        for (size_t i = 0; i < n; i++) {\n\
    \            res[i][i] = T(1);\n        }\n        return res;\n    }\n\n    Matrix\
    \ pow(int64_t k) const {\n        assert(row() == col());\n        Matrix base\
    \ = *this, res = identity(row());\n        while (k) {\n            if (k & 1)\
    \ res *= base;\n            k >>= 1;\n            base *= base;\n        }\n \
    \       return res;\n    }\n\n    T sum_all() const { return submatrix_sum(0,\
    \ 0, row(), col()); }\n    \n    // sum of [r1, r2) x [c1, c2)\n    T submatrix_sum(size_t\
    \ r1, size_t c1, size_t r2, size_t c2) const {\n        T res{0};\n        for\
    \ (size_t i = r1; i < r2; i++) {\n            for (size_t j = c1; j < c2; j++)\
    \ {\n                res += matrix[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    // fibonanci <= 1e18 with mod\n    static int32_t fibonanci(int64_t\
    \ n, int32_t mod) {\n        if (!n) return 0;\n        vector<vector<ll>> init\
    \ = { {1, 1},\n                                    {1, 0} };\n        Matrix<ll>\
    \ ans = identity(2), f(init);\n        ll e = n - 1;\n        while (e) {\n  \
    \          if (e & 1) ans = (ans * f) % mod;\n            f = f * f % mod;\n \
    \           e /= 2;\n        }\n        return ans[0][0];\n    }\n\n    // ----------------------\
    \ Input Output ---------------------\n    friend ostream &operator << (ostream\
    \ &out, const Matrix &a) {\n        for (auto &mat : a.matrix) {\n           \
    \ for (auto &x : mat) {\n                out << x << \" \";\n            }\n \
    \           out << '\\n';\n        }\n        return out;\n    }\n};\n\n// void\
    \ reverse_shape(vector<vector<int>> &v){\n//     int n = v.size();\n//     int\
    \ m = v[0].size();\n//     for (int i = 0; i < n; ++i) {\n//         for (int\
    \ j = 0; j < m / 2; ++j) {\n//             swap(v[i][j], v[i][m - 1 - j]);\n//\
    \         }\n//     }\n// }\n\n// void transpose(vector<vector<int>> &v){\n//\
    \     int n = v.size();\n//     int m = v[0].size();\n//     vector<vector<int>>\
    \ res(m, vector<int>(n));\n//     for (int i = 0; i < n; ++i) {\n//         for\
    \ (int j = 0; j < m; ++j) {\n//             res[j][i] = v[i][j];\n//         }\n\
    //     }\n//     res.swap(v);\n// }\n\n// void rotate(vector<vector<int>>& matrix)\
    \ {\n//     transpose(matrix);\n//     reverse_shape(matrix);\n// }\n"
  code: "#include \"../template.h\"\n\n// AC: https://cses.fi/problemset/task/1722/\n\
    \ntemplate<typename T>\nstruct Matrix {\n    vector<vector<T>> matrix;\n\n   \
    \ Matrix() = default;\n\n    Matrix(int32_t _row, int32_t _col): matrix(_row,\
    \ vector<T>(_col)) {}\n\n    Matrix(const vector<vector<T>> &_matrix): matrix(_matrix)\
    \ {}\n\n    Matrix &operator = (const Matrix &b) {\n        matrix = b.matrix;\n\
    \        return *this;\n    }\n\n    Matrix &operator = (const vector<vector<T>>\
    \ &mat) { \n        matrix = mat;\n        return *this;\n    }\n\n    Matrix\
    \ &operator += (const Matrix &b) {\n        assert(row() == b.row() && col() ==\
    \ b.col());\n        for (size_t i = 0; i < row(); i++) {\n            for (size_t\
    \ j = 0; j < col(); j++) {\n                matrix[i][j] += b[i][j];\n       \
    \     }\n        }\n        return *this;\n    }\n\n    Matrix &operator -= (const\
    \ Matrix &b) {\n        *this += (-b);\n        return *this;\n    }\n\n    Matrix\
    \ &operator *= (const Matrix &b) {\n        Matrix a = *this;\n        assert(a.col()\
    \ == b.row());\n        Matrix c(a.row(), b.col());\n        for (size_t i = 0;\
    \ i < a.row(); i++) {\n            for (size_t j = 0; j < b.col(); j++) {\n  \
    \              for (size_t k = 0; k < a.col(); k++) {\n                    c[i][j]\
    \ += a[i][k] * b[k][j];\n                }\n            }\n        }\n       \
    \ return *this = c;\n    }\n\n    Matrix &operator *= (const T &x) {\n       \
    \ for (size_t i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col();\
    \ j++) {\n                (*this)[i][j] *= x;\n            }\n        }\n    \
    \    return *this;\n    }\n\n    Matrix &operator %= (const T &mod) {\n      \
    \  for (size_t i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col();\
    \ j++) {\n                (*this)[i][j] %= mod;\n            }\n        }\n  \
    \      return *this;\n    }\n\n    // ------------------------ Operator ------------------------\n\
    \    Matrix operator - () const {\n        Matrix res = *this;\n        for (size_t\
    \ i = 0; i < row(); i++) {\n            for (size_t j = 0; j < col(); j++) {\n\
    \                res[i][j] *= -1;\n            }\n        }\n        return res;\n\
    \    } // -a\n\n    // Matrix = Matrix + Matrix\n    Matrix operator + (const\
    \ Matrix &b) const { return Matrix(*this) += b; }\n    Matrix operator - (const\
    \ Matrix &b) const { return Matrix(*this) -= b; }\n    Matrix operator * (const\
    \ Matrix &b) const { return Matrix(*this) *= b; }\n\n    // Matrix = Matrix *\
    \ Int\n    Matrix operator * (const T &t) const { return Matrix(*this) *= t; }\n\
    \    Matrix operator % (const T &t) const { return Matrix(*this) %= t; }\n\n \
    \   // Matrix = Int * Matrix\n    friend Matrix operator * (const T &t, const\
    \ Matrix &b) { return Matrix(b) *= t; }\n\n    const vector<T> &operator [] (size_t\
    \ i) const { assert(i < row()); return matrix[i]; }\n    vector<T> &operator []\
    \ (size_t i) { assert(i < row()); return matrix[i]; }\n\n    // -------------------------\
    \ Comparison ---------------------\n    bool operator == (const Matrix &b) const\
    \ {\n        for (size_t i = 0; i < row(); i++) {\n            for (size_t j =\
    \ 0; j < col(); j++) {\n                if ((*this)[i][j] != b[i][j]) return false;\n\
    \            }\n        }\n        return true;\n    }\n\n    // -------------------------\
    \ Misc ---------------------------\n    size_t row() const { return matrix.size();\
    \ }\n\n    size_t col() const { return isEmpty() ? 0 : matrix[0].size(); }\n\n\
    \    bool isEmpty() const { return matrix.empty(); }\n\n    static Matrix identity(size_t\
    \ n) {\n        Matrix res(n, n);\n        for (size_t i = 0; i < n; i++) {\n\
    \            res[i][i] = T(1);\n        }\n        return res;\n    }\n\n    Matrix\
    \ pow(int64_t k) const {\n        assert(row() == col());\n        Matrix base\
    \ = *this, res = identity(row());\n        while (k) {\n            if (k & 1)\
    \ res *= base;\n            k >>= 1;\n            base *= base;\n        }\n \
    \       return res;\n    }\n\n    T sum_all() const { return submatrix_sum(0,\
    \ 0, row(), col()); }\n    \n    // sum of [r1, r2) x [c1, c2)\n    T submatrix_sum(size_t\
    \ r1, size_t c1, size_t r2, size_t c2) const {\n        T res{0};\n        for\
    \ (size_t i = r1; i < r2; i++) {\n            for (size_t j = c1; j < c2; j++)\
    \ {\n                res += matrix[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    // fibonanci <= 1e18 with mod\n    static int32_t fibonanci(int64_t\
    \ n, int32_t mod) {\n        if (!n) return 0;\n        vector<vector<ll>> init\
    \ = { {1, 1},\n                                    {1, 0} };\n        Matrix<ll>\
    \ ans = identity(2), f(init);\n        ll e = n - 1;\n        while (e) {\n  \
    \          if (e & 1) ans = (ans * f) % mod;\n            f = f * f % mod;\n \
    \           e /= 2;\n        }\n        return ans[0][0];\n    }\n\n    // ----------------------\
    \ Input Output ---------------------\n    friend ostream &operator << (ostream\
    \ &out, const Matrix &a) {\n        for (auto &mat : a.matrix) {\n           \
    \ for (auto &x : mat) {\n                out << x << \" \";\n            }\n \
    \           out << '\\n';\n        }\n        return out;\n    }\n};\n\n// void\
    \ reverse_shape(vector<vector<int>> &v){\n//     int n = v.size();\n//     int\
    \ m = v[0].size();\n//     for (int i = 0; i < n; ++i) {\n//         for (int\
    \ j = 0; j < m / 2; ++j) {\n//             swap(v[i][j], v[i][m - 1 - j]);\n//\
    \         }\n//     }\n// }\n\n// void transpose(vector<vector<int>> &v){\n//\
    \     int n = v.size();\n//     int m = v[0].size();\n//     vector<vector<int>>\
    \ res(m, vector<int>(n));\n//     for (int i = 0; i < n; ++i) {\n//         for\
    \ (int j = 0; j < m; ++j) {\n//             res[j][i] = v[i][j];\n//         }\n\
    //     }\n//     res.swap(v);\n// }\n\n// void rotate(vector<vector<int>>& matrix)\
    \ {\n//     transpose(matrix);\n//     reverse_shape(matrix);\n// }"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Matrix.h
  requiredBy: []
  timestamp: '2025-10-21 17:34:50+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Matrix.h
layout: document
redirect_from:
- /library/Misc/Matrix.h
- /library/Misc/Matrix.h.html
title: Misc/Matrix.h
---
