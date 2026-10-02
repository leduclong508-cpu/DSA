# 🗼 Tower of Hanoi: Minimum Moves Calculation

Dự án này triển khai thuật toán tính số bước di chuyển tối thiểu để giải quyết bài toán Tháp Hà Nội (Tower of Hanoi) bằng ngôn ngữ C/C++. 

Repository cung cấp 2 phương pháp tiếp cận: **Đệ quy (Recursive)** và **Khử đệ quy (Iterative)** để đối chiếu hiệu năng quản lý bộ nhớ và tốc độ thực thi.

---

## 📐 Nền tảng Toán học (Mathematical Foundation)

Số bước di chuyển đĩa trong tháp Hà Nội tuân theo hệ thức truy hồi (Recurrence Relation):
*   **Điều kiện cơ sở:** $T(1) = 1$
*   **Hệ thức:** $T(n) = 2T(n-1) + 1$

Bằng phương pháp khai triển, ta có thể chứng minh phương trình tổng quát cho bài toán này là một cấp số nhân:
$T(n) = 2^n - 1$

---

## ⚙️ Đánh giá Độ phức tạp (Complexity Analysis)

Mặc dù bài toán in ra từng bước đi của Tháp Hà Nội tốn $O(2^n)$ thời gian, đoạn code trong dự án này chỉ tập trung vào việc **tính toán số bước**. Độ phức tạp được rút gọn như sau:

### 1. Cách tiếp cận Đệ quy (Recursive)
*   **Time Complexity:** $O(N)$ - Hàm gọi lại chính nó $N$ lần.
*   **Space Complexity:** $O(N)$ - Mỗi lần gọi đệ quy, CPU phải đẩy trạng thái vào Stack memory. Nếu $N$ lớn, nguy cơ tràn bộ nhớ Call Stack (Stack Overflow) là rất cao.

### 2. Cách tiếp cận Khử Đệ quy (Iterative - Khuyên dùng)
*   **Time Complexity:** $O(N)$ - Vòng lặp `for` duyệt đúng $N$ vòng.
*   **Space Complexity:** $O(1)$ - Không tốn thêm bất kỳ vùng nhớ RAM nào ngoài biến `moves` và biến chạy `i`. Đây là giải pháp tối ưu cho phần cứng hạn chế.

---

## 🛠️ Hướng dẫn Biên dịch và Cài đặt (Build & Run)

Sử dụng `gcc` (hoặc `g++`) trong môi trường terminal (Linux/WSL) để biên dịch:

```bash
# 1. Biên dịch mã nguồn
gcc recursive_hanoi_tower.cpp -o hanoi_calc

# 2. Chạy file thực thi
./hanoi_calc

## 🧪 Kịch bản Kiểm thử (Test Cases)

Bảng dưới đây liệt kê các kịch bản kiểm thử đã được thực hiện để đảm bảo tính chính xác và độ bền (robustness) của thuật toán, đặc biệt là sau khi đã tái cấu trúc (refactor) điều kiện cơ sở.

| Mã TC | Đầu vào (`n`) | Kết quả mong đợi | Phân loại (Type) | Tình trạng | Ghi chú / Đánh giá |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **TC_01** | `3` | `7` | Normal | ✅ Pass | Thuật toán tính đúng theo công thức $2^n - 1$. |
| **TC_02** | `5` | `31` | Normal | ✅ Pass | Xử lý tốt các mốc tính toán thông thường. |
| **TC_03** | `1` | `1` | Boundary | ✅ Pass | Biên dưới cùng hợp lệ của bài toán thực tế. |
| **TC_04** | `0` | `0` | Edge Case | ✅ Pass | Đã khắc phục lỗi Stack Overflow nhờ cơ chế Early Return (`if n < 1`). |
| **TC_05** | `-5` | `0` | Edge Case | ✅ Pass | Chặn thành công các giá trị âm không hợp lệ. |
| **TC_06** | `31` | `2147483647` | Boundary | ✅ Pass | Chạm ngưỡng giới hạn lưu trữ tối đa của kiểu `int` 32-bit có dấu. |
| **TC_07** | `32` | Tràn số / Lỗi | Stress Test | ⚠️ Known Bug | Gây tràn bộ nhớ (Integer Overflow), kết quả bị đảo thành số âm. Yêu cầu nâng cấp kiểu dữ liệu nếu cần xử lý lượng đĩa lớn hơn. |