
if(WIN32)
    add_definitions(-DFCBase)
    add_definitions(-DPYCXX_DLL)
    add_definitions(-DBOOST_DYN_LINK)
    add_definitions(-DZIPIOS_UTF8)
endif()

include_directories(
    ${CMAKE_BINARY_DIR}/src
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    #${Boost_INCLUDE_DIRS}
    #${Qt5Core_INCLUDE_DIRS}
)
list(APPEND GSystemBase_LIBS ${Qt5Core_LIBRARIES})

set(GSystemBase_CPP_SRCS
    BaseClass.cpp
)

set(GSystemBase_HPP_SRCS
    BaseClass.h
)

set(GSystemBase_SRCS
    ${GSystemBase_CPP_SRCS}
    ${GSystemBase_HPP_SRCS}
)


add_library(GSystemBase SHARED ${GSystemBase_SRCS})
target_link_libraries(GSystemBase ${GSystemBase_LIBS})

#SET_BIN_DIR(GSystemBase GSystemBase)


install(TARGETS GSystemBase
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
