set(GTEST_SHUFFLE 1)

FIND_PACKAGE( OpenCV REQUIRED )
add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/imageProcessor.cpp
    ../app/lanes.cpp
    ../include/imageProcessor.hpp
    ../include/lanes.hpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
target_link_libraries(cpp-test PUBLIC gtest)
