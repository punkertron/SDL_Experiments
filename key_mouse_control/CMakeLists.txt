# Define the target name
set(TARGET_NAME key_mouse_control_exe)

# Collect all source files
set(SOURCES
    key_mouse_control.c
)

# Define the executable
add_executable(${TARGET_NAME} ${SOURCES})

# Link SDL2 library to the executable
target_link_libraries(${TARGET_NAME} ${SDL2_LIBRARIES})

# Add SDL2 and common include directories specifically for this target
target_include_directories(${TARGET_NAME} PRIVATE ${SDL2_INCLUDE_DIRS} ${COMMON_INC_DIR})

# Specify output directory for the executable
set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
