set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\release\JHPlugin\JHStudentManager\

mkdir %PLUGIN_PATH%
copy %CURRENT_PATH%release\JHStudentManager.dll %PLUGIN_PATH%JHStudentManager.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
