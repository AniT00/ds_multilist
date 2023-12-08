add_executable(deque "deque.cpp")

message(${INCLUDE_ROOT})

target_include_directories(deque PUBLIC ${INCLUDE_ROOT})

#target_link_libraries(main deque)