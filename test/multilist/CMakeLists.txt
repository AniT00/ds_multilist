add_executable(multilist "multilist.cpp")

message(${INCLUDE_ROOT})

target_include_directories(multilist PUBLIC ${INCLUDE_ROOT})

#target_link_libraries(main deque)