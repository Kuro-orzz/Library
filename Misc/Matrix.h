#include "../template.h"

// AC: https://cses.fi/problemset/task/1722/

template<typename T>
struct Matrix {
    vector<vector<T>> matrix;

    Matrix() = default;

    Matrix(int32_t _row, int32_t _col): matrix(_row, vector<T>(_col)) {}

    Matrix(const vector<vector<T>> &_matrix): matrix(_matrix) {}

    Matrix &operator = (const Matrix &b) {
        matrix = b.matrix;
        return *this;
    }

    Matrix &operator = (const vector<vector<T>> &mat) { 
        matrix = mat;
        return *this;
    }

    Matrix &operator += (const Matrix &b) {
        assert(row() == b.row() && col() == b.col());
        for (size_t i = 0; i < row(); i++) {
            for (size_t j = 0; j < col(); j++) {
                matrix[i][j] += b[i][j];
            }
        }
        return *this;
    }

    Matrix &operator -= (const Matrix &b) {
        *this += (-b);
        return *this;
    }

    Matrix &operator *= (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (size_t i = 0; i < a.row(); i++) {
            for (size_t j = 0; j < b.col(); j++) {
                for (size_t k = 0; k < a.col(); k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return *this = c;
    }

    Matrix &operator *= (const T &x) {
        for (size_t i = 0; i < row(); i++) {
            for (size_t j = 0; j < col(); j++) {
                (*this)[i][j] *= x;
            }
        }
        return *this;
    }

    Matrix &operator %= (const T &mod) {
        for (size_t i = 0; i < row(); i++) {
            for (size_t j = 0; j < col(); j++) {
                (*this)[i][j] %= mod;
            }
        }
        return *this;
    }

    // ------------------------ Operator ------------------------
    Matrix operator - () const {
        Matrix res = *this;
        for (size_t i = 0; i < row(); i++) {
            for (size_t j = 0; j < col(); j++) {
                res[i][j] *= -1;
            }
        }
        return res;
    } // -a

    // Matrix = Matrix + Matrix
    Matrix operator + (const Matrix &b) const { return Matrix(*this) += b; }
    Matrix operator - (const Matrix &b) const { return Matrix(*this) -= b; }
    Matrix operator * (const Matrix &b) const { return Matrix(*this) *= b; }

    // Matrix = Matrix * Int
    Matrix operator * (const T &t) const { return Matrix(*this) *= t; }
    Matrix operator % (const T &t) const { return Matrix(*this) %= t; }

    // Matrix = Int * Matrix
    friend Matrix operator * (const T &t, const Matrix &b) { return Matrix(b) *= t; }

    const vector<T> &operator [] (size_t i) const { assert(i < row()); return matrix[i]; }
    vector<T> &operator [] (size_t i) { assert(i < row()); return matrix[i]; }

    // ------------------------- Comparison ---------------------
    bool operator == (const Matrix &b) const {
        for (size_t i = 0; i < row(); i++) {
            for (size_t j = 0; j < col(); j++) {
                if ((*this)[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    // ------------------------- Misc ---------------------------
    size_t row() const { return matrix.size(); }

    size_t col() const { return isEmpty() ? 0 : matrix[0].size(); }

    bool isEmpty() const { return matrix.empty(); }

    static Matrix identity(size_t n) {
        Matrix res(n, n);
        for (size_t i = 0; i < n; i++) {
            res[i][i] = T(1);
        }
        return res;
    }

    Matrix pow(int64_t k) const {
        assert(row() == col());
        Matrix base = *this, res = identity(row());
        while (k) {
            if (k & 1) res *= base;
            k >>= 1;
            base *= base;
        }
        return res;
    }

    T sum_all() const { return submatrix_sum(0, 0, row(), col()); }
    
    // sum of [r1, r2) x [c1, c2)
    T submatrix_sum(size_t r1, size_t c1, size_t r2, size_t c2) const {
        T res{0};
        for (size_t i = r1; i < r2; i++) {
            for (size_t j = c1; j < c2; j++) {
                res += matrix[i][j];
            }
        }
        return res;
    }

    // fibonanci <= 1e18 with mod
    static int32_t fibonanci(int64_t n, int32_t mod) {
        if (!n) return 0;
        vector<vector<ll>> init = { {1, 1},
                                    {1, 0} };
        Matrix<ll> ans = identity(2), f(init);
        ll e = n - 1;
        while (e) {
            if (e & 1) ans = (ans * f) % mod;
            f = f * f % mod;
            e /= 2;
        }
        return ans[0][0];
    }

    // ---------------------- Input Output ---------------------
    friend ostream &operator << (ostream &out, const Matrix &a) {
        for (auto &mat : a.matrix) {
            for (auto &x : mat) {
                out << x << " ";
            }
            out << '\n';
        }
        return out;
    }
};

// void reverse_shape(vector<vector<int>> &v){
//     int n = v.size();
//     int m = v[0].size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m / 2; ++j) {
//             swap(v[i][j], v[i][m - 1 - j]);
//         }
//     }
// }

// void transpose(vector<vector<int>> &v){
//     int n = v.size();
//     int m = v[0].size();
//     vector<vector<int>> res(m, vector<int>(n));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             res[j][i] = v[i][j];
//         }
//     }
//     res.swap(v);
// }

// void rotate(vector<vector<int>>& matrix) {
//     transpose(matrix);
//     reverse_shape(matrix);
// }