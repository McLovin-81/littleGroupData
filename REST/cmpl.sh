#!/bin/bash

# The name of the C++ file
FILE_NAME="cUrl-API.cpp"

# The name of the executable
EXECUTABLE_NAME="cUrl-API"

# The path to the curl library
#CURL_LIBRARY_PATH="/usr/lib"

# The command to compile the program
COMMAND="g++ ${FILE_NAME} -o ${EXECUTABLE_NAME} -lcurl"

# Run the command
echo "Compiling ${FILE_NAME}.."
${COMMAND}
echo "Done!"

# Run the executable
./${EXECUTABLE_NAME}

# Delete the executable
rm ${EXECUTABLE_NAME}

# chmod +x <fileName>
# Change the the permissions on the script!