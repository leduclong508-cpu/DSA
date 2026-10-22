# 🚀 C/C++ Sorting Algorithms: Quick Sort & Merge Sort

Dự án này triển khai hai thuật toán sắp xếp kinh điển dựa trên triết lý **Chia để trị (Divide and Conquer)** bằng ngôn ngữ C/C++ thuần (From Scratch), không sử dụng thư viện hỗ trợ. 

Mục tiêu cốt lõi của dự án là đối chiếu hiệu năng thực thi, cách quản lý bộ nhớ trên RAM và minh họa rõ nét bài toán **Đánh đổi Không gian - Thời gian (Space-Time Tradeoff)** trong Khoa học Máy tính.

---

## 🧠 Nguyên lý Hoạt động (Algorithm Logic)

### 1. Quick Sort (Phân mảnh tại chỗ - In-place Sorting)
Thuật toán hoạt động bằng cách chọn một phần tử làm "Chốt" (Pivot) và phân loại mảng:
*   **Bước 1:** Khởi tạo 2 con trỏ chạy từ hai đầu mảng.
*   **Bước 2:** Dồn toàn bộ các phần tử $\le$ Pivot về bên trái, và các phần tử $>$ Pivot về bên phải.
*   **Bước 3:** Đưa Pivot vào đúng vị trí ranh giới ở giữa.
*   **Bước 4:** Đệ quy lặp lại quá trình trên cho hai mảng con (trái và phải) cho đến khi mảng hoàn toàn được sắp xếp.

### 2. Merge Sort (Sắp xếp trộn - Out-of-place Sorting)
Thuật toán hoạt động theo nguyên tắc chia nhỏ đến tận cùng rồi mới xử lý:
*   **Bước 1 (Divide):** Chẻ đôi mảng liên tục cho đến khi mỗi mảng con chỉ còn đúng 1 phần tử (mặc định đã sắp xếp).
*   **Bước 2 (Conquer/Merge):** Sử dụng kỹ thuật **Hai con trỏ (Two Pointers)** để gộp các mảng con lại. So sánh tuần tự phần tử của mảng Trái (`L`) và mảng Phải (`R`), bốc phần tử nhỏ hơn đè vào mảng gốc.
*   **Bước 3:** Giải phóng vùng nhớ tạm của `L` và `R` để chống rò rỉ bộ nhớ (Memory Leak).

---

## ⚙️ Đánh giá Độ phức tạp & So sánh (Complexity Analysis)

| Tiêu chí | Quick Sort | Merge Sort | Phân tích Hệ thống |
| :--- | :--- | :--- | :--- |
| **Time Complexity (Avg)** | $O(N \log N)$ | $O(N \log N)$ | Cả hai đều chẻ đôi bài toán thành cây nhị phân độ cao $\log N$ và mất $O(N)$ thao tác tại mỗi tầng. |
| **Time Complexity (Worst)**| $O(N^2)$ | $O(N \log N)$ | Quick Sort bị thoái hóa thành $O(N^2)$ nếu chọn sai Pivot liên tục (VD: mảng đã sắp xếp sẵn). Merge Sort luôn ổn định tuyệt đối trong mọi trường hợp. |
| **Space Complexity** | $O(\log N)$ | $O(N)$ | **Sự khác biệt cốt lõi:** Quick Sort hoán đổi trực tiếp trên bộ nhớ gốc (In-place). Merge Sort phải cấp phát động mảng tạm (Out-of-place), tiêu tốn RAM tỷ lệ thuận với kích thước dữ liệu $N$. |
| **Tính Ổn định (Stability)**| Không (Unstable)| Có (Stable) | Merge Sort giữ nguyên thứ tự tương đối của các phần tử có giá trị bằng nhau. |

---

## 💡 Góc nhìn Kiến trúc & Quản lý Bộ nhớ (Advanced Memory Mindset)

Trong quá trình triển khai dự án bằng C/C++, các kiến thức chuyên sâu về bộ nhớ vật lý đã được áp dụng triệt để:

1.  **Tham chiếu ngầm định (Array Decay to Pointer):**
    Khi truyền mảng `a[13]` từ hàm `main` vào các hàm `merge` hay `partition`, C/C++ không copy toàn bộ mảng. Thay vào đó, nó truyền đi **địa chỉ ô nhớ của phần tử đầu tiên** (Pointer). Mọi thao tác gán `arr[k] = L[i]` thực chất là chép thẳng vào ô nhớ vật lý của mảng gốc. Điều này giúp C/C++ đạt tốc độ tối đa và tránh lỗi Stack Overflow do copy mảng dung lượng lớn.
2.  **Quản lý Vòng lặp Hai con trỏ (Two Pointers):**
    Trong hàm `merge`, thay vì để vòng lặp `for` tự động ép các con trỏ tịnh tiến, thuật toán dùng vòng lặp `while` kết hợp chạy thủ công có điều kiện. Con trỏ `i` và `j` chỉ được phép bước tiếp (`i++`, `j++`) khi phần tử nó đang giữ thực sự được rút ra, đảm bảo tính vẹn toàn của dữ liệu khi gộp.
3.  **Xử lý Dữ liệu trùng lặp (Duplicate Handling):**
    Trong hàm `partition` của Quick Sort, điều kiện biên được thiết lập chặt chẽ (`arr[i] <= pivot`) để con trỏ không bị kẹt lại thành vòng lặp vô hạn (Infinite Loop) khi mảng chứa nhiều giá trị giống hệt nhau.

---

## 🛠️ Hướng dẫn Biên dịch và Chạy thử (Build & Run)

Mã nguồn tương thích hoàn toàn với trình biên dịch `gcc/g++` trên hệ điều hành Linux (bao gồm WSL) và Windows.

```bash
# 1. Biên dịch Quick Sort
g++ QuickSort.cpp -o QuickSort

# 2. Biên dịch Merge Sort
g++ MergeSort.cpp -o MergeSort

# 3. Chạy file thực thi
./QuickSort
./MergeSort