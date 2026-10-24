# Check if a Subarray with 0 Sum Exists

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 24/10/2026
* **Chủ đề:** Mảng (Array), Vét cạn (Brute Force), Mảng con (Subarray)

**Mô tả bài toán**
Cho một mảng các số nguyên (bao gồm cả số âm, số 0 và số dương). Yêu cầu kiểm tra xem có tồn tại bất kỳ một mảng con liên tiếp (contiguous subarray) nào có tổng các phần tử đúng bằng `0` hay không. Nếu có, in ra vị trí các chỉ số (hoặc thông báo tồn tại); nếu không, thông báo không tìm thấy.

**Mô tả giải thuật chi tiết (Brute Force Approach)**
1. **Duyệt qua tất cả các điểm bắt đầu:**
   * Sử dụng vòng lặp ngoài với biến `i` chạy từ `0` đến `n - 1` để cố định vị trí bắt đầu của mảng con.
2. **Tính tổng dồn các mảng con liên tiếp:**
   * Tại mỗi vị trí `i`, khởi tạo biến tích lũy `current_sum = 0`.
   * Sử dụng vòng lặp trong với biến `j` chạy từ `i` đến `n - 1` để mở rộng mảng con liên tiếp sang phải.
   * Tại mỗi bước `j`, cộng dồn phần tử hiện tại vào tổng: `current_sum += arr[j]`.
3. **Kiểm tra điều kiện:**
   * Nếu `current_sum == 0`: Tìm thấy mảng con liên tiếp từ chỉ số `i` đến `j` có tổng bằng 0. In ra kết quả và kết thúc hàm ngay lập tức.
4. **Kết luận:** Nếu cả hai vòng lặp duyệt hết toàn bộ các tổ hợp đoạn `[i...j]` mà không có đoạn nào đạt tổng bằng 0, in ra thông báo không tồn tại.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N^2)$ do sử dụng hai vòng lặp lồng nhau để kiểm tra tất cả $\frac{N(N+1)}{2}$ mảng con liên tiếp có thể có.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì chỉ sử dụng các biến đếm và biến lưu tổng tạm thời nguyên thủy (`i`, `j`, `current_sum`), không cần thêm bất kỳ cấu trúc dữ liệu lưu trữ phụ nào.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Có mảng con tổng 0 ở đầu (chuẩn) | `[3, 4, -7, 3, 1, -4, -2, -2]` | `Subarray with 0 sum found from index 0 to 2` |
| **Test 2** | Bản thân một phần tử bằng 0 | `[1, 2, 0, 4]` | `Subarray with 0 sum found from index 2 to 2` |
| **Test 3** | Không tồn tại mảng con tổng 0 | `[1, 2, 3, 4]` | `No subarray with 0 sum exists` |
| **Test 4** | Toàn bộ mảng cộng lại bằng 0 | `[2, -1, -1]` | `Subarray with 0 sum found from index 0 to 2` |
| **Test 5** | Mảng con tổng 0 nằm ở cuối mảng | `[5, 2, -1, -1]` | `Subarray with 0 sum found from index 1 to 3` |