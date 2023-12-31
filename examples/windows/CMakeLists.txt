#aux_source_directory(. SOURCE_FILES)
file(GLOB SOURCE_FILES "*.cpp" "*.cc")
file(GLOB HEADER_FILES "*.h" "*.hpp")

add_executable(amqpcpp_win_example ${SOURCE_FILES} ${HEADER_FILES})
add_dependencies(amqpcpp_win_example amqpcpp)
set(Boost_USE_STATIC_LIBS OFF)

target_compile_definitions(amqpcpp_win_example PRIVATE BOOST_ALL_DYN_LINK _WIN32_WINNT=0x0A00)

set(BOOST_ROOT "E:/source/libs/boost_1_84_0/boost_vc143") # 设置boost库搜索路径 
set(Boost_NO_SYSTEM_PATHS ON) #只搜索上语句设置的搜索路径
find_package(Boost 1.84.0 REQUIRED COMPONENTS system filesystem thread)

set(OPENSSL_ROOT_DIR "E:/source/libs/openssl-3.2.0-x64")
set(ENV{OPENSSL_ROOT_DIR} ${OPENSSL_ROOT_DIR})
find_package(OpenSSL REQUIRED)

target_include_directories(amqpcpp_win_example PRIVATE 
${Boost_INCLUDE_DIRS}
${OpenSSL_INCLUDE_DIRS}
)
target_link_directories(amqpcpp_win_example PRIVATE 
${Boost_LIBRARY_DIRS}
${OpenSSL_LIBRARY_DIRS}
)

target_link_libraries(amqpcpp_win_example PRIVATE amqpcpp ${Boost_LIBRARYS} OpenSSL::SSL)