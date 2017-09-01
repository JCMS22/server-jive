cmake_minimum_required(VERSION 3.8)
project(server_jive)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/DataBaseConnector/IDataBaseConnector.h src/DataBaseConnector/IJsonLookupDataBase.h src/DataBaseConnector/JsonLocalDataBase.cpp src/DataBaseConnector/JsonLocalDataBase.h src/Server/IServer.h src/Server/TcpServer.cpp src/Server/TcpServer.h src/Server/ServerTypes.h src/CommandProcessor/ICmdStack.h src/CommandProcessor/SipLookupCmdProcessor.cpp src/CommandProcessor/SipLookupCmdProcessor.h src/DataBaseConnector/ISipLookup.h src/CommandProcessor/ICmdResponseCallback.h src/Server/ServerCmdCallback.cpp src/Server/ServerCmdCallback.h)

# Add QT dependencies
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
qt5_generate_moc(src/main.cpp main.moc)
add_executable(server_jive ${SOURCE_FILES} main.moc)
target_link_libraries(server_jive Qt5::Core Qt5::Network)