// Button object implementation
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "themeswitcherbutton.h"
#include "lxqt/ilxqtpanelplugin.h"

ThemeSwitcherButton::ThemeSwitcherButton(ILXQtPanelPlugin *plugin, QWidget *parent) :
    QToolButton(parent),
    mPlugin(plugin)
{
    this->setToolTip(QStringLiteral("Click to toggle theme"));
    // qDebug() << "Added...";
    update();
}

void ThemeSwitcherButton::setPanelAppearance(quint8 choice)
{
    switch (choice) {
        case 1:
            this->setToolTip(QStringLiteral("Dark Theme"));
            this->setText(QStringLiteral("Switch Theme"));
            break;
        case 2:
            this->setToolTip(QStringLiteral("Light Theme"));
            this->setText(QStringLiteral("Switch Theme"));
            break;
        default:
            this->setToolTip(QStringLiteral(""));
            this->setText(QStringLiteral("Switching..."));
            break;
    }
    update();
}

// void ThemeSwitcherButton::setToolTip(const QString& tooltip)
// {
//     this->setToolTip(tooltip);
// }



ThemeSwitcherButton::~ThemeSwitcherButton() {};

