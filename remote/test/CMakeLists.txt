PROJECT (SOF_REMOTE_TEST)

SET (SOURCES 
	src/BundleActivator1.cpp
    src/BundleActivator2.cpp
    src/CustomizedCORBAHelper.cpp
    src/Multiplier.cpp
    src/MultiplierImpl.cpp
    src/IDividerImpl.cpp
    src/RemoteSOFLauncherTest.cpp
    src/sof_remote_test.cpp
    src/UnitTestLogger.cpp
	)
    
GET_PROPERTY( MICO_LIBRARY_PATH GLOBAL PROPERTY MICO_LIBS )
GET_PROPERTY( MICO_ORB_LIB GLOBAL PROPERTY MICO_ORB )
GET_PROPERTY( MICO_COSS_LIB GLOBAL PROPERTY MICO_COSS )
GET_PROPERTY( MICO_PTHREAD_LIB GLOBAL PROPERTY MICO_PTHREAD )
GET_PROPERTY( TEST_SCRIPT GLOBAL PROPERTY SOF_REMOTE_TEST_SCRIPT )
GET_PROPERTY( MICO_INCLUDE_DIR GLOBAL PROPERTY MICO_INCLUDE )

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/impl/src ${CMAKE_SOURCE_DIR}/remote/impl/src ${CMAKE_SOURCE_DIR}/extern/CppUnitLite/src ${MICO_INCLUDE_DIR} )
LINK_DIRECTORIES( ${CMAKE_BINARY_DIR}/remote/impl ${CMAKE_BINARY_DIR}/extern/CppUnitLite ${MICO_LIBRARY_PATH} )
ADD_EXECUTABLE( sof_remote_test ${SOURCES} )


TARGET_LINK_LIBRARIES( sof_remote_test sof_remote cppunitlite ${MICO_ORB_LIB} ${MICO_COSS_LIB} ${MICO_PTHREAD_LIB} )

INSTALL( FILES ${CMAKE_SOURCE_DIR}/remote/test/bin/${TEST_SCRIPT} DESTINATION ${CMAKE_BINARY_DIR}/remote/test )


