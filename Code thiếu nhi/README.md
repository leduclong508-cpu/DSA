# 💻 C/C++ Solutions
*Nhật ký giải thuật và rèn luyện tư duy logic.*

---

##    NGÀY 1: 12/09 
##  BÀI 1: Find a pair with the given sum in an array
- **Link đề bài:** [github - 1](https://www.techiedelight.com/find-pair-with-given-sum-array/)
- **Các cách làm:**
    - **Cách 1: Brute Force**
        - **Độ phức tạp:**
            - **Time:** **O(N^2)**
                
            - **Space:** **O(1)** 

        - **Bug / Ghi chú:**
            - Cách làm vẫn chưa tối ưu, quá tốn thời gian để xét.

    - **Cách 2: Dùng Sorting + 2 Pointers**
        - **Độ phức tạp:**
            - **Time:** **O(N log N)**
                - Hàm `std::sort` tốn $O(N \log N)$.
                - Vòng lặp `while` tốn $O(N)$ để quét mảng = 2 con trỏ.
                
            - **Space:** **O(1)** 

        - **Bug / Ghi chú:**
            - **2 Pointers:** Kỹ thuật tìm kiếm cặp phần tử khi mảng **đã được sắp xếp**. Thay vì dùng 2 vòng for lồng nhau, thu hẹp phạm vi tìm, giảm thời gian tìm kiếm từ $O(N^2)$ xuống $O(N)$.
            - **Nhược điểm (Edge Case):** Lệnh Sort làm xáo trộn, làm **mất vị trí ban đầu (index)** của các phần tử. Nếu đề bài yêu cầu in ra *vị trí mảng gốc* thay vì *giá trị*, cách này không khả thi trừ khi dùng thêm cấu trúc dữ liệu lưu lại index trước khi sort. 
