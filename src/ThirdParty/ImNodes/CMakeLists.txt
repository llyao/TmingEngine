project (ImNodes)
file (GLOB heads *.h)
file( GLOB sources *.cpp)
include_directories("include")
include_directories("../../../include")
#add_executable_beautiful(scheme ${heads} ${sources})
add_library_beautiful(ImNodes STATIC ${heads} ${sources})

install_header_files (DIRECTORY ./ DESTINATION ${DEST_INCLUDE_DIR}/ImNodes FILES_MATCHING PATTERN *.hpp *.h USE_FILE_SYMLINK BUILD_TREE_ONLY) 
