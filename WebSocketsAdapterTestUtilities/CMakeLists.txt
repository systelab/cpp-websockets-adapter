cmake_minimum_required(VERSION 3.2)

# Find external dependencies
find_package(TestUtilitiesInterface)
find_package(WebSocketsAdapterInterface)

set(GTEST_PACKAGE_NAME gtest)
find_package(${GTEST_PACKAGE_NAME})
if (NOT TARGET ${GTEST_PACKAGE_NAME}::${GTEST_PACKAGE_NAME})
    set(GTEST_PACKAGE_NAME GTest)
    find_package(${GTEST_PACKAGE_NAME})
endif()


# Add project folder into includes
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure DB Adapter test utilities project
set(WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT WebSocketsAdapterTestUtilities)
file(GLOB_RECURSE WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_SRC "*.cpp")
file(GLOB_RECURSE WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_HDR "*.h")
add_library(${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT} STATIC ${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
target_link_libraries(${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT} ${GTEST_PACKAGE_NAME}::${GTEST_PACKAGE_NAME} TestUtilitiesInterface::TestUtilitiesInterface WebSocketsAdapterInterface::WebSocketsAdapterInterface)

# Configure source groups
foreach(FILE ${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${WEB_SOCKETS_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()
