import QtQuick 2.7
import Qt.labs.folderlistmodel 2.1
import JHFramework 1.0
import QtQml 2.12

Item {
    id: loader

    property var pluginNameMap: Object()
    property var pluginMap: Object()

    signal pluginListChanged();

    FolderListModel {
        id: model
        folder: {
            if (Qt.platform.os == "windows"){
                return "file:///" + JHApp.applicationDirPath() + "/JHPlugin";
            }
            return "file://" + JHApp.utils.applicationDirPath() + "/JHPlugin"
        }

        onCountChanged: {
            updatePlugins();
        }
    }

    Timer{
        id: timer0
        repeat: false
        interval: 200
        onTriggered: {
            pluginListChanged();
        }
    }

    function updatePlugins(){
        var d = {};
        for (var i = 0; i < model.count; ++i){
            var isDir = model.get(i, "fileIsDir");
            var fileName = model.get(i, "fileName");

            if (!isDir){
                continue;
            }

            if (fileName === "." || fileName === ".."){
                continue;
            }
            d[fileName] = "JH.Function." + fileName;
        }
        pluginNameMap = d;

    }

    onPluginNameMapChanged: {
        for (var p1 in pluginNameMap){
            if (pluginMap.hasOwnProperty(p1)){
                continue;
            }
            loadPlugin(p1);
        }
        for (var p2 in pluginMap){
            if (pluginNameMap.hasOwnProperty(p2)){
                continue;
            }
            removePlugin(p2);
        }
        timer0.start();
    }

    function loadPlugin(pluginName){
        try{

            var importStatement1 = "import " + pluginName + " 1.0; ";
            var objectStatement = pluginName + "{}";
            var plugin = Qt.createQmlObject(importStatement1  + objectStatement, loader);
            pluginMap[pluginName] = plugin;
        }catch(e){
            console.log(pluginName+" 加载失败")
        }
    }

    function removePlugin(pluginName){
        var plugin = pluginMap[pluginName];
        delete pluginMap[pluginName];
        plugin.destroy();
    }
}
