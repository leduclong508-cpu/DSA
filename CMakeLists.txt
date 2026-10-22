# Phiên bản CMake tối thiểu
cmake_minimum_required(VERSION 3.10)

# Tên dự án tổng của bạn
project(DSA_All_Projects)

# Sử dụng chuẩn C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# QUÉT ĐỆ QUY: Tìm TẤT CẢ các file .cpp trong thư mục dsa và các thư mục con
file(GLOB_RECURSE ALL_SOURCES "*.cpp")

# Lặp qua từng file tìm được
foreach(source IN LISTS ALL_SOURCES)
    
    # Lấy đường dẫn tương đối từ thư mục gốc đến file đó
    # Ví dụ: BTVN/tuần 2/Knapsack problem/DynaProg.cpp
    file(RELATIVE_PATH rel_path ${CMAKE_CURRENT_SOURCE_DIR} ${source})
    
    # Cắt bỏ đuôi .cpp để làm tên
    string(REPLACE ".cpp" "" target_name "${rel_path}")
    
    # Thay thế các dấu gạch chéo '/' và khoảng trắng ' ' thành dấu gạch dưới '_' để đặt tên target không bị lỗi
    # Kết quả: BTVN_tuần_2_Knapsack_problem_DynaProg
    string(REPLACE "/" "_" target_name "${target_name}")
    string(REPLACE " " "_" target_name "${target_name}")
    
    # Tạo file thực thi cho file .cpp đó với cái tên độc nhất vừa tạo
    add_executable(${target_name} ${source})

endforeach()