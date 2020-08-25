

#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <GSConfig.h>
#include <QMainWindow>

#include "ui_MainWindow.h"

namespace Ui
{
    class MainWindow;
}

namespace Gui
{

    class GuiExport MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
    };

} // namespace Gui

#endif
