#!/bin/bash

# Get the current directory
directory=$(../pwd)

# Function to recursively remove files with the specified extensions
remove_files() {
    local dir="$1"
    
    # Loop through each file/directory in the current directory
    for file in "$dir"/*; do
        if [[ -d "$file" ]]; then
            # If the current item is a directory, recursively call the function
            remove_files "$file"
        elif [[ -f "$file" ]]; then
            # If the current item is a file, check the extension and remove if it matches
            if [[ "$file" == *.so || "$file" == *.o ]]; then
                echo "Removing file: $file"
                rm "$file"
            fi
        fi
    done
}

# Call the function with the current directory
remove_files "$directory"
