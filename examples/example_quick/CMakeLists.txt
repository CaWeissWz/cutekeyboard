qt_add_executable(example_quick WIN32 MACOSX_BUNDLE main.cpp)
target_compile_definitions(example_quick PRIVATE QT_DEPRECATED_WARNINGS)

target_link_libraries(example_quick PRIVATE Qt::Core Qt::Gui Qt::Quick)

set(qml_resource_files "main.qml")

qt_add_resources(example_quick "qml" PREFIX "/" FILES ${qml_resource_files})

install(
  TARGETS example_quick
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

qt_generate_deploy_app_script(TARGET example_quick FILENAME_VARIABLE deploy_script
                              NO_UNSUPPORTED_PLATFORM_ERROR)
install(SCRIPT ${deploy_script})
