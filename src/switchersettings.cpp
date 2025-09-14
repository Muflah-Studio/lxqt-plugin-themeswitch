// Plugin settings model
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "switchersettings.h"

SwitcherSettings::SwitcherSettings() : LXQt::Settings(QStringLiteral("lxqt")) {}

// SwitcherSettings::SwitcherSettings(const QString& mainKey) : LXQt::Settings(mainKey) {}

// SwitcherSettings::SwitcherSettings(const QSettings& parentSettings, const QString& subGroup) : LXQt::Settings(parentSettings, subGroup) {}

// SwitcherSettings::SwitcherSettings(const QString& confFileName, QSettings::Format format) : LXQt::Settings(confFileName, format) {}

SwitcherSettings::~SwitcherSettings() noexcept
{
}
