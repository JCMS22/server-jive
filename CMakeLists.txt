cmake_minimum_required(VERSION 3.8)
project(udp_server_jive)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp DataBaseConnector/IDataBaseConnector.h DataBaseConnector/IJsonLookupDataBase.h DataBaseConnector/JsonLocalDataBase.cpp DataBaseConnector/JsonLocalDataBase.h Server/IServer.h Server/TcpServer.cpp Server/TcpServer.h Server/ServerTypes.h)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
qt5_generate_moc(main.cpp main.moc)
add_executable(udp_server_jive ${SOURCE_FILES} main.moc)
target_link_libraries(udp_server_jive Qt5::Core Qt5::Network)