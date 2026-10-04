# C++ Music Recommendation System 🎵

Một hệ thống đề xuất âm nhạc (Music Recommendation Engine) viết bằng C++ hiện đại, ứng dụng thuật toán Lọc cộng tác (Collaborative Filtering). Dự án tập trung vào thiết kế Hướng đối tượng (OOP) sạch, quản lý bộ nhớ an toàn và tối ưu hóa tốc độ truy xuất bằng cấu trúc dữ liệu Hash Table.

## 🚀 Tính năng nổi bật (Key Features)

* **Hệ thống đánh giá trọng số (Weighted Interactions):** Phân loại mức độ yêu thích của người dùng qua các hành động ngầm và công khai (View: 1, Like: 3, Download: 5).
* **Đo lường độ tương đồng (Similarity Calculation):** Tính toán điểm số giao thoa (dot-product) giữa các người dùng dựa trên lịch sử tương tác.
* **Cơ chế đề xuất theo ngưỡng (Benchmark Threshold):** Khắc phục "hiệu ứng buồng vang" (filter bubble) bằng cách đề xuất nhạc từ một cộng đồng người dùng vượt qua điểm chuẩn (Benchmark = 4).
* **Xử lý Dữ liệu ngầm (Implicit Feedback):** Nhận diện sở thích của người dùng lười tương tác thông qua việc cộng dồn điểm số (nghe lặp lại nhiều lần).

* ** Giải thích kĩ càng hơn:**
  * ## 🔬 Cơ sở Lý thuyết & Nguyên lý Kỹ thuật (Theoretical Foundations)

Hệ thống đề xuất này không chỉ là các vòng lặp IF/ELSE đơn thuần, mà được thiết kế dựa trên các khái niệm chuẩn của Khoa học Dữ liệu (Data Science) và Hệ thống Gợi ý (Recommendation Systems):

### 1. Chi phí hành động (Cost of Action) & Heuristics
Hệ thống sử dụng các trọng số tịnh tiến (View: 1, Like: 3, Download: 5) dựa trên khái niệm **Chi phí hành động**. Lướt qua một bài hát có "ma sát" rất thấp, nhưng để tải xuống, người dùng phải hy sinh dung lượng thiết bị. Hành động có chi phí càng cao, độ tin cậy của dữ liệu càng lớn. Các con số này đóng vai trò là các chỉ số suy nghiệm (Heuristics) để lượng hóa sở thích con người thành dữ liệu khả toán.

### 2. Tích vô hướng (Dot-Product) trong Không gian Vector
Mỗi người dùng trong hệ thống được biểu diễn như một vector trong không gian N-chiều (với N là tổng số bài hát). Thuật toán tính điểm tương đồng (`calculateSimilarity`) thực chất là phép nhân vô hướng (Dot-Product) giữa hai vector. Điểm giao thoa càng cao, hai vector càng hướng về chung một cụm sở thích.

### 3. Đa dạng hóa (Diversity) & Tính tình cờ (Serendipity)
Việc sử dụng một ngưỡng Benchmark tĩnh để lọc "Tri kỷ" lấy cảm hứng từ thuật toán tìm kiếm lân cận (Radius-based K-Nearest Neighbors). Nếu chỉ đi tìm DUY NHẤT một người giống hệt mình (Best Match / ArgMax), người dùng sẽ rơi vào **Filter Bubble (Hiệu ứng buồng vang)**. Bằng cách mở rộng Benchmark để lấy một *cộng đồng*, hệ thống tạo ra **Serendipity (Tính tình cờ)** - khả năng thuật toán mang lại những bài hát mới lạ, không ngờ tới nhưng lại rất hợp tai.

### 4. Mức độ tự tin (Confidence Level) trên Dữ liệu ngầm (Implicit Feedback)
Hệ thống giải quyết triệt để bài toán người dùng "bóng ma" (Lurker) bằng cách sử dụng toán tử cộng dồn (`+=`). 
* Nút Like/Download là **Explicit Feedback** (Phản hồi công khai): Chất lượng cao nhưng rất khan hiếm.
* Lượt nghe (View) là **Implicit Feedback** (Phản hồi ngầm): Dồi dào nhưng chứa nhiều nhiễu.
Bằng cách cộng dồn điểm (ví dụ: nghe 4 lần = 4 điểm > 1 nút Like), hệ thống chuyển đổi Tần suất (Frequency) thành Mức độ tự tin (Confidence Level) của thuật toán, đảm bảo không bỏ sót bất kỳ sở thích thực sự nào.

---

## 🧠 Cấu trúc dữ liệu & Kiến trúc (Under the Hood)

Dự án ưu tiên tốc độ xử lý lớn bằng cách tận dụng tối đa các container của C++ Standard Template Library (STL):

