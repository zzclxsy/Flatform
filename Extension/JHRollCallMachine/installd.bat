set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\debug\JHPlugin\JHRollCallMachine\

mkdir %PLUGIN_PATH%
copy %CURRENT_PATH%debug\JHRollCallMachined.dll %PLUGIN_PATH%JHRollCallMachined.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
