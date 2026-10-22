# 🚀 06/10/2026: Thuật toán sắp xếp (Insertion Sort & Selection Sort)

Tài liệu này phân tích chi tiết hai thuật toán sắp xếp cơ bản: Sắp xếp chèn (Insertion Sort) và Sắp xếp chọn (Selection Sort), bao gồm ý tưởng, thiết kế, phân tích mã nguồn và kết quả thực thi từng bước.

---

## 1. Ý tưởng thuật toán (Algorithm Concept)

*   **Insertion Sort (Sắp xếp chèn):** Mô phỏng cách chúng ta sắp xếp các lá bài trên tay. Thuật toán chia mảng thành 2 phần: phần đã sắp xếp (bên trái) và phần chưa sắp xếp (bên phải). Lấy lần lượt từng phần tử ở phần chưa sắp xếp và "chèn" nó vào đúng vị trí của nó trong phần đã sắp xếp.
*   **Selection Sort (Sắp xếp chọn):** Thuật toán liên tục tìm kiếm phần tử có giá trị nhỏ nhất trong mảng chưa sắp xếp, sau đó hoán vị (đổi chỗ) phần tử nhỏ nhất đó với phần tử đầu tiên của mảng chưa sắp xếp, qua đó mở rộng dần phần mảng đã sắp xếp.

---

## 2. Xây dựng thuật toán (Algorithm Design)

### Thuật toán Insertion Sort
1.  Bắt đầu vòng lặp ngoài với `i` chạy từ `1` đến `n-1` (giả sử mảng tại `i=0` đã có thứ tự).
2.  Lưu giá trị của `arr[i]` vào biến tạm `key`.
3.  Sử dụng con trỏ `j = i - 1` để quét ngược về đầu mảng.
4.  Chừng nào `j >= 0` và `arr[j] > key`:
    *   Đẩy `arr[j]` lùi về sau một vị trí (`arr[j+1] = arr[j]`).
    *   Giảm `j` đi 1.
5.  Chèn `key` vào vị trí khoảng trống vừa được tạo ra (`arr[j+1] = key`).

### Thuật toán Selection Sort
1.  Bắt đầu vòng lặp ngoài với `i` chạy từ `0` đến `n-2` (vị trí cần đặt phần tử nhỏ nhất).
2.  Giả sử phần tử nhỏ nhất nằm ở `i`, gán `min_idx = i`.
3.  Bắt đầu vòng lặp trong quét từ `j = i + 1` đến `n-1`:
    *   Nếu tìm thấy `arr[j] < arr[min_idx]`, cập nhật lại `min_idx = j`.
4.  Sau khi kết thúc vòng lặp trong, nếu `min_idx` khác `i`, tiến hành hoán đổi giá trị giữa `arr[i]` và `arr[min_idx]`.

---

## 3. Phân tích mã nguồn C++ (Code Analysis)

*   **Xử lý mảng (In-place):** Cả hai đoạn code đều xử lý trực tiếp trên mảng gốc `arr` sinh ra từ cấp phát động mảng VLA (`int arr[n]`), không sử dụng thêm mảng phụ để tiết kiệm bộ nhớ.
*   **Tối ưu hóa thao tác:** 
    *   Trong `insertion_sort.cpp`, thay vì hoán đổi (swap) liên tục tốn kém, code sử dụng phép gán một chiều (shift) để dịch mảng và chỉ thực hiện thao tác gán `key` ở bước cuối cùng.
    *   Trong `selection_sort.cpp`, thao tác tìm kiếm giá trị nhỏ nhất chỉ cập nhật chỉ số `min_idx`. Việc hoán đổi (swap) qua biến `temp` chỉ được gọi **đúng một lần** sau khi đã quét xong toàn bộ mảng con.
*   **Theo dõi (Tracking):** Ở cuối mỗi vòng lặp ngoài của cả hai thuật toán, một vòng lặp `for (int k = 0; k < n; k++)` được tích hợp để in ra toàn bộ trạng thái của mảng, giúp trực quan hóa sự thay đổi qua từng vòng.

