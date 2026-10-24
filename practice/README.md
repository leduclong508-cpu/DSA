# Data Structures & Algorithms — Array Practice Problems

Kho lưu trữ mã nguồn và tài liệu giải thuật chuyên sâu về cấu trúc dữ liệu Mảng (Arrays), được triển khai bằng ngôn ngữ C/C++ từ mức nền tảng (from-scratch) nhằm tối ưu hóa độ phức tạp thuật toán và quản lý bộ nhớ trực tiếp.

* **Tác giả:** Lê Đức Long
* **Môi trường phát triển:** Ubuntu (WSL) / Visual Studio Code / CMake & Ninja Toolchain
* **Tài liệu tham khảo thuật toán:** [DataStructuresAlgorithms (bollwarm)](https://github.com/bollwarm/DataStructuresAlgorithms)

---

## 📑 Danh mục bài tập & Phân tích độ phức tạp

| Thư mục | Tên bài toán | Tệp mã nguồn | Phương pháp giải thuật | Time | Space | Trạng thái |
| :--- | :--- | :--- | :--- | :---: | :---: | :---: |
| [bai1](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai1) | Find Pair with Given Sum | `find_pair_given_sum.cpp`[cite: 2] | Brute Force (Hai vòng lặp lồng) | $O(N^2)$ | $O(1)$ | Hoàn thành |
| [bai2](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai2) | Subarray with 0 Sum Exists | `subarray_0_sum.cpp`[cite: 2] | Brute Force / Prefix Sum Check | $O(N^2)$ | $O(1)$ | Hoàn thành |
| [bai4](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai4) | Sort Binary Array in Linear Time | `sort_binary_linear.cpp`[cite: 2] | Đếm số phần tử (Counting Approach) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai5](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai5) | Find Duplicate in Limited Range | `dupli_element_in_range.cpp`[cite: 2] | Tổng toán học (Mathematical Sum) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai9](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai9) | Dutch National Flag Problem | `Dutch_flag_prob.cpp`[cite: 2] | Counting Sort / Three Pointers | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai10](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai10) | In-place Merge Two Sorted Arrays | `inplace_merge_2sorted.cpp`[cite: 2, 3] | Duy trì bất biến (Insertion Sort Invariant) | $O(m \times n)$ | $O(1)$ | Hoàn thành |
| [bai13](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai13) | Maximum Product of Two Integers | `max_product_in_arr.cpp`[cite: 2, 3] | Sắp xếp & So sánh cực trị biên | $O(N \log N)$ | $O(1)$ | Hoàn thành |
| [bai16](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai16) | Find Equilibrium Index | `equilibrium_index.cpp`[cite: 3] | Tổng tiền tố (Prefix Sum) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai18](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai18) | Move All Zeros to End | `move_zeros_end.cpp`[cite: 3] | Ghi đè tại chỗ (In-place Overwrite) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai21](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai21) | Maximum Difference ($j > i$) | `max_diff_constraints.cpp`[cite: 3] | Duyệt ngược theo vết giá trị lớn nhất | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai22](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai22) | Maximum Subarray Sum | `Kadane_prob.cpp`[cite: 3] | Thuật toán Kadane (Quy hoạch động) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai29](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai29) | Subarray with Given Sum | `subarr_given_sum.cpp`[cite: 3] | Cửa sổ trượt (Sliding Window) | $O(N)$ | $O(1)$ | Hoàn thành |
| [bai35](https://github.com/leduclong508-cpu/DSA/tree/main/practice/bai35) | Trapping Rain Water Problem | `rainWater_within_bars.cpp`[cite: 3] | Hai con trỏ biên (Two Pointers) | $O(N)$ | $O(1)$ | Đang hoàn thiện |

---

## 🛠️ Cấu trúc thư mục

```text
DSA/
├── CMakeLists.txt              # Cấu hình biên dịch tự động toàn bộ bài tập
├── README.md                   # Tài liệu tổng hợp repository
└── practice/
    ├── bai1/                   # Find Pair with Given Sum
    ├── bai2/                   # Subarray with 0 Sum Exists
    ├── bai4/                   # Sort Binary Array in Linear Time
    ├── bai5/                   # Find Duplicate in Limited Range
    ├── bai9/                   # Dutch National Flag (0, 1, 2)
    ├── bai10/                  # In-place Merge Two Sorted Arrays
    ├── bai13/                  # Maximum Product of Two Integers
    ├── bai16/                  # Find Equilibrium Index
    ├── bai18/                  # Move Zeros to End
    ├── bai21/                  # Maximum Difference with Constraints
    ├── bai22/                  # Maximum Subarray (Kadane)
    ├── bai29/                  # Subarray with Given Sum
    └── bai35/                  # Trapping Rain Water