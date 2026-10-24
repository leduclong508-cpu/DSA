# Find Subarray Having Given Sum in Given Array of Integers

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Cửa sổ trượt (Sliding Window), Hai con trỏ (Two Pointers)

**Mô tả bài toán**
Cho một mảng các số nguyên không âm và một giá trị tổng mục tiêu (`target`). Yêu cầu tìm ra vị trí bắt đầu và kết thúc của một mảng con liên tiếp đầu tiên có tổng các phần tử đúng bằng giá trị mục tiêu đã cho. Nếu không tồn tại, in ra thông báo tương ứng.

**Mô tả giải thuật chi tiết (Sliding Window Approach)**
*Giả định: Toàn bộ phần tử trong mảng là số nguyên không âm ($arr[i] \ge 0$).*
1. **Khởi tạo cửa sổ trượt:**
   * Khởi tạo biến lưu tổng cửa sổ `current_sum = 0`.
   * Sử dụng hai con trỏ `left = 0` (cạnh trái cửa sổ) và `right = 0` (cạnh phải cửa sổ).
2. **Duyệt và điều chỉnh kích thước cửa sổ:**
   * Tăng dần con trỏ `right` từ `0` đến `n - 1` để mở rộng cửa sổ sang phải: `current_sum += arr[right]`.
   * Nếu tổng hiện tại vượt quá mục tiêu (`current_sum > target`) và cửa sổ vẫn hợp lệ (`left <= right`), tiến hành thu hẹp cửa sổ từ phía bên trái bằng cách trừ dần `arr[left]` khỏi `current_sum` và tăng `left` lên $1$ đơn vị liên tục cho đến khi tổng nhỏ hơn hoặc bằng `target`.
   * Kiểm tra điều kiện:
     * Nếu `current_sum == target`: Đã tìm thấy mảng con cần tìm. In ra dải chỉ số từ `left` đến `right` và kết thúc hàm ngay lập tức.
3. **Kết luận:** Nếu con trỏ `right` đi hết mảng mà không tìm thấy tổng hợp lệ, in ra thông báo "No subarray found with the given sum."

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ vì mỗi con trỏ `left` và `right` chỉ dịch chuyển từ đầu đến cuối mảng tối đa một lần, không có hiện tượng quay lui (backtracking).
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ do thuật toán hoạt động trực tiếp trên mảng ban đầu thông qua các chỉ số, không sử dụng cấu trúc lưu trữ phụ như Hash Map.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Dữ liệu ngẫu nhiên (chuẩn) | `nums = [2, 6, 0, 9, 7, 3, 1, 4, 1, 10]`, `target = 15` | `Subarray found from index 1 to 3` |
| **Test 2** | Mảng con nằm ngay tại vị trí đầu | `nums = [5, 10, 20, 30]`, `target = 15` | `Subarray found from index 0 to 1` |
| **Test 3** | Mảng con chỉ gồm 1 phần tử duy nhất | `nums = [1, 4, 20, 3, 10, 5]`, `target = 20` | `Subarray found from index 2 to 2` |
| **Test 4** | Không tìm thấy tổng mục tiêu | `nums = [1, 2, 3, 4]`, `target = 100` | `No subarray found with the given sum.` |
| **Test 5** | Mảng con nằm ở cuối mảng | `nums = [3, 2, 5, 8]`, `target = 13` | `Subarray found from index 2 to 3` |