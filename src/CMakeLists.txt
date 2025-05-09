include_directories(fastp)
include_directories(zlib)
include_directories(../lib/libdeflate)
include_directories(../lib/libisal)

add_subdirectory(fastp)
add_subdirectory(zlib)

add_executable(fastp
        ${zlib_source_files}
        ${fastp_source_files}
)
target_link_libraries(fastp 
    PRIVATE isal
    PRIVATE libdeflate_static
)
set_target_properties(fastp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# target_include_directories(fastp
#   PRIVATE
#     $<TARGET_PROPERTY:isal,INTERFACE_INCLUDE_DIRECTORIES>
#     $<TARGET_PROPERTY:deflate,INTERFACE_INCLUDE_DIRECTORIES>
# )
# target_link_libraries(metabuli prodigal)
# add_dependencies(metabuli local-generated)

# install(TARGETS metabuli DESTINATION bin)