---

## 4. Nhận xét độ phức tạp (Complexity Analysis)

| Tiêu chí | Insertion Sort | Selection Sort |
| :--- | :--- | :--- |
| **Độ phức tạp thời gian (Best Case)** | **$O(N)$** (Khi mảng đã có thứ tự sẵn) | **$O(N^2)$** (Vẫn phải quét để tìm Min) |
| **Độ phức tạp thời gian (Worst Case)**| **$O(N^2)$** (Khi mảng đảo ngược hoàn toàn) | **$O(N^2)$** |
| **Độ phức tạp thời gian (Average)** | **$O(N^2)$** | **$O(N^2)$** |
| **Độ phức tạp bộ nhớ (Space)** | **$O(1)$** (In-place) | **$O(1)$** (In-place) |
| **Tính ổn định (Stability)** | **Ổn định (Stable)** - Giữ nguyên thứ tự phần tử bằng nhau | **Không ổn định (Unstable)** |

**Đánh giá:** Insertion Sort vượt trội hơn Selection Sort trong thực tế, đặc biệt là với các mảng dữ liệu có kích thước nhỏ hoặc các mảng đã được sắp xếp gần xong, do nó có khả năng kết thúc sớm vòng lặp trong.

---

## 5. Test Cases

Test case thử nghiệm với mảng dữ liệu ngẫu nhiên có chứa các số trùng lặp (`13`), giá trị lớn nhỏ đan xen để kiểm tra tính ổn định và luồng chạy thực tế.
*   **Số lượng phần tử ($N$):** 13
*   **Mảng đầu vào:** `[101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59]`

---

## 6. Kết quả in ra (Execution Results)

### Kết quả theo vết thuật toán Insertion Sort:
```text
Step 1: 23 101 57 13 25 121 87 36 13 204 111 89 59 
Step 2: 23 57 101 13 25 121 87 36 13 204 111 89 59 
Step 3: 13 23 57 101 25 121 87 36 13 204 111 89 59 
Step 4: 13 23 25 57 101 121 87 36 13 204 111 89 59 
Step 5: 13 23 25 57 101 121 87 36 13 204 111 89 59 
Step 6: 13 23 25 57 87 101 121 36 13 204 111 89 59 
Step 7: 13 23 25 36 57 87 101 121 13 204 111 89 59 
Step 8: 13 13 23 25 36 57 87 101 121 204 111 89 59 
Step 9: 13 13 23 25 36 57 87 101 121 204 111 89 59 
Step 10: 13 13 23 25 36 57 87 101 111 121 204 89 59 
Step 11: 13 13 23 25 36 57 87 89 101 111 121 204 59 
Step 12: 13 13 23 25 36 57 59 87 89 101 111 121 204

### Kết quả theo vết thuật toán Selection Sort:
```text
Step 1: 13 23 57 101 25 121 87 36 13 204 111 89 59 
Step 2: 13 13 57 101 25 121 87 36 23 204 111 89 59 
Step 3: 13 13 23 101 25 121 87 36 57 204 111 89 59 
Step 4: 13 13 23 25 101 121 87 36 57 204 111 89 59 
Step 5: 13 13 23 25 36 121 87 101 57 204 111 89 59 
Step 6: 13 13 23 25 36 57 87 101 121 204 111 89 59 
Step 7: 13 13 23 25 36 57 59 101 121 204 111 89 87 
Step 8: 13 13 23 25 36 57 59 87 121 204 111 89 101 
Step 9: 13 13 23 25 36 57 59 87 89 204 111 121 101 
Step 10: 13 13 23 25 36 57 59 87 89 101 111 121 204 
Step 11: 13 13 23 25 36 57 59 87 89 101 111 121 204 
Step 12: 13 13 23 25 36 57 59 87 89 101 111 121 204