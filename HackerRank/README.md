# 💻 C/C++ Solutions
*Nhật ký giải thuật và rèn luyện tư duy logic.*

---

## Ngày 1: Variable Sized Arrays
- **Link đề bài:** [HackerRank - Variable Sized Arrays](https://www.hackerrank.com/challenges/variable-sized-arrays/problem)

- **Độ phức tạp:**
  - **Time:** **O(N + S + Q)**
    - $N$: Số lượng mảng.
    - $S$: Tổng số phần tử của $N$ mảng cộng lại ($S = k_0 + k_1 + ... + k_{N-1}$).
    - $Q$: Số lượng truy vấn.
  - **Space:** **O(S)** (Lưu trữ toàn bộ các phần tử trong vector 2 chiều).

- **Bug / Ghi chú:**
  - `vector<vector<int>> a(n);` : Khai báo mảng 2 chiều động, số lượng hàng là $n$.
  - `a[i].resize(k);` : Cấp phát độ dài $k$ cho hàng thứ $i$ để tối ưu bộ nhớ thay vì dùng ma trận vuông.