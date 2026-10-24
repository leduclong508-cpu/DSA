# Sort an Array of 0's, 1's, and 2's (Dutch National Flag Problem)

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 23/10/2026
* **Chủ đề:** Mảng (Array), Sắp xếp (Sorting), Counting Sort

**Mô tả bài toán**
Cho một mảng số nguyên chỉ chứa 3 loại giá trị là `0`, `1` và `2`. Yêu cầu sắp xếp mảng này theo thứ tự tăng dần (tất cả các số `0` đứng đầu, tiếp theo là số `1`, và cuối cùng là số `2`) trong thời gian tuyến tính và sử dụng không gian bộ nhớ hằng số.

**Mô tả giải thuật chi tiết (Counting Approach)**
Cách tiếp cận này dựa trên tư tưởng của thuật toán Counting Sort, thao tác trực tiếp trên mảng gốc qua 2 bước chính:
1. **Đếm tần suất:** 
   - Khởi tạo các biến đếm `zeros`, `ones`, `twos` bằng 0.
   - Duyệt qua mảng một lần (từ $0$ đến $n-1$) để đếm số lượng phần tử `0` và `2`.
   - Số lượng phần tử `1` có thể tính nhanh bằng công thức: `ones = n - zeros - twos`.
2. **Ghi đè dữ liệu (In-place modification):**
   - Sử dụng vòng lặp `for` đầu tiên: Ghi đè giá trị `0` từ vị trí index `0` đến `zeros - 1`.
   - Sử dụng vòng lặp `for` thứ hai: Ghi đè giá trị `1` từ vị trí index `zeros` đến `zeros + ones - 1`.
   - Sử dụng vòng lặp `for` thứ ba: Ghi đè giá trị `2` từ vị trí index `zeros + ones` đến cuối mảng ($n - 1$).

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do thuật toán thực hiện hai lần duyệt qua mảng (một lần để đếm, một lần để ghi đè giá trị).
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì thuật toán chỉ sử dụng một vài biến đếm số nguyên nguyên thủy (`zeros`, `ones`, `twos`, `n`), việc cập nhật được thực hiện trực tiếp trên mảng đầu vào.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Dữ liệu chuẩn (hỗn hợp 3 số) | `[0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 0]` | `[0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2]` |
| **Test 2** | Mảng sắp xếp ngược | `[2, 2, 1, 1, 0, 0]` | `[0, 0, 1, 1, 2, 2]` |
| **Test 3** | Mảng chỉ có 2 loại giá trị | `[2, 0, 2, 0]` | `[0, 0, 2, 2]` |
| **Test 4** | Mảng đã được sắp xếp | `[0, 1, 2]` | `[0, 1, 2]` |
| **Test 5** | Mảng chỉ có 1 loại giá trị | `[1, 1, 1]` | `[1, 1, 1]` |