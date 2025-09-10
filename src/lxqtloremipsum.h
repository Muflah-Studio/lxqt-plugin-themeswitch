// Main plugin header
// SPDX-FileCopyrightText: 2025 <copyright holder> <email addr>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef LXQTLOREMIPSUM_H
#define LXQTLOREMIPSUM_H

#include <lxqt/ilxqtpanelplugin.h>
#include "loremipsumbutton.h"
#include <QWidget>

class LoremIpsum : public QObject, public ILXQtPanelPlugin
{
    Q_OBJECT
public:
    LoremIpsum(const ILXQtPanelPluginStartupInfo &startupInfo);
    virtual QWidget *widget();
    virtual QString themeId() const { return QStringLiteral("loremipsum"); }
    virtual ILXQtPanelPlugin::Flags flags() const { return PreferRightAlignment ; }
    ~LoremIpsum();

private:
    LoremIpsumButton *blabel;
};

// Important part
class LoremIpsumPluginLibrary: public QObject, public ILXQtPanelPluginLibrary
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "lxqt.org/Panel/PluginInterface/3.0")
    Q_INTERFACES(ILXQtPanelPluginLibrary)

public:
    ILXQtPanelPlugin *instance(const ILXQtPanelPluginStartupInfo &startupInfo) const
    {
        return new LoremIpsum(startupInfo);
    }
};

#endif // LXQTLOREMIPSUM_H
