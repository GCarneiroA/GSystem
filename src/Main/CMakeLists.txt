



include_directories(
    ${CMAKE_BINARY_DIR}/src
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    #${Boost_INCLUDE_DIRS}
    #${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)


############### GSystemMain ###############
set(GSystem_SRCS
    #${CMAKE_CURRENT_BINARY_DIR}/gsystem.rc
    #icon.ico
    MainGui.cpp
)

set(GSystem_LIBS GSystemGui)


add_executable(GSystemMain ${GSystem_SRCS})
target_link_libraries(GSystemMain ${GSystem_LIBS})

install(TARGETS GSystemMain
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

