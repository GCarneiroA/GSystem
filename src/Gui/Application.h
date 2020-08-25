
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GSConfig.h>

namespace Gui
{

    class GuiExport Application
    {
    public:
        Application(bool GUIenabled);
        ~Application();
        static void initApplication();
        static void runApplication();
    private:

    };

}

#endif  // GUI_APPLICATION_H
