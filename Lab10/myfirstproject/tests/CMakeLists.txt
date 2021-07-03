add_executable(
unit_tests
sort_unittest.cc
)

target_link_libraries(
unit_tests
gtest_main

)

add_test(
NAME
unit
COMMAND
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)