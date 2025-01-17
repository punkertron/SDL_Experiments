#!/bin/bash

# Directories to format
DIRECTORIES=("common_inc" "simple_triangle" "key_mouse_control")

# File extensions to format
EXTENSIONS=("c" "h")

# Function to run clang-format on specified files
format_files() {
    local files_to_format=()
    
    for dir in "${DIRECTORIES[@]}"; do
        for ext in "${EXTENSIONS[@]}"; do
            files=($(find "$dir" -type f -name "*.$ext"))
            files_to_format+=("${files[@]}")
        done
    done

    if [ ${#files_to_format[@]} -eq 0 ]; then
        echo "No files found to format."
        return
    fi

    echo "Formatting ..."
    for file in "${files_to_format[@]}"; do
        echo "- $file"
        clang-format -i "$file"
    done
}

# Run the formatting function
format_files
echo "Formatting complete."


############################################################################

# Run CMake configuration and build commands
echo -e "\nConfiguring and building the project..."
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/
cmake --build ./build
