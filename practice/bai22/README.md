# Maximum Subarray Problem (Kadane's Algorithm)

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Quy hoạch động (Dynamic Programming), Thuật toán Kadane

**Mô tả bài toán**
Cho một mảng các số nguyên (có thể chứa cả số âm và số dương). Yêu cầu tìm ra một mảng con liên tiếp (contiguous subarray) có tổng các phần tử đạt giá trị lớn nhất, đồng thời in ra các phần tử của mảng con đó cùng giá trị tổng tương ứng.

**Mô tả giải thuật chi tiết (Kadane's Algorithm with Index Tracking)**
1. **Khởi tạo:**
   * Gán `max_sum` và `current_sum` bằng giá trị của phần tử đầu tiên (`arr[0]`).
   * Sử dụng 3 biến chỉ số: `start` (vị trí bắt đầu mảng con tối ưu), `end` (vị trí kết thúc), và `temp_start` (điểm neo bắt đầu của chuỗi con hiện tại).
2. **Duyệt và tối ưu hóa tổng (Dynamic Programming):**
   * Duyệt tuần tự từng phần tử từ index `0` đến `n - 1`.
   * Tại mỗi vị trí `arr[i]`, đưa ra quyết định:
     * Nếu `arr[i] > current_sum + arr[i]`: Chuỗi tích lũy trước đó làm giảm giá trị của phần tử hiện tại. Ta bắt đầu một chuỗi con mới độc lập tại `i` bằng cách gán `current_sum = arr[i]` và dời điểm neo `temp_start = i`.
     * Ngược lại: Cộng tiếp phần tử hiện tại vào chuỗi con đang xét (`current_sum += arr[i]`).
   * So sánh tổng hiện tại với kỷ lục:
     * Nếu `current_sum > max_sum`: Cập nhật kỷ lục `max_sum = current_sum`, đồng thời chốt vị trí biên `start = temp_start` và `end = i`.
3. **Trích xuất kết quả:** Duyệt một vòng lặp từ `start` đến `end` để in toàn bộ các phần tử thuộc mảng con có tổng lớn nhất ra màn hình.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do thuật toán chỉ duyệt qua mảng đúng một lần duy nhất theo chiều dài $N$.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì chỉ sử dụng các biến đơn lẻ để lưu trữ giá trị và chỉ số biên, không cấp phát thêm bộ nhớ động hay mảng phụ.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Xen kẽ số âm và dương (chuẩn) | `[-2, 1, -3, 4, -1, 2, 1, -5, 4]` | `Subarray: 4 2 1 with sum: 6` |
| **Test 2** | Mảng toàn số âm | `[-8, -3, -6, -2, -5, -4]` | `Subarray: -2 with sum: -2` |
| **Test 3** | Mảng toàn số dương | `[1, 2, 3, 4]` | `Subarray: 1 2 3 4 with sum: 10` |
| **Test 4** | Mảng chỉ có đúng 1 phần tử | `[-5]` | `Subarray: -5 with sum: -5` |
| **Test 5** | Dãy lớn nhất nằm ngay đầu mảng | `[5, 4, -1, -8, 2]` | `Subarray: 5 4 with sum: 9` |