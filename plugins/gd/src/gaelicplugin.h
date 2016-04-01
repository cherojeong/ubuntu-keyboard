﻿#ifndef GAELICPLUGIN_H
#define GAELICPLUGIN_H

#include <QObject>
#include "languageplugininterface.h"
#include "westernlanguagesplugin.h"

//#include <presage.h>

class GaelicPlugin : public WesternLanguagesPlugin
{
    Q_OBJECT
    Q_INTERFACES(LanguagePluginInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.GaelicPlugin" FILE "gaelicplugin.json")

public:
    explicit GaelicPlugin(QObject* parent = 0)
        : WesternLanguagesPlugin(parent)
    {
    }

    virtual ~GaelicPlugin()
    {
    }
};

#endif // GAELICPLUGIN_H
