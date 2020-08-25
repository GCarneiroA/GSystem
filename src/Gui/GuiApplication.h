
#ifndef GUI_APPLICATION_H
#define GUI_APPLICATION_H

#include <GSConfig.h>

#include "GuiApplicationNativeEventAware.h"

namespace Gui
{

    class GuiExport GUIApplication : public GUIApplicationNativeEventAware
    {
        Q_OBJECT
    public:
        GUIApplication(int &argc, char *argv[]);
        virtual ~GUIApplication();
    };
} // namespace Gui

#endif