1. **`std::unordered_map` (Sparse Matrix Representation):** 
   * Dùng để lưu trữ kho bài hát (`songs`), danh sách người dùng (`users`) và lịch sử tương tác (`interactions`).
2. **`std::unordered_set` (Fast Membership Testing):**
   * Được sử dụng cho `likedSongs`, `viewedSongs`, và mảng lọc `recommendedSongIDs`. Cho phép kiểm tra trạng thái "đã nghe hay chưa" cực nhanh $O(1)$.
3. **Const Correctness:** 
   * Toàn bộ tham số đầu vào và hàm truy vấn đều được gắn mác `const` (vd: `const User& target_user`, `hasViewdSong() const`) để bảo vệ toàn vẹn dữ liệu và tối ưu RAM.

## ⏱️ Đánh giá Độ phức tạp Thuật toán (Complexity Analysis)

* **Thời gian (Time Complexity):** 
  * Tính điểm tương đồng: $O(K)$ (với $K$ là số bài hát đã nghe).
  * Đề xuất bài hát: $O(U \times K)$ (với $U$ là tổng số user). Lọc trùng lặp bằng Hash Set tốn $O(1)$.
* **Không gian (Space Complexity):** $O(S + U \times I)$ (với $S$ là số bài hát, $I$ là lượng tương tác). Đánh đổi bộ nhớ để lấy tốc độ là chiến lược cốt lõi.

---

## 💡 Nhật ký Phát triển & Tư duy Thuật toán (My Development Journey) & Quá trình Tối ưu hóa Hệ thống (System Evolution Log)

Quá trình phát triển dự án tập trung vào việc giải quyết các bài toán tối ưu và liên tục tinh chỉnh kiến trúc để đạt hiệu năng tốt nhất:

### 📅 02/10/2026: Cấu trúc Dữ liệu & Hệ trọng số
* **Tối ưu hóa không gian lưu trữ:** Chuyển đổi từ cấu trúc mảng 2 chiều truyền thống sang `unordered_map` và `unordered_set`. Áp dụng tư duy Ma trận thưa (Sparse Matrix) để chỉ lưu trữ các tương tác thực tế, tiết kiệm đáng kể dung lượng RAM.
* **Thiết lập hệ trọng số:** Xây dựng thang điểm định lượng (View=1, Like=3, Download=5) thay vì kiểm tra trạng thái nhị phân (có/không), giúp đo lường và lượng hóa chính xác mức độ "cùng gu".

### 📅 03/10/2026: Business Logic & Const Correctness
* **Thay đổi kiến trúc cốt lõi (Từ ArgMax sang Benchmark):** Từ bỏ hướng đi tìm "duy nhất một Best Match" để tránh Hiệu ứng buồng vang (Filter Bubble). Triển khai cơ chế Ngưỡng điểm (Benchmark >= 4) để trích xuất một cộng đồng người dùng, tạo ra sự đa dạng và tính tình cờ (Serendipity) trong danh sách đề xuất.
* **Xử lý Edge Case (Implicit Data):** Giải quyết bài toán người dùng "bóng ma" (chỉ nghe, không tương tác) bằng cách thiết kế hệ điểm cộng dồn (`+=`). Ví dụ: 3 lần lướt nghe = 3 điểm (tương đương 1 Like), giúp hệ thống thu thập trọn vẹn dữ liệu ngầm mà không bị bỏ sót.
* **Áp dụng Const Correctness:** Triển khai triệt để từ khóa `const` ở các input và cuối method. Việc này vừa tận dụng pass-by-reference để tiết kiệm tài nguyên hệ thống, vừa khóa chặt trạng thái của object, đảm bảo an toàn bộ nhớ (memory-safe).

### 📅 04/10/2026: Tư duy Quy hoạch động (DP Mindset) & Hoàn thiện
* **Áp dụng triết lý Space-Time Tradeoff (Đánh đổi bộ nhớ lấy thời gian):** Lấy cảm hứng từ thuật toán Quy hoạch động (Lưu kết quả bài toán con để tránh tính toán lại). Hệ thống ưu tiên cấp phát thêm RAM cho Hash Map/Set để lưu trữ trạng thái (State) lịch sử nghe nhạc, đưa các vòng lặp quét $O(N)$ nặng nề về các truy vấn $O(1)$ chớp nhoáng.
* **Hoàn thiện bản chất vật lý:** Chuẩn hóa các giá trị khởi tạo (như cờ hiệu `-1`) và đảm bảo kiểm soát chặt chẽ luồng dữ liệu trên bộ nhớ.
---

## 🛠️ Hướng dẫn cài đặt & Chạy thử (Build & Run)

**Bước 1:** Khởi động Terminal và biên dịch mã nguồn (yêu cầu chuẩn C++11 trở lên):
```bash
g++ -std=c++17 RecommendSong.cpp -o RecommendSong