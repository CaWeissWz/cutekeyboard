import QtQml 2.3
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.CuteKeyboard 1.0
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12


Item {
    id: root

    Rectangle {
        width: parent.width
        height: parent.height
        color: "transparent"

        InputPanel {
            id: inputPanel

            z: 0
            y: parent.height * 1 / 5

            width: parent.width
            height: parent.height * 4 / 5
        }
    }
}


