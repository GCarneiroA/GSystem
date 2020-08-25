

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_BINARY_DIR}/..
    #${CMAKE_CURRENT_BINARY_DIR}/Language
    #${CMAKE_CURRENT_BINARY_DIR}/propertyeditor
    #${Boost_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

set(GSystemGui_LIBS
    GSystemApp
    Qt::Widgets
)

set(GSystemGui_CPP_SRCS
    Application.cpp
    GuiApplicationNativeEventAware.cpp
    GuiApplication.cpp
    GuiSingleApplication.cpp
)

set(GSystemGui_HPP_SRCS
    Application.h
    GuiApplicationNativeEventAware.h
    GuiApplication.h
    GuiSingleApplication.h
)

set(Widget_CPP_SRCS
    MainWindow.cpp
)

set(Widget_HPP_SRCS
    MainWindow.h
)

set(Widget_UI_SRCS
    MainWindow.ui
)

set(GSystemGui_SRCS
    ${GSystemGui_CPP_SRCS}
    ${Widget_CPP_SRCS}
    ${Widget_UI_SRCS}
)

add_library(GSystemGui SHARED ${GSystemGui_SRCS})
target_link_libraries(GSystemGui ${GSystemGui_LIBS})
