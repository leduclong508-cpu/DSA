# Find a Duplicate Element in a Limited Range Array

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Toán học (Mathematical Sum)

**Mô tả bài toán**
Cho một mảng gồm $N$ phần tử, trong đó các giá trị nằm trong phạm vi từ $1$ đến $N-1$. Theo nguyên lý Dirichlet (Pigeonhole Principle), chắc chắn có ít nhất một phần tử bị lặp lại trong mảng. Yêu cầu tìm và trả về giá trị của phần tử bị trùng lặp đó.

**Mô tả giải thuật chi tiết (Mathematical Sum Approach)**
1. Tính tổng thực tế của toàn bộ các phần tử đang có trong mảng (gọi là `sum`).
2. Vì mảng chứa các số từ $1$ đến $N-1$, ta tính tổng lý tưởng (kỳ vọng) của dãy số liên tiếp từ $1$ đến $N-1$ bằng công thức Gauss: $\frac{(N-1) \times N}{2}$ (gọi là `expected_sum`).
3. Giá trị phần tử bị lặp lại chính là phần dư ra khi lấy tổng thực tế trừ đi tổng kỳ vọng (`sum - expected_sum`).

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do chỉ cần duyệt qua mảng đúng một lần để tính tổng thực tế.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì chỉ sử dụng thêm các biến lưu trữ tổng số nguyên, không phụ thuộc vào kích thước mảng đầu vào.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Dữ liệu chuẩn (lặp ở cuối) | `[1, 2, 3, 4, 4]` | `4` |
| **Test 2** | Lặp ở đầu mảng | `[2, 1, 2]` | `2` |
| **Test 3** | Mảng lớn hơn không theo thứ tự | `[3, 1, 4, 2, 5, 1]` | `1` |
| **Test 4** | Mảng chỉ có 2 phần tử | `[1, 1]` | `1` |