set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\release\JHQmlControls\



mkdir %PLUGIN_PATH%

copy %CURRENT_PATH%release\JHQmlControls.dll %PLUGIN_PATH%JHQmlControls.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
copy %CURRENT_PATH%plugin.qmltypes %PLUGIN_PATH%plugin.qmltypes

rem copy dependencies
