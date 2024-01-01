cmake_minimum_required(VERSION 3.10)
project(RType)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(client)

# Find source files
file(GLOB_RECURSE CLIENT_SOURCES "client/*.cpp")
file(GLOB_RECURSE SERVER_SOURCES "server/source/*.cpp")
file(GLOB_RECURSE SERVER_HEADERS "server/include/*.hpp")

# Add the client executable
add_executable(r-type_client ${CLIENT_SOURCES})

# Add the server executable
add_executable(r-type_server ${SERVER_SOURCES} ${SERVER_HEADERS})

# Link libraries if needed (you may need to adjust this based on your dependencies)
target_link_libraries(r-type_client PRIVATE boost_system boost_thread boost_chrono sfml-system sfml-window sfml-graphics sfml-audio)
target_link_libraries(r-type_server PRIVATE boost_system boost_thread boost_chrono)
target_link_libraries(r-type_server PRIVATE -pthread)

# Optionally, you can copy assets to the build directory during build
# You may need to adjust this based on your project structure
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
