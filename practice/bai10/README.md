# In-place Merge Two Sorted Arrays

**Thông tin bài tập**
* **Tác giả:** Le Duc Long
* **Ngày hoàn thành:** 24/10/2026
* **Chủ đề:** Mảng (Array), Sắp xếp (Sorting), Gộp tại chỗ (In-place Merge)

**Mô tả bài toán**
Cho hai mảng số nguyên đã được sắp xếp tăng dần: mảng $X[]$ kích thước $n_1$ và mảng $Y[]$ kích thước $n_2$. Yêu cầu gộp hai mảng này trực tiếp tại chỗ (in-place) sao cho sau khi hoàn tất:
* Mảng $X[]$ chứa $n_1$ phần tử nhỏ nhất và được sắp xếp tăng dần.
* Mảng $Y[]$ chứa $n_2$ phần tử lớn nhất và được sắp xếp tăng dần.
* Không được cấp phát thêm mảng phụ thứ ba ($O(1)$ auxiliary space).

**Mô tả giải thuật chi tiết (Insertion Sort Invariant Approach)**
Thuật toán dựa trên nguyên lý duy trì bất biến: mảng thứ hai (`arr2`) luôn luôn được giữ ở trạng thái sắp xếp tăng dần trong suốt quá trình chạy, nghĩa là phần tử nhỏ nhất của `arr2` luôn luôn nằm ở chỉ số đầu tiên (`arr2[0]`).

1. **Duyệt qua mảng thứ nhất (`arr1`):**
   * Cho vòng lặp `i` chạy từ index $0$ đến $n_1 - 1$.
2. **So sánh và hoán đổi:**
   * Tại mỗi vị trí `arr1[i]`, so sánh nó với phần tử nhỏ nhất hiện tại của `arr2` là `arr2[0]`.
   * Nếu `arr1[i] <= arr2[0]`: Phần tử `arr1[i]` nhỏ hơn toàn bộ các phần tử đang có trong `arr2`. Nó đã đứng đúng vị trí của nửa mảng nhỏ hơn, tiếp tục bước sang phần tử kế tiếp.
   * Nếu `arr1[i] > arr2[0]`: Có một phần tử thuộc `arr2` nhỏ hơn `arr1[i]`. Phần tử nhỏ hơn này phải thuộc về mảng `arr1`. Do đó, hoán đổi hai giá trị `swap(&arr1[i], &arr2[0])`.
3. **Khôi phục tính chất sắp xếp cho mảng thứ hai (Insertion Step):**
   * Sau lệnh swap, giá trị mới nhận tại `arr2[0]` thường là một số lớn, làm phá vỡ trật tự sắp xếp tăng dần của `arr2`.
   * Lưu giá trị vừa swap sang vào biến tạm: `int first = arr2[0]`.
   * Dùng vòng lặp duyệt từ vị trí $k = 1$ trong `arr2`: dịch tất cả các phần tử nhỏ hơn `first` sang bên trái một vị trí (`arr2[k - 1] = arr2[k]`).
   * Khi gặp phần tử lớn hơn hoặc đi hết mảng, đặt `first` vào đúng vị trí trống còn lại (`arr2[k - 1] = first`).
   * Lúc này, `arr2` đã lấy lại trạng thái sắp xếp hoàn chỉnh, chuẩn bị cho lần lặp `i + 1` tiếp theo.

**Độ phức tạp**
* **Độ phức tạp thời gian (Time Complexity):** $O(n_1 \times n_2)$
  * Vòng lặp ngoài duyệt qua $n_1$ phần tử của `arr1`.
  * Ở trường hợp xấu nhất (mỗi bước đều cần swap), bước chèn dịch chuyển trong `arr2` tiêu tốn tối đa $O(n_2)$ phép so sánh và dịch ô nhớ.
* **Độ phức tạp không gian (Space Complexity):** $O(1)$ vì chỉ sử dụng các biến đơn lẻ (`i`, `k`, `first`, `temp`) để thực hiện hoán đổi và dịch chuyển trực tiếp trên hai mảng có sẵn.

**Dữ liệu kiểm thử (Test Cases)**

| Test Case | Mô tả trạng thái mảng | Đầu vào (Input) | Đầu ra (Output) |
| :--- | :--- | :--- | :--- |
| **Test 1** | Hai mảng đan xen giá trị (dữ liệu chuẩn) | `X = [1, 4, 7, 8, 10]`, `Y = [2, 3, 9]` | `X: 1 2 3 4 7`<br>`Y: 8 9 10` |
| **Test 2** | Mảng X đã nhỏ hơn toàn bộ mảng Y | `X = [1, 2, 3]`, `Y = [4, 5, 6]` | `X: 1 2 3`<br>`Y: 4 5 6` |
| **Test 3** | Mảng X lớn hơn toàn bộ mảng Y | `X = [5, 6, 7]`, `Y = [1, 2]` | `X: 1 2 5`<br>`Y: 6 7` |
| **Test 4** | Hai mảng có các phần tử trùng lặp | `X = [1, 3, 5]`, `Y = [1, 2, 6]` | `X: 1 1 2`<br>`Y: 3 5 6` |
| **Test 5** | Mảng Y chỉ có đúng 1 phần tử | `X = [2, 4, 7, 8]`, `Y = [3]` | `X: 2 3 4 7`<br>`Y: 8` |