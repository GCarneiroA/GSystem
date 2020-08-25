
#ifndef GUI_SINGLEAPPLICATION_H
#define GUI_SINGLEAPPLICATION_H

#include <GSConfig.h>

#include "GuiApplication.h"

namespace Gui
{
    class GuiExport GUISingleApplication : public GUIApplication
    {
        Q_OBJECT
    public:
        explicit GUISingleApplication(int &argc, char *argv[]);
        virtual ~GUISingleApplication();
    };
} // namespace Gui

#endif
