// Main plugin code
// SPDX-FileCopyrightText: 2025 <copyright holder> <email addr>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lxqtthemeswitcher.h"
#include "themeswitcherbutton.h"

#include <QDebug>

ThemeSwitcher::ThemeSwitcher(const ILXQtPanelPluginStartupInfo &startupInfo)
    : QObject(), ILXQtPanelPlugin(startupInfo)
{
    // Create a simple label to display some text
    blabel = new ThemeSwitcherButton(this);
    QString btext = QStringLiteral("Hello, Plugin!");
    blabel->setText(btext);

    settingsChanged();
}

ThemeSwitcher::~ThemeSwitcher() {
    delete blabel;
};


QWidget *ThemeSwitcher::widget()
{
   return blabel;
}
