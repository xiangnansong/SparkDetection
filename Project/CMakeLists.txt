cmake_minimum_required(VERSION 3.1)
project(Project)
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED Core Widgets Sql)
find_package(OpenCV)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Widgets/StackWidget.cpp Widgets/StackWidget.h Widgets/ButtonBar.cpp
        Widgets/ButtonBar.h Widgets/MainWidget.cpp Widgets/MainWidget.h src.qrc Widgets/ImageButton.cpp
        Widgets/ImageButton.h Widgets/HomeWidget.cpp Widgets/HomeWidget.h Widgets/SettingWidget.cpp
        Widgets/SettingWidget.h Widgets/StateItem.cpp Widgets/StateItem.h Widgets/ViewWidget.cpp Widgets/ViewWidget.h
        DataBase/SqlUtils.cpp DataBase/SqlUtils.h DataBase/TableBase.h DataBase/TableBase.cpp
        DataBase/Picture.h DataBase/Picture.cpp Widgets/DataWidget.cpp Widgets/DataWidget.h Thread/LoadThread.cpp Thread/LoadThread.h Thread/ProcessThread.cpp
        Thread/ProcessThread.h Widgets/ObjItem.cpp Widgets/ObjItem.h DataBase/Config.cpp
        DataBase/Config.h DataBase/Result.cpp DataBase/Result.h Thread/algorithm.cpp Thread/algorithm.h
        MpvPlayer/Player.cpp MpvPlayer/Player.h MpvPlayer/Widget.cpp MpvPlayer/Widget.h
        Graphics/CircleGroup.cpp Graphics/CircleGroup.h Graphics/ItemT.cpp Graphics/ItemT.h Graphics/Point.cpp Graphics/Point.h
        Graphics/TangleGroup.cpp Graphics/TangleGroup.h Graphics/Circle.h Graphics/Circle.cpp
        Graphics/NumCircle.cpp Graphics/NumCircle.h Widgets/PlayView.cpp Widgets/PlayView.h Widgets/CheckView.cpp Widgets/CheckView.h DataBase/Check.cpp DataBase/Check.h)
add_executable(Project ${SOURCE_FILES})
target_link_libraries(Project Qt5::Widgets Qt5::Sql)
target_link_libraries(Project ${OpenCV_LIBS})
target_link_libraries(Project -lmpv)