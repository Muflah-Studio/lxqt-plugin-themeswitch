// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2025 <copyright holder> <email>
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef LOREMIPSUMBUTTON_H
#define LOREMIPSUMBUTTON_H

#include <QToolButton>

class ILXQtPanelPlugin;

class LoremIpsumButton : public QToolButton
{
    Q_OBJECT

public:
    LoremIpsumButton(ILXQtPanelPlugin *plugin, QWidget* parent = nullptr);
    ~LoremIpsumButton();

private:
    ILXQtPanelPlugin *mPlugin;
};

#endif // LOREMIPSUMBUTTON_H
