import QtQuick 2.0

Rectangle {

    id: cardTypeOneB
    objectName: "CardTypeOneB"

    property double scale: 1.0
    property string kanji: "下"
    property int num: 50

    function init( param ){
        kanji = param["kanji"];
        num = param["num"];
        scale = param["scale"];
    }

    //Template for initializing this card type
    function getTemplate(){
        return {kanji:"",
                num:0,
                scale:1.0};
    }

    width: 200*scale
    height: 300*scale
    radius: 12
    gradient: Gradient {
        GradientStop {
            position: 0.425
            color: "#ffffff"
        }

        GradientStop {
            position: 0.997
            color: "#afabab"
        }
    }
    border.width: 4

    Text {
        text: kanji
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Yu Mincho"
        font.pointSize: 130
    }
    Text{
        x: 12
        y: 76
        text: num
        font.pointSize: 12
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        verticalAlignment: Text.AlignVCenter
    }

}
