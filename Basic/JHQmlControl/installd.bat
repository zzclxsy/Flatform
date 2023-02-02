set CURRENT_PATH=%~dp0
set TARGET_PATH=%1
set PLUGIN_PATH=%TARGET_PATH%\debug\JHQmlControls\


mkdir %PLUGIN_PATH%
copy %CURRENT_PATH%debug\JHQmlControlsd.dll %PLUGIN_PATH%JHQmlControlsd.dll
copy %CURRENT_PATH%qmldir %PLUGIN_PATH%qmldir
copy %CURRENT_PATH%plugin.qmltypes %PLUGIN_PATH%plugin.qmltypes
rem copy dependencies
