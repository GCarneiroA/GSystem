
#ifndef GUIAPPLICATIONNATIVEEVENTAWARE_H
#define GUIAPPLICATIONNATIVEEVENTAWARE_H

#include <QApplication>

#include <GSConfig.h>

class QMainWindow;

namespace Gui
{
    class GuiExport GUIApplicationNativeEventAware : public QApplication
    {
        Q_OBJECT
    public:
        GUIApplicationNativeEventAware(int &argc, char *argv[]);
        ~GUIApplicationNativeEventAware();
    };
} // namespace Gui

#endif
