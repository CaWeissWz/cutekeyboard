find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick QuickWidgets Widgets)

qt_add_executable(example_widgets WIN32 MACOSX_BUNDLE main.cpp mainwindow.cpp)
target_compile_definitions(example_widgets PRIVATE QT_DEPRECATED_WARNINGS)
target_link_libraries(example_widgets PRIVATE Qt::Core Qt::Gui Qt::Quick Qt::QuickWidgets Qt::Widgets)

set(qml_resource_files "example_widgets.qml")
qt_add_resources(example_widgets "qml" PREFIX "/" FILES ${qml_resource_files})

install(
  TARGETS example_widgets
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

qt_generate_deploy_app_script(TARGET example_widgets FILENAME_VARIABLE deploy_script
                              NO_UNSUPPORTED_PLATFORM_ERROR)
install(SCRIPT ${deploy_script})
