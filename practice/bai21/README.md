# Find Maximum Difference Between Two Elements in an Array

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Duyệt ngược (Reverse Traversal)

**Mô tả bài toán**
Cho một mảng số nguyên. Yêu cầu tìm hiệu số lớn nhất giữa hai phần tử `arr[j] - arr[i]` sao cho phần tử lớn hơn xuất hiện sau phần tử nhỏ hơn trong mảng (tức là $j > i$ và $arr[j] > arr[i]$). Nếu mảng giảm dần hoặc không tồn tại cặp phần tử nào thỏa mãn, trả về `-1`.

**Mô tả giải thuật chi tiết (Reverse Traversal Approach)**
1. **Khởi tạo:**
   * Đặt biến lưu hiệu số lớn nhất `diff = -1`.
   * Khởi tạo `max_value = arr[n - 1]`, đóng vai trò lưu giữ phần tử lớn nhất đã gặp được khi quét từ cuối mảng ngược về đầu.
2. **Duyệt ngược từ phải sang trái:**
   * Cho vòng lặp chạy từ vị trí `i = n - 2` lùi dần về `0`.
   * Tại mỗi vị trí `arr[i]`:
     * Nếu `arr[i] > max_value`: Cập nhật lại kỷ lục phần tử lớn nhất phía sau `max_value = arr[i]`.
     * Ngược lại (khi `arr[i] <= max_value`): Tính hiệu số `max_value - arr[i]` và cập nhật kỷ lục `diff = max(diff, max_value - arr[i])`.
3. **Kết luận:** Sau khi duyệt hết mảng, `diff` sẽ chứa giá trị chênh lệch lớn nhất thỏa mãn điều kiện $j > i$.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do chỉ cần duyệt qua mảng đúng một lần từ cuối về đầu.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì thuật toán chỉ sử dụng hai biến số nguyên phụ trợ (`diff` và `max_value`), không cấp phát thêm bộ nhớ động.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Dữ liệu ngẫu nhiên tiêu chuẩn | `[2, 7, 9, 5, 1, 3, 5]` | `Maximum difference is: 7` |
| **Test 2** | Mảng giảm dần liên tục (không có cặp thỏa mãn) | `[9, 8, 7, 6, 5]` | `Maximum difference is: -1` |
| **Test 3** | Mảng tăng dần liên tục | `[1, 2, 6, 80, 100]` | `Maximum difference is: 99` |
| **Test 4** | Phần tử lớn nhất nằm ở đầu mảng | `[10, 3, 6, 8, 9, 2]` | `Maximum difference is: 6` |
| **Test 5** | Mảng có các phần tử bằng nhau | `[4, 4, 4, 4]` | `Maximum difference is: -1` |