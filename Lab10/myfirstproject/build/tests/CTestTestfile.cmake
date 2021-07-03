# CMake generated Testfile for 
# Source directory: C:/Users/Sergiu/Desktop/myfirstproject/tests
# Build directory: C:/Users/Sergiu/Desktop/myfirstproject/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(unit "C:/Users/Sergiu/Desktop/myfirstproject/build/bin/unit_tests")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(unit "C:/Users/Sergiu/Desktop/myfirstproject/build/bin/unit_tests")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(unit "C:/Users/Sergiu/Desktop/myfirstproject/build/bin/unit_tests")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(unit "C:/Users/Sergiu/Desktop/myfirstproject/build/bin/unit_tests")
else()
  add_test(unit NOT_AVAILABLE)
endif()
