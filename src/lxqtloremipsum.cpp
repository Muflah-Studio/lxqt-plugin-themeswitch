// Main plugin code
// SPDX-FileCopyrightText: 2025 <copyright holder> <email addr>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lxqtloremipsum.h"
#include "loremipsumbutton.h"

#include <QDebug>

LoremIpsum::LoremIpsum(const ILXQtPanelPluginStartupInfo &startupInfo)
    : QObject(), ILXQtPanelPlugin(startupInfo)
{
    // Create a simple label to display some text
    blabel = new LoremIpsumButton(this);
    QString btext = QStringLiteral("Hello, Plugin!");
    blabel->setText(btext);

    settingsChanged();
}

LoremIpsum::~LoremIpsum() {
    delete blabel;
};


QWidget *LoremIpsum::widget()
{
   return blabel;
}
