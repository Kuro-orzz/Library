# Basic knowledge

## 1. [Thuật toán Euclid](https://wiki.vnoi.info/vi/algo/algebra/euclid)

Thuật toán Euclid:
- **Định lý Lamé**: Thuật toán Euclid cần thực hiện ít hơn $5\log_{10}(\min(a, b))$ lần chia lấy dư.
- Thuật toán chạy chậm nhất khi $a = F_n$, $b = F_{n - 1}$, với $F_i$ là số Fibonacci thứ $i$. Khi đó thuật toán cần thực hiện $n - 2$ lần đệ quy.

Binary GCD (Stein's algorithm):
- https://en.wikipedia.org/wiki/Binary_GCD_algorithm
- Thuật toán cải tiến trên sẽ thực hiện $\log(a) + \log(b)$ lần trong trường hợp tệ nhất. Do vậy, độ phức tạp của thuật toán là $\mathcal{O}(\log \max(a, b))$.

Lưu ý:
- `__gcd()`:
    + Nằm trong `<algorithm> (bits/stl_algo.h)`, không phải hàm chuẩn của C++ mà là hàm nội bộ của libstdc++, thư viện chuẩn đi kèm GCC
    + Tên bắt đầu bằng `__` là tên dành riêng cho bộ thư viện dùng nội bộ, nó chỉ tình cờ gọi được từ bên ngoài, nên dân CP dùng nhiều
    + Implement bằng Euclid thuần
- `std::gcd()`:
    + Nằm trong `<numeric>`, là hàm chuẩn từ C++17
    + Implement bằng Binary GCD

Thuật toán Euclid mở rộng:
- **Bổ đề Bézout**: Với hai số nguyên $a$, $b$ có ƯCLN là $d$, tồn tại hai số nguyên $x$ và $y$ thoả mãn $ax + by = d$. Hơn nữa, tất cả các số nguyên $D$ có dạng $D = aX + bY$ đều là bội của $d$.
- Dùng để giải phương trình Diophantine

Nghịch đảo modulo:
- Số tự nhiên $\gamma$ được gọi là **nghịch đảo modulo** theo modulo $M$ của một số tự nhiên $a$ nếu $a\gamma \equiv 1 \pmod{M}$. Ký hiệu là $a^{-1} \pmod{M}$.
- Tồn tại khi và chỉ khi $\gcd(a, M) = 1$.


## 2. [Sieve of Eratosthenes](https://wiki.vnoi.info/vi/algo/algebra/prime_sieve)

### Sieve of Eratosthenes
Độ phức tạp thời gian là $\mathcal{O}\left( n \times \left(\frac{1}{2} + \frac{1}{3} +\ldots+\frac{1}{p} \right) \right)$ với $p$ là số nguyên tố $\le  n$.
Từ đó, ta có thể sử dụng định lý Merten 2 để rút gọn độ phức tạp:
$$
\mathcal{O}\left( n \times \left(\frac{1}{2} + \frac{1}{3} +\ldots+\frac{1}{p} \right) \right) = \mathcal{O}( n \log (\log n))
$$
- **Độ phức tạp thời gian: $\boldsymbol{\mathcal{O}(n \log \log n)}$**
- **Độ phức tạp không gian: $\boldsymbol{\mathcal{O}(n)}$**

### Sàng nguyên tố trong đoạn [L, R]:
- **Độ phức tạp thời gian: $\boldsymbol{\mathcal{O} \left( N \log \log (R) + \sqrt R \log \log \sqrt R \right)}$**
- **Độ phức tạp không gian: $\boldsymbol{\mathcal{O} \left( N + \sqrt R \right)}$**

### So sánh mảng bool và vector<bool>
- Một biến `bool` chỉ có hai giá trị `true/false` nên về mặt lý thuyết chỉ cần 1 bit để lưu trữ nó. Nhưng bình thường, các máy tính hiện nay khi lưu trữ biến `bool` sẽ sử dụng $1$ byte (tương đương với $8$ bits) để truy cập nhanh chóng. Vì thế một mảng `bool a[n]` sẽ cần đến $n$ bytes.
- `vector<bool>` được tối ưu để lưu trữ $1$ biến `bool` trong $1$ bit thay vì $1$ byte, ngoài ra còn có $40$ bytes sử dụng cho khởi tạo `vector<bool>` ban đầu. Tuy nhiên, việc tối ưu về bộ nhớ khiến ta phải truy cập bit một các gián tiếp: mỗi lần truy cập, đọc, ghi bit ta cần tách nhỏ từng bit của byte đó. Trong trường hợp bộ dữ liệu nhỏ (khoảng $10^{6}$), truy cập như vậy sẽ chậm hơn so với việc truy cập trực tiếp.
- Tóm lại, ta có bảng dưới đây

|                        | bool a[n] |                   vector<bool>                   |
| ---------------------- |:---------:|:------------------------------------------------:|
| Không gian lưu trữ     | $n$ bytes | $40 + \left\lceil\frac{n}{8}\right\rceil$ bytes  |
| Truy cập, đọc, ghi bit | Trực tiếp |                   Gián tiếp                      |


### Phi hàm Euler

$$
\varphi(n) = p_1^{\alpha_1 - 1} \times p_2^{\alpha_2 - 1} \ldots p_k^{\alpha_k - 1} \times (p_1-1)(p_2 - 1) \ldots (p_k - 1)
= n \frac{p_1-1}{p_1} \frac{p_2-1}{p_2} \ldots \frac{p_k-1}{p_k}
$$

### Bánh xe phân tích - Wheel Factorization

- **Độ phức tạp thời gian: $\boldsymbol{\mathcal{O}\left(\frac{4}{15} n \log \log n \right)}$**
- **Độ phức tạp không gian: $\boldsymbol{\mathcal{O}\left(\frac{4}{15} n \right)}$**