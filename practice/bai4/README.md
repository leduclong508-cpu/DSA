# Sort a Binary Array in Linear Time

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 13/09/2026
* **Chủ đề:** Mảng (Array), Sắp xếp (Sorting)

**Mô tả bài toán**
Cho một mảng nhị phân chỉ chứa các phần tử `0` và `1` xuất hiện ngẫu nhiên. Yêu cầu sắp xếp mảng này sao cho toàn bộ số `0` nằm ở đầu mảng và số `1` nằm ở cuối mảng trong thời gian tuyến tính và không gian hằng số.

**Mô tả giải thuật chi tiết (Counting Approach)**
1. Khởi tạo một biến đếm `zeros = 0` dùng để lưu trữ tổng số lượng phần tử `0` có trong mảng.
2. Quét qua toàn bộ mảng một lần (từ vị trí $0$ đến $n-1$). Tại mỗi vị trí, nếu phần tử có giá trị bằng `0`, ta tăng biến `zeros` thêm $1$.
3. Sau khi kết thúc vòng lặp đầu tiên, ta đã biết chính xác số lượng số `0`. Khởi tạo một biến chỉ mục `j = 0` để theo dõi vị trí đang ghi đè.
4. Sử dụng một vòng lặp `while` để chạy đúng `zeros` lần. Ở mỗi lần lặp, ghi đè giá trị `0` vào mảng tại vị trí `j` và tăng `j` lên $1$.
5. Tiếp tục sử dụng vòng lặp `while` thứ hai từ vị trí `j` hiện tại cho đến khi đi hết mảng ($j < n$). Tại các vị trí này, ghi đè giá trị `1` và tăng `j` lên $1$.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(N)$ do ta quét qua mảng theo hai giai đoạn nối tiếp nhau (một vòng lặp đếm và các vòng lặp ghi đè), thời gian thực thi tỷ lệ thuận với số lượng phần tử $N$.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ do thuật toán thực hiện ghi đè dữ liệu trực tiếp trên mảng gốc (in-place modification) mà không cần cấp phát thêm bộ nhớ cho mảng phụ hay cấu trúc dữ liệu khác.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Mảng ngẫu nhiên (dữ liệu chuẩn) | `[0, 0, 1, 0, 1, 1, 0, 1, 0, 0]` | `[0, 0, 0, 0, 0, 0, 1, 1, 1, 1]` |
| **Test 2** | Mảng đã được sắp xếp sẵn | `[0, 0, 1, 1]` | `[0, 0, 1, 1]` |
| **Test 3** | Mảng sắp xếp ngược | `[1, 1, 0, 0]` | `[0, 0, 1, 1]` |
| **Test 4** | Mảng chỉ toàn số 1 (cạnh biên) | `[1, 1, 1, 1]` | `[1, 1, 1, 1]` |
| **Test 5** | Mảng chỉ có 1 phần tử | `[0]` | `[0]` |

