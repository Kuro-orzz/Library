# Trick

1. Pragma

- Sometimes it will help you run code faster, but sometimes does not
- Need to understand before adding to your code
```cpp
pragma GCC optimize("O3, unroll-loops")
pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();
```

2. Policy based data structures (PBDS)

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
// insert(), order_of_key(), find_by_order()

// Custom ver
template <typename T, typename Compare = std::less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;
```

3. BigNum

- Should use python instead of c++ template (cuz it's so long)

4. Custom comparator for STL

```cpp
// Example
struct cmp{
    bool operator()(pii a, pii b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};
```

5. Bash script

```bash
#!/bin/bash

# g++ -g -O2 -std=gnu++17 -static ${files}
run() { g++ -std=c++17 -O2 "$1/solve.cpp" -o "$1/solve" && "$1/solve" < "$1/inp.txt"; }

dbg() { g++ -std=c++17 -g -Wall -Wextra -Wshadow -fsanitize=address,undefined -D_GLIBCXX_DEBUG "$1/solve.cpp" -o "$1/solve_dbg" && "$1/solve_dbg" < "$1/inp.txt"; }

chk() { run "$1" > "$1/my.txt" && diff -Z "$1/my.txt" "$1/out.txt" > /dev/null && echo "==> OK" || echo "==> WA"; }
```
- Note:
    + Check valid shell before run this `cat /etc/shells`
    + Can `source setup.sh`
    + Maybe in some OS (like NixOS boot from USB), it does not work like i thought

6. Random func

```cpp
// It not work for sublime, but maybe in vscode or other IDE
#define _CRT_SECURE_NO_WARNINGS

// GCD(Fib(M), Fib(N)) = Fib(GCD(M,N))

void tmp1() {
    set<pii> s;
    pii p = {0, 0};
    s.insert({0, 2});
    cout << typeid(*s.begin()).name() << '\n';
    // St4pairIiiE
    cout << typeid(p).name() << '\n';
    // St4pairIiiE
    auto it = (*prev(s.end())).fi;
    cout << typeid(it).name() << '\n';
    // i
    
    tuple<int, int, int> tp = {0, 1, 2};
    cout << get<0>(tp);
}

void solve(){
    // vector: v.max_size();
    // set: *next(it, so_ptu_sau_it) *prev(it,.....);
    // size return so_ptu
    // sizeof return ?byte
    // auto it = equal_range(v.begin(), v.end(), 3);
    // cout << it.fi-v.begin() << '\n' << it.se-v.begin();
    // array<int, 3> same with vector, don't know why note it here:))
    // __LINE__ return number of line you write 
}
```