// Representation container on panel
// SPDX-FileCopyrightText: 2025 Aryo Sr. <98627850+aryo-sr@users.noreply.github.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef THEMESWITCHERBUTTON_H
#define THEMESWITCHERBUTTON_H

#include <QToolButton>

class ILXQtPanelPlugin;

class ThemeSwitcherButton : public QToolButton
{
    Q_OBJECT

public:
    ThemeSwitcherButton(ILXQtPanelPlugin *plugin, QWidget* parent = nullptr);
    ~ThemeSwitcherButton() override;

// public slots:
    void setPanelAppearance(quint8 choice = 0); // 0 waiting, 1 dark, 2 light
    // void setToolTip(const QString& tooltip);

private:
    ILXQtPanelPlugin *mPlugin;
};

#endif // THEMESWITCHERBUTTON_H
