# 💻 C/C++ Solutions
*Nhật ký giải thuật và rèn luyện tư duy logic.*

---

## NGÀY: 15/09/2026
## BÀI TẬP: Find a pair with the given sum in an array
*   **Link đề bài:** [Techie Delight](https://www.techiedelight.com/find-pair-with-given-sum-array/)
*   **Mục tiêu:** Tìm 2 phần tử trong mảng có tổng bằng `target`.

### Cách 1: Brute Force (Vét cạn) - Không ưu tiên
*   Dùng 2 vòng `for` lồng nhau để thử mọi cặp số. 
*   **Độ phức tạp:** Thời gian O(N^2), Không gian O(1).
*   **Hạn chế:** Quá chậm khi mảng có hàng triệu phần tử.

---

### Cách 2: Sắp xếp (Sorting) + Kỹ thuật 2 Con trỏ (Two Pointers)
**Cơ chế chung:** Xếp mảng tăng dần trước. Sau đó dùng 2 "con trỏ" (`left` ở đầu, `right` ở cuối) dò tiến/lùi vào giữa. Tổng nhỏ hơn `target` thì tiến `left`, lớn hơn thì lùi `right`. Thời gian rút xuống còn O(N log N).

#### Hướng 2.1: Dùng thư viện chuẩn (`std::sort`)
*   **Phải làm gì:** Include `<algorithm>` và gọi `std::sort(arr, arr + n);`.
*   **Sự khác biệt:** Code cực ngắn gọn, sạch sẽ, chạy chắc chắn đúng. 
*   **Hạn chế của hướng này:** Nó giống như một "hộp đen" (black box). Mình chỉ biết ném dữ liệu vào và lấy kết quả ra, không học được cách máy tính thao tác vật lý trên bộ nhớ (RAM) như thế nào.

#### Hướng 2.2: Không dùng thư viện (Tự code Quick Sort từ con số 0)
*   **Phải làm gì:** Tự xây dựng 3 hàm riêng biệt: `swap` (đổi chỗ), `partition` (quy hoạch phân mảnh) và `quickSort` (chia để trị).
*   **Phần mới học được:**
    *   **Tư duy "Chia để trị" (Divide & Conquer):** Băm mảng to thành các mảng nhỏ để trị.
    *   **In-place Sorting:** Kỹ thuật thao tác ép trực tiếp trên mảng gốc, không cần phải tạo thêm mảng phụ gây tốn dung lượng bộ nhớ.
*   **Phần "LÚ" nhất (Hàm `partition`):**
    1.  **Lỗi khởi tạo `i`:** Ban đầu rất dễ đặt `i = low`. Nhưng ĐÚNG phải là `i = low - 1`. Khởi tạo `i = low - 1` để coi như "khu vực số nhỏ" đang rỗng (nằm ngoài mảng). Nếu đặt `i = low` sẽ vô tình khóa mất vị trí số 0 của mảng, làm sai lệch toàn bộ mảng.
    2.  **Sự tách biệt giữa `i` và `j`:** Vòng lặp `for` làm biến `j` chạy liên tục, nhưng `i` chỉ tăng khi tìm thấy số nhỏ. Số lớn ngẫu nhiên sẽ bị ngó lơ, rớt lại phía sau ranh giới `i`.
    3.  **Cú chốt hạ:** Lệnh `swap(&arr[i+1], &arr[high])` nằm ngoài vòng `for` chính là thao tác bắt buộc để kẹp số mốc (pivot) vào chính giữa khu vực số lớn và số nhỏ.
*   **💡 Bài học rút ra:**
    *   Tự code thuật toán giúp bản thân thực sự kiểm soát được các con trỏ (pointers).
    *   **Sự đánh đổi (Trade-off):** Dù dùng hướng 2.1 hay 2.2, việc sắp xếp mảng làm **MẤT ĐI VỊ TRÍ (INDEX) GỐC** của dữ liệu. Nếu đề bài yêu cầu in ra "Vị trí của 2 số ban đầu" thay vì "Giá trị của 2 số", cách Sorting sẽ phá sản (hoặc phải tốn công viết thêm Struct/Class để lưu vết vị trí cũ).