// Main plugin header
// SPDX-FileCopyrightText: 2025 <copyright holder> <email addr>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef LXQTTHEMESWITCHER_H
#define LXQTTHEMESWITCHER_H

#include <lxqt/ilxqtpanelplugin.h>
#include "themeswitcherbutton.h"
#include <QWidget>

class ThemeSwitcher : public QObject, public ILXQtPanelPlugin
{
    Q_OBJECT
public:
    ThemeSwitcher(const ILXQtPanelPluginStartupInfo &startupInfo);
    virtual QWidget *widget();
    virtual QString themeId() const { return QStringLiteral("themeswitcher"); }
    virtual ILXQtPanelPlugin::Flags flags() const { return PreferRightAlignment ; }
    ~ThemeSwitcher();

private:
    ThemeSwitcherButton *blabel;
};

// Important part
class ThemeSwitcherPluginLibrary: public QObject, public ILXQtPanelPluginLibrary
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "lxqt.org/Panel/PluginInterface/3.0")
    Q_INTERFACES(ILXQtPanelPluginLibrary)

public:
    ILXQtPanelPlugin *instance(const ILXQtPanelPluginStartupInfo &startupInfo) const
    {
        return new ThemeSwitcher(startupInfo);
    }
};

#endif // LXQTTHEMESWITCHER_H
