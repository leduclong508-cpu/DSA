# 💻 C/C++ Solutions
*Nhật ký giải thuật và rèn luyện tư duy logic.*

---

##    Ngày 1: 
##  Variable Sized Arrays
- **Link đề bài:** [HackerRank - Variable Sized Arrays](https://www.hackerrank.com/challenges/variable-sized-arrays/problem)

- **Độ phức tạp:**
  - **Time:** **O(N + S + Q)**
    - $N$: Số lượng mảng.
    - $S$: Tổng số phần tử của $N$ mảng cộng lại ($S = k_0 + k_1 + ... + k_{N-1}$).
    - $Q$: Số lượng truy vấn.
  - **Space:** **O(S)** (Lưu trữ toàn bộ các phần tử trong vector 2 chiều).

- **Bug / Ghi chú:**
  - `vector<vector<int>> a(n);` : Khai báo mảng 2 chiều động, số lượng hàng là $n$.
  - `a[i].resize(k);` : Cấp phát độ dài $k$ cho hàng thứ $i$ để tối ưu bộ nhớ thay vì dùng ma trận vuông.

##  Variable Sized Arrays
- **Link đề bài:** [HackerRank - Messages Order](https://www.hackerrank.com/challenges/messages-order/problem?isFullScreen=true)

- **Độ phức tạp:**
  - **Time:** **O(N log N)**
    - $N$: Số lượng tin nhắn (messages).
    - Quá trình tạo tin nhắn mất $O(N)$, nhưng thuật toán `std::sort` trong hàm `fix_order() tiêu tốn $(N \log N)$ để sắp xếp lại mảng.

  - **Space:** **O(N)** 
    - Cần $O(N)$ bộ nhớ cho mảng `vector<Message> message_` để lưu trữ toàn bộ các gói tin trước khi in ra.

- **Bug / Ghi chú:**
  - 
  - `bool operator<(const Message& other) const` : **Nập chồng toán tử (Operator Overloading)**. Dạy các hàm chuẩn của C++ (như `std::sort`) cách so sánh 2 đối tượng (object) do người dùng tự định nghĩa.
  - **Tính đống gói (Encapsulation):** Đặt các biến `text_` và `id_` ở phạm vi `private` để giấu kín dữ liệu, không cho phép bên ngoài sửa đổi trực tiếp mà phải thông qua các hàm được cấp phép.
  - **Factory Pattern (Mẫu thiết kế):** Sử dụng `MessageFactory` làm nhà máy sản xuất gói tin. Nhà máy này tự động quản lý biến đếm `current_id_` và âm thầm đóng dấu ID vào từng `Message` sinh ra.