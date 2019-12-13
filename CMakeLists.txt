cmake_minimum_required(VERSION 3.15)
project(pg)

set(CMAKE_CXX_STANDARD 17)

add_executable(pg main.cpp )

add_subdirectory(CommandManager)
add_subdirectory(BinToolsLib)
add_subdirectory(Department)
add_subdirectory(Person)

target_link_libraries(DepartmentLib BinToolsLib)
target_link_libraries(DepartmentLib PersonLib)

target_link_libraries(CommandManagerLib BinToolsLib)
target_link_libraries(CommandManagerLib DepartmentLib)
target_link_libraries(CommandManagerLib PersonLib)
target_link_libraries(pg CommandManagerLib)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/dep.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/per.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
