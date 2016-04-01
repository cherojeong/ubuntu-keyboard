/*
 * Copyright 2013 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 2.4
import keys 1.0

KeyPad {
    anchors.fill: parent

    content: c1
    symbols: "languages/Keyboard_symbols.qml"

    Column {
        id: c1
        anchors.fill: parent
        spacing: 0

        Row {
            anchors.horizontalCenter: parent.horizontalCenter;
            spacing: 0

            CharKey { label: "ㅂ"; shifted: "ㅃ"; extended: ["1"]; extendedShifted: ["1"]; leftSide: true; }
            CharKey { label: "ㅈ"; shifted: "ㅉ"; extended: ["2"]; extendedShifted: ["2"] }
            CharKey { label: "ㄷ"; shifted: "ㄸ"; extended: ["3"]; extendedShifted: ["3"] }
            CharKey { label: "ㄱ"; shifted: "ㄲ"; extended: ["4"]; extendedShifted: ["4"] }
            CharKey { label: "ㅅ"; shifted: "ㅆ"; extended: ["5"]; extendedShifted: ["5"] }
            CharKey { label: "ㅛ"; shifted: "ㅛ"; extended: ["6"]; extendedShifted: ["6"] }
            CharKey { label: "ㅕ"; shifted: "ㅕ"; extended: ["7"]; extendedShifted: ["7"] }
            CharKey { label: "ㅑ"; shifted: "ㅑ"; extended: ["8"]; extendedShifted: ["8"] }
            CharKey { label: "ㅐ"; shifted: "ㅒ"; extended: ["9"]; extendedShifted: ["9"] }
            CharKey { label: "ㅔ"; shifted: "ㅖ"; extended: ["0"]; extendedShifted: ["0"]; rightSide: true; }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter;
            spacing: 0

            CharKey { label: "ㅁ"; shifted: "ㅁ"; }
            CharKey { label: "ㄴ"; shifted: "ㄴ"; }
            CharKey { label: "ㅇ"; shifted: "ㅇ"; }
            CharKey { label: "ㄹ"; shifted: "ㄹ"; }
            CharKey { label: "ㅎ"; shifted: "ㅎ"; }
            CharKey { label: "ㅗ"; shifted: "ㅗ"; }
            CharKey { label: "ㅓ"; shifted: "ㅓ"; }
            CharKey { label: "ㅏ"; shifted: "ㅏ"; }
            CharKey { label: "ㅣ"; shifted: "ㅣ"; rightSide: true; }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter;
            spacing: 0

            ShiftKey {}
            CharKey { label: "ㅋ"; shifted: "ㅋ"; }
            CharKey { label: "ㅌ"; shifted: "ㅌ"; }
            CharKey { label: "ㅊ"; shifted: "ㅊ"; }
            CharKey { label: "ㅍ"; shifted: "ㅍ"; }
            CharKey { label: "ㅠ"; shifted: "ㅠ"; }
            CharKey { label: "ㅜ"; shifted: "ㅜ"; }
            CharKey { label: "ㅡ"; shifted: "ㅡ"; }
            BackspaceKey {}
        }

        Item {
            anchors.left: parent.left
            anchors.right: parent.right

            height: panel.keyHeight + units.gu(UI.row_margin);

            SymbolShiftKey { id: symShiftKey;                            anchors.left: parent.left; height: parent.height; }
            LanguageKey    { id: languageMenuButton;                     anchors.left: symShiftKey.right; height: parent.height; }
            CharKey        { id: slashKey;    label: "/"; shifted: "/";  anchors.left: languageMenuButton.right; height: parent.height; }
            SpaceKey       { id: spaceKey;                               anchors.left: slashKey.right; anchors.right: urlKey.left; noMagnifier: true; height: parent.height; }
            UrlKey         { id: urlKey; label: ".com"; extended: [".co.uk", ".net", ".org", ".edu", ".gov", ".ac.uk"]; anchors.right: dotKey.left; height: parent.height; }
            CharKey        { id: dotKey;      label: "."; shifted: "."; extended: ["?", "-", "_", "!", "+", "%","#","/"]; extendedShifted: ["?", "-", "_", "!", "+", "%","#","/"]; anchors.right: enterKey.left; height: parent.height; }
            ReturnKey      { id: enterKey;                               anchors.right: parent.right; height: parent.height; }
        }
    } // column
}
