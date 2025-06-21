set(EXECUTABLE_NAME StorageNode)


set(PRIVATE_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/db
        ${CMAKE_CURRENT_SOURCE_DIR}/db/bitcask
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/server
        ${CMAKE_CURRENT_SOURCE_DIR}/server/proto
)

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/db/bitcask/bitcask.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/net.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/proto/message.pb.cc
)


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_include_directories(
        ${EXECUTABLE_NAME}
        PRIVATE
        ${PRIVATE_INCLUDE_DIR}
)

find_package(Protobuf REQUIRED)

target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        spdlog::spdlog
        tomlplusplus::tomlplusplus
        protobuf::libprotobuf
        absl::log_internal_check_op # dependency for protobuf
)

