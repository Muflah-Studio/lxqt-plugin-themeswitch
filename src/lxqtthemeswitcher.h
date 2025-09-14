// Main plugin header
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef LXQTTHEMESWITCHER_H
#define LXQTTHEMESWITCHER_H

#include <QWidget>
#include <lxqt/ilxqtpanelplugin.h>

#include "themeswitcherbutton.h"
#include "switchersettings.h"

class ThemeSwitcher : public QObject, public ILXQtPanelPlugin
{
    Q_OBJECT

public:
    ThemeSwitcher(const ILXQtPanelPluginStartupInfo& startupInfo, SwitcherSettings *swSettings = nullptr);

    virtual QString themeId() const { return QStringLiteral("themeswitcher"); }
    virtual ILXQtPanelPlugin::Flags flags() const { return PreferRightAlignment ; }
    QWidget *widget() { return blabel; }
    ~ThemeSwitcher();

private:
    ThemeSwitcherButton *blabel;
    SwitcherSettings *lxSettings;
    QString getCurrentLXQtTheme();
    QString getDarkTheme();
    QString getLightTheme();
    bool checkThemeSet();
    void initializeSettings();
    void saveThemeSettings(quint8 state);
    quint8 toggleTheme();

private slots:
    void handleClick();
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
