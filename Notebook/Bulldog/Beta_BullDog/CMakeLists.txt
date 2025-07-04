cmake_minimum_required(VERSION 3.16)
project(Beta_BullDog LANGUAGES CXX)

# Ativa o processamento automático de arquivos UI, MOC, e RCC do Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Configura o padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra as versões apropriadas do Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Sql)

# Define os arquivos de origem e cabeçalhos
add_executable(Beta_BullDog
    main.cpp
    mainwindow.h
    mainwindow.cpp
    oilibrarywidget.h
    oilibrarywidget.cpp
    addoilwidget.h
    addoilwidget.cpp
    compareoilswidget.h
    compareoilswidget.cpp
    databaseconnection.cpp
    addOilToDatabase.cpp
    databaseconnection.h
    addOilToDatabase.h
    oilibrarywidget.h

)

# Linka as bibliotecas do Qt necessárias
target_link_libraries(Beta_BullDog
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Define os diretórios de instalação
include(GNUInstallDirs)
install(TARGETS Beta_BullDog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
