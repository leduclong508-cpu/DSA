# Move All Zeros Present in the Array to the End

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Ghi đè tại chỗ (In-place Overwrite)

**Mô tả bài toán**
Cho một mảng số nguyên bất kỳ có chứa các phần tử số `0` xen kẽ với các số khác. Yêu cầu di chuyển toàn bộ các số `0` về cuối mảng mà vẫn giữ nguyên thứ tự tương đối ban đầu của tất cả các phần tử khác 0.

**Mô tả giải thuật chi tiết (In-place Overwrite Approach)**
1. **Duyệt và gom phần tử khác 0:**
   * Sử dụng biến con trỏ ghi đè `count = 0` đại diện cho vị trí tiếp theo sẽ lưu phần tử khác 0.
   * Duyệt qua từng phần tử từ index `0` đến `n - 1`. Khi gặp một phần tử khác 0 (`arr[i] != 0`), gán giá trị đó vào vị trí `arr[count]` rồi tăng `count` lên 1 đơn vị.
   * Thao tác này giúp dồn toàn bộ các giá trị khác 0 về nửa đầu mảng một cách tuần tự và bảo toàn nguyên vẹn thứ tự xuất hiện ban đầu.
2. **Điền số 0 vào phần còn lại:**
   * Sau khi duyệt hết mảng, biến `count` chính là tổng số lượng các phần tử khác 0.
   * Chạy một vòng lặp từ vị trí `count` đến cuối mảng ($n - 1$) và gán giá trị `0` cho tất cả các vị trí này.
3. **In kết quả:** Duyệt lại mảng để in toàn bộ các giá trị đã được sắp xếp lại ra màn hình.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do thuật toán chỉ duyệt qua mảng theo các bước tuần tự độc lập (một vòng lặp dồn số khác 0, một vòng lặp điền số 0 và một vòng lặp in kết quả).
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì việc dồn và điền dữ liệu diễn ra trực tiếp trên mảng đầu vào (in-place), chỉ sử dụng thêm một biến đếm số nguyên phụ trợ (`count`).

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Dữ liệu ngẫu nhiên xen kẽ | `[6, 0, 8, 2, 3, 0, 4, 0, 1]` | `[6, 8, 2, 3, 4, 1, 0, 0, 0]` |
| **Test 2** | Số 0 nằm toàn bộ ở đầu mảng | `[0, 0, 0, 1, 2, 3]` | `[1, 2, 3, 0, 0, 0]` |
| **Test 3** | Mảng đã chuẩn (số 0 nằm cuối) | `[1, 2, 3, 0, 0]` | `[1, 2, 3, 0, 0]` |
| **Test 4** | Mảng không chứa số 0 nào | `[1, 2, 3, 4, 5]` | `[1, 2, 3, 4, 5]` |
| **Test 5** | Mảng chỉ chứa toàn số 0 | `[0, 0, 0]` | `[0, 0, 0]` |