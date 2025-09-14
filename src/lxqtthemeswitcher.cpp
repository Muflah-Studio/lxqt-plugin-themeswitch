// Main plugin code
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lxqtthemeswitcher.h"

#include <QDebug>
#include <QTimer>
#include <QEventLoop>

ThemeSwitcher::ThemeSwitcher(const ILXQtPanelPluginStartupInfo &startupInfo, SwitcherSettings *swSettings) :
    QObject(), ILXQtPanelPlugin(startupInfo), lxSettings(swSettings)
{
    // Create a simple label to display some text
    blabel = new ThemeSwitcherButton(this);
    QString btext = QStringLiteral("Switch Theme");
    blabel->setText(btext);

    initializeSettings();
    //lxSettings = new SwitcherSettings();

    connect(blabel, &ThemeSwitcherButton::clicked, this, &ThemeSwitcher::handleClick);

    settingsChanged();
}

ThemeSwitcher::~ThemeSwitcher() {
    delete blabel;
    delete lxSettings;
};

void ThemeSwitcher::handleClick()
{
    // blabel->setText(QStringLiteral("Switching..."));
    blabel->setPanelAppearance();
    // QString currentTheme = getCurrentLXQtTheme();

    // QTimer::singleShot(1000, [this, currentTheme]() {
    //     //qDebug() << "Code executed after 1 seconds!";
    //     this->blabel->setText(currentTheme);
    // });
    if (quint8 theme = toggleTheme()) {
        // blabel->setText(QStringLiteral("Switch Theme"));
        blabel->setPanelAppearance(theme);
    }

    // qDebug() <<  "testing.... core dump.....";
    // QString newText = QStringLiteral("Clicked....!!!");
}

void ThemeSwitcher::initializeSettings()
{
    if (nullptr == dynamic_cast<SwitcherSettings*>(lxSettings)) {
        lxSettings = new SwitcherSettings();
    }
}

void ThemeSwitcher::saveThemeSettings(quint8 state)
{
    qDebug() << state << " theme state";
    QString themeName = getLightTheme();
    if (state == 1) {
        themeName = getDarkTheme();
    }
    LXQt::LXQtTheme theme(themeName);
    if(theme.isValid() && themeName != getCurrentLXQtTheme()) {
        lxSettings->setValue(QStringLiteral("theme"), themeName);
        qDebug() << "Theme settings saved";
    }
}

quint8 ThemeSwitcher::toggleTheme()
{
    QEventLoop loop;
    QTimer timer;
    // quint8 themeState = 2;
    timer.setSingleShot(true);
    timer.setInterval(1000);

    // Connect a signal to quit the event loop
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

    qDebug() << "Switching theme...";
    // if (checkThemeSet()) {
    quint8 themeState = static_cast<quint8>(checkThemeSet()) + 1;
    // }
    timer.start();

    saveThemeSettings(themeState);

    loop.exec(); // Blocks until timer.timeout() is emitted and loop.quit() is called
    qDebug() << "Toggle finished";
    return themeState;
}

bool ThemeSwitcher::checkThemeSet()
{
    return getCurrentLXQtTheme() == getDarkTheme();
}

QString ThemeSwitcher::getCurrentLXQtTheme()
{
    return lxSettings->value(QStringLiteral("theme")).toString();
}

QString ThemeSwitcher::getDarkTheme()
{
    return QStringLiteral("Breeze Dark");
}

QString ThemeSwitcher::getLightTheme()
{
    return QStringLiteral("Breeze Light");
}
