
if(WIN32)
    add_definitions(-DFCApp)
    add_definitions(-DBOOST_DYN_LINK)
endif()

include_directories(
    ${CMAKE_BINARY_DIR}/src
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    #${Boost_INCLUDE_DIRS}
    #${Qt5Core_INCLUDE_DIRS}
)

set(GSystemApp_LIBS
    GSystemBase
    #${Boost_LIBRARIES}
    #${Qt5Core_LIBRARIES}
    #${Qt5Xml_LIBRARIES}
)

set(GSystemApp_CPP_SRCS
    Application.cpp
)

set(GSystemApp_HPP_SRCS
    Application.h
)

set(GSystemApp_SRCS
    ${GSystemApp_CPP_SRCS}
    ${GSystemApp_HPP_SRCS}
)

add_library(GSystemApp SHARED ${GSystemApp_SRCS})
target_link_libraries(GSystemApp ${GSystemApp_LIBS})

#SET_BIN_DIR(GSystemApp GSystemApp)

install(TARGETS GSystemApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
