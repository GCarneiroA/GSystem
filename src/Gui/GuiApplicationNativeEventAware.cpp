
#include "GuiApplicationNativeEventAware.h"

using namespace Gui;

GUIApplicationNativeEventAware::GUIApplicationNativeEventAware(int &argc, char *argv[])
    : QApplication(argc, argv)
{
}

GUIApplicationNativeEventAware::~GUIApplicationNativeEventAware()
{
}
