set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\debug\JHPlugin\JHStudentManager\

mkdir %PLUGIN_PATH%
copy %CURRENT_PATH%debug\JHStudentManagerd.dll %PLUGIN_PATH%JHStudentManagerd.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
