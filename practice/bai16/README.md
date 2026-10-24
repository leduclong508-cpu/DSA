# Find Equilibrium Index of an Array

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Tổng tiền tố (Prefix Sum)

**Mô tả bài toán**
Cho một mảng các số nguyên. Điểm cân bằng (Equilibrium Index) của mảng là vị trí chỉ số (index) mà tổng các phần tử nằm bên trái nó bằng tổng các phần tử nằm bên phải nó. Yêu cầu tìm và in ra chỉ số cân bằng đầu tiên xuất hiện trong mảng, hoặc thông báo nếu không tồn tại.

**Mô tả giải thuật chi tiết (Prefix Sum Approach)**
1. **Tính tổng toàn mảng:** Duyệt qua mảng một lần để tính tổng toàn bộ các phần tử và lưu vào biến `sum`.
2. **Khởi tạo biến theo dõi:** Khởi tạo biến `left_sum = 0` để lưu tổng các phần tử nằm bên trái chỉ số hiện tại.
3. **Duyệt và kiểm tra điều kiện cân bằng:** Duyệt tuần tự từng phần tử từ index `0` đến `n - 1`:
   * Tính tổng các phần tử bên phải tại vị trí `i` bằng công thức: `right_sum = sum - left_sum - arr[i]`.
   * So sánh nếu `left_sum == right_sum`: Vị trí `i` chính là chỉ số cân bằng cần tìm. In ra kết quả và kết thúc hàm ngay lập tức.
   * Nếu không thỏa mãn: Cập nhật biến `left_sum += arr[i]` rồi tiếp tục xét phần tử tiếp theo.
4. **Kết luận:** Nếu duyệt hết mảng mà không thỏa mãn điều kiện tại bất kỳ vị trí nào, in ra thông báo "No equilibrium index found".

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do chỉ sử dụng hai vòng lặp duyệt tuần tự độc lập (một vòng lặp tính tổng toàn mảng và một vòng lặp kiểm tra điểm cân bằng).
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì thuật toán chỉ sử dụng hai biến số nguyên phụ trợ (`sum` và `left_sum`), không cấp phát thêm bất kỳ mảng hay cấu trúc dữ liệu lưu trữ nào.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Điểm cân bằng nằm ở đầu mảng (dữ liệu chuẩn) | `[0, -3, 5, -4, -2, 3, 1, 0]` | `Equilibrium index is 0` |
| **Test 2** | Điểm cân bằng nằm ở giữa mảng | `[-7, 1, 5, 2, -4, 3, 0]` | `Equilibrium index is 3` |
| **Test 3** | Không tồn tại điểm cân bằng | `[1, 2, 3]` | `No equilibrium index found` |
| **Test 4** | Mảng chỉ có đúng 1 phần tử | `[5]` | `Equilibrium index is 0` |
| **Test 5** | Điểm cân bằng nằm ở cuối mảng | `[1, -1, 4]` | `Equilibrium index is 2` |