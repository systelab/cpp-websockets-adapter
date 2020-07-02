cmake_minimum_required(VERSION 3.2)

project(WebSocketsAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find external dependencies
find_package(WebSocketsAdapterTestUtilities)

# Configure test package project
set(WEBSOCKETS_ADAPTER_PACKAGE_TEST_PROJECT WebSocketsAdapterPackageTest)
add_executable(${WEBSOCKETS_ADAPTER_PACKAGE_TEST_PROJECT} WebSocketsAdapterExample.cpp)
target_link_libraries(${WEBSOCKETS_ADAPTER_PACKAGE_TEST_PROJECT} WebSocketsAdapterTestUtilities::WebSocketsAdapterTestUtilities)

# Register tests
enable_testing()
add_test(NAME WebSocketsAdapterPackageTest COMMAND ${WEBSOCKETS_ADAPTER_PACKAGE_TEST_PROJECT})
