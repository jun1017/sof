PROJECT (SOF_EXAMPLES_BUNDLE1)

SET (SOURCES 
	src/BundleActivator1.cpp
    src/dll.cpp
	)
    

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/impl/src ${CMAKE_SOURCE_DIR}/examples/common/src )
LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/impl )

ADD_LIBRARY( sof_examples_bundle1 SHARED ${SOURCES} )

if ( UNIX )
    SET_TARGET_PROPERTIES(sof_examples_bundle1 PROPERTIES 
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples
    )   
endif ( UNIX )

if ( WIN32 )
    SET_TARGET_PROPERTIES(sof_examples_bundle1 PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples
    )   
endif ( WIN32 )


TARGET_LINK_LIBRARIES( sof_examples_bundle1 sof )