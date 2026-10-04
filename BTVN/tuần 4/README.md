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

Nếu bài toán yêu cầu **in ra từng bước di chuyển vật lý**, thời gian thực thi sẽ là $O(2^n)$. Tuy nhiên, đoạn code trong dự án này chỉ tập trung vào việc **tính toán tổng số bước**, giúp độ phức tạp được tối ưu rút gọn như sau:

### 1. Cách tiếp cận Đệ quy (Recursive)
*   **Time Complexity:** $O(N)$ - Hàm gọi lại chính nó $N$ lần.
*   **Space Complexity:** $O(N)$ - Mỗi lần gọi đệ quy, CPU đẩy trạng thái vào Stack memory. Nếu $N$ lớn, nguy cơ tràn Call Stack (Stack Overflow) là rất cao.

### 2. Cách tiếp cận Khử Đệ quy (Iterative - Khuyên dùng)
*   **Time Complexity:** $O(N)$ - Vòng lặp `for` duyệt đúng $N$ vòng.
*   **Space Complexity:** $O(1)$ - Không tốn thêm RAM ngoài biến `moves` và `i`. Giải pháp tối ưu cho phần cứng hạn chế.

---

## 📝 Diễn giải các bước thực hiện giải thuật (Algorithm Logic)

### 1. Thuật toán Đệ quy (Recursive)
Để chuyển $n$ đĩa từ cột Nguồn (Source) sang cột Đích (Destination) thông qua cột Trung gian (Auxiliary), giải thuật thực hiện 3 bước:
* **Bước 1:** Chuyển $n-1$ đĩa nằm trên cùng từ cột Nguồn sang cột Trung gian (lấy cột Đích làm trạm trung chuyển).
* **Bước 2:** Chuyển đĩa thứ $n$ (đĩa lớn nhất) từ cột Nguồn sang cột Đích.
* **Bước 3:** Chuyển $n-1$ đĩa từ cột Trung gian sang cột Đích (lấy cột Nguồn làm trạm trung chuyển).
* **Điều kiện dừng (Base case):** Khi $n = 1$, di chuyển đĩa trực tiếp từ Nguồn sang Đích và kết thúc hàm.

### 2. Thuật toán Khử đệ quy (Iterative)
* **Bước 1:** Khởi tạo biến `moves = 0`.
* **Bước 2:** Sử dụng vòng lặp `for` chạy từ `1` đến `n`.
* **Bước 3:** Tại mỗi vòng, áp dụng công thức tích lũy dựa trên quan hệ truy hồi: `moves = moves * 2 + 1`.
* **Bước 4:** Kết thúc vòng lặp, trả về tổng số `moves`.

---

## 💡 Phân tích Mở rộng & Tư duy Hệ thống (Advanced System Mindset)

Trong trường hợp hệ thống yêu cầu **Mô phỏng/In ra từng bước di chuyển vật lý**, bản chất bài toán sẽ mang lại những góc nhìn sâu sắc về Khoa học Máy tính:

*   **Độ phức tạp Hàm mũ (Exponential Time):** Quá trình in bước tốn $O(2^n)$ thời gian và $O(N)$ không gian bộ nhớ. Đây là bài toán kinh điển minh họa cho sự bùng nổ tổ hợp.
*   **Tại sao Quy hoạch động (Dynamic Programming) vô dụng ở đây?** 
    Khác với dãy Fibonacci có các trạng thái lặp lại để lưu vết (Memoization), thao tác chuyển đĩa trong Tháp Hà Nội là độc lập về mặt vật lý (ví dụ: chuyển đĩa 3 từ A $\rightarrow$ C khác hoàn toàn với từ B $\rightarrow$ C). Do không có trạng thái tính toán trùng lặp, ta không thể dùng không gian bộ nhớ để giảm thời gian $O(2^n)$ xuống được. Bài toán buộc phải chạy đủ $2^n - 1$ thao tác.
*   **Tư duy Chia để trị (Divide and Conquer):** Giải thuật này là tiền đề tư duy để viết các thuật toán như Merge Sort hay Quick Sort: Giao việc cho đệ quy xử lý $n-1$ đĩa, tự tay xử lý đĩa lõi, rồi lại gọi đệ quy xử lý phần còn lại.
*   **Ứng dụng Kỹ thuật Thực tế:**
    *   **Chiến lược Sao lưu Dữ liệu:** Quản trị mạng sử dụng chiến lược "Tower of Hanoi backup" (xoay vòng băng từ theo tần suất khác nhau) để giữ được lịch sử backup rất lâu mà tốn ít phần cứng nhất.
    *   **Mã Gray (Gray Code) trong Viễn thông:** Đồ thị chuyển trạng thái của Tháp Hà Nội tương đương 100% với cách lật các bit trong mã Gray, ứng dụng trong truyền tải tín hiệu chống lỗi.
*   **Biến thể 4 cọc (Frame-Stewart Algorithm):** Nếu thêm một cọc thứ tư, độ phức tạp $O(2^n)$ sẽ bị phá vỡ và tối ưu xuống còn $O(2^{\sqrt{2n}})$.

---

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

---

## 🛠️ Hướng dẫn Biên dịch và Cài đặt (Build & Run)

Sử dụng `gcc` (hoặc `g++`) trong môi trường terminal (Linux/WSL) để biên dịch:

```bash
# 1. Biên dịch mã nguồn
gcc recursive_hanoi_tower.cpp -o hanoi_calc

# 2. Chạy file thực thi
./hanoi_calc