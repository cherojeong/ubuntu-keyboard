/*
 * This file is part of Maliit Plugins
 *
 * Copyright (C) 2014 Canonical Ltda
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * Neither the name of Nokia Corporation nor the names of its contributors may be
 * used to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef UBUNTU_KEYBOARD_EXTENSION_H
#define UBUNTU_KEYBOARD_EXTENSION_H

#include <QtCore>
#include <QtQuick>

namespace Ubuntu {
namespace Keyboard {

class InputMethodExtension : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap extensions READ inputMethodExtensions WRITE setInputMethodExtensions NOTIFY inputMethodExtensionsChanged)
public:
    InputMethodExtension(QObject *parent = 0);

    QVariantMap inputMethodExtensions() const;
    void setInputMethodExtensions(const QVariantMap &map);

Q_SIGNALS:
    void inputMethodExtensionsChanged();

private:
    QVariantMap m_extensions;
    QObject *m_inputText;

    QObject *findInput(QObject *parent);
};

class InputMethod : public QObject
{
    Q_OBJECT

public:
    InputMethod(QObject *parent = 0);

    static InputMethodExtension *qmlAttachedProperties(QObject *obj);
};

} // namespace Ubuntu
} // namespace Keyboard

QML_DECLARE_TYPEINFO(Ubuntu::Keyboard::InputMethod, QML_HAS_ATTACHED_PROPERTIES)

#endif
