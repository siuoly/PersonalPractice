project( TEST ) 

ADD_SUBDIRECTORY( lib ) 

ADD_EXECUTABLE( app main.cc )

target_link_libraries(app PUBLIC mylib)

target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/lib")
