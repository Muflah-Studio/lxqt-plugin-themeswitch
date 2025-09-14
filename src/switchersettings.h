// Plugin settings model
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef SWITCHERSETTINGS_H
#define SWITCHERSETTINGS_H

#include <LXQt/Settings>
#include <pluginsettings.h>

#include <QString>
#include <lxqtsettings.h>

/**
 * @todo write docs
 */
class SwitcherSettings : public LXQt::Settings
{
public:
    // single setting
    // explicit SwitcherSettings(const QString& parentKey = QStringLiteral("lxqt"));
    // nested settings
    // explicit SwitcherSettings(const QSettings& parentSettings, const QString& subGroup);
    // new settings
    // SwitcherSettings(const QString &confFileName, QSettings::Format format);
    // plugin settings
    SwitcherSettings();
    ~SwitcherSettings();
    // void setGroup();
};

#endif // SWITCHERSETTINGS_H
