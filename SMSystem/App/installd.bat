set CURRENT_PATH=%~dp0
set TARGET_PATH=%CURRENT_PATH%


set PLUGIN_PATH=%~dp0..\..\Extension
call %PLUGIN_PATH%\JHStudentManager\installd.bat %TARGET_PATH%

set PLUGIN_PATH=%~dp0..\..\Extension
call %PLUGIN_PATH%\JHRollCallMachine\installd.bat %TARGET_PATH%

set NOVA_PATH=%~dp0..\..\Basic
call %NOVA_PATH%\JHQmlControl\installd.bat %TARGET_PATH%

