# Find Maximum Product of Two Integers in an Array

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Toán học (Math), Sắp xếp (Sorting)

**Mô tả bài toán**
Cho một mảng số nguyên (có thể chứa số âm, số 0 và số dương). Yêu cầu tìm ra hai phần tử bất kỳ trong mảng sao cho tích của chúng là lớn nhất và in ra giá trị tích đó.

**Mô tả giải thuật chi tiết (Sorting Approach)**
1. **Kiểm tra biên:** Nếu kích thước mảng $N < 2$, mảng không đủ số lượng phần tử để tạo thành một cặp. Thuật toán in ra thông báo "No pairs exist" và kết thúc sớm.
2. **Sắp xếp mảng:** Sử dụng hàm `std::sort` để sắp xếp toàn bộ các phần tử trong mảng theo thứ tự tăng dần.
3. **Phân tích toán học:** Tích lớn nhất của hai số trong mảng luôn rơi vào một trong hai trường hợp cực trị:
   * Trường hợp 1 (Tích hai số dương lớn nhất): Chính là tích của hai phần tử nằm ở cuối mảng đã sắp xếp (`arr[n-1] * arr[n-2]`).
   * Trường hợp 2 (Tích hai số âm bé nhất): Vì số âm nhân số âm sẽ tạo ra số dương, tích này có thể lớn hơn tích các số dương. Nó là tích của hai phần tử nằm ở đầu mảng đã sắp xếp (`arr[0] * arr[1]`).
4. **So sánh và Kết luận:** Khối lệnh `if-else` so sánh hai giá trị tích trên, giá trị nào lớn hơn sẽ được in ra làm kết quả cuối cùng.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N \log N)$ do thuật toán phụ thuộc hoàn toàn vào tốc độ của hàm `std::sort`. Các phép toán nhân và so sánh mảng diễn ra sau đó chỉ tốn $O(1)$.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ đối với logic thuật toán tự cài đặt, do không sử dụng thêm cấu trúc dữ liệu bên ngoài. Tùy thuộc vào trình biên dịch, bản thân hàm `std::sort` (Introsort) có thể tiêu tốn tối đa $O(\log N)$ không gian bộ nhớ trên Call Stack.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Có số âm tạo tích dương lớn nhất (dữ liệu chuẩn) | `[-10, -3, 5, 6, -20]` | `Max product is 200` |
| **Test 2** | Toàn bộ là số dương | `[1, 4, 3, 6, 2, 7]` | `Max product is 42` |
| **Test 3** | Toàn bộ là số âm | `[-8, -5, -2, -9, -1]` | `Max product is 72` |
| **Test 4** | Mảng có chứa số 0 | `[0, -1, 3, 0]` | `Max product is 0` |
| **Test 5** | Mảng không đủ 2 phần tử (cạnh biên) | `[5]` | `No pairs exist` |