set(EXECUTABLE_NAME StorageNode)


set(PRIVATE_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/db
        ${CMAKE_CURRENT_SOURCE_DIR}/db/bitcask
)

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/db/bitcask/bitcask.cpp
)


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_include_directories(
        ${EXECUTABLE_NAME}
        PRIVATE
        ${PRIVATE_INCLUDE_DIR}
)

target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        spdlog::spdlog
        absl::status
        tomlplusplus::tomlplusplus
)

