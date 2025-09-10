// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2025 <copyright holder> <email>
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
    ~ThemeSwitcherButton();

private:
    ILXQtPanelPlugin *mPlugin;
};

#endif // THEMESWITCHERBUTTON_H
