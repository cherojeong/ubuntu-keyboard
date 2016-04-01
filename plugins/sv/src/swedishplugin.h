﻿#ifndef SWEDISHPLUGIN_H
#define SWEDISHPLUGIN_H

#include <QObject>
#include "languageplugininterface.h"
#include "westernlanguagesplugin.h"

class SwedishPlugin : public WesternLanguagesPlugin
{
    Q_OBJECT
    Q_INTERFACES(LanguagePluginInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.SwedishPlugin" FILE "swedishplugin.json")

public:
    explicit SwedishPlugin(QObject* parent = 0)
        : WesternLanguagesPlugin(parent)
    {
    }

    virtual ~SwedishPlugin()
    {
    }
};

#endif // SWEDISHPLUGIN_H
