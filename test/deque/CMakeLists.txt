add_executable(deque main.cpp)

message(${INCLUDE_ROOT})

target_include_directories(deque PUBLIC ${INCLUDE_ROOT})

#target_link_libraries(main deque)