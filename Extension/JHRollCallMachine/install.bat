set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\release\JHPlugin\JHRollCallMachine\

mkdir %PLUGIN_PATH%
copy %CURRENT_PATH%release\JHRollCallMachine.dll %PLUGIN_PATH%JHRollCallMachine.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
