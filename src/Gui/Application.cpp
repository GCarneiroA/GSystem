
#include "Application.h"
#include <App/Application.h>

#include <Gui/MainWindow.h>
#include <Gui/GuiSingleApplication.h>

#include <map>
#include <string>

#include <QCoreApplication>

using namespace Gui;

Application::Application(bool GUIenabled)
{
}

Application::~Application()
{
}

void Application::initApplication()
{
}

void Application::runApplication()
{
    const std::map<std::string, std::string>& cfg = App::Application::Config();
    std::map<std::string, std::string>::const_iterator it;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
#endif
#if QT_VERSION >= 0x050600
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    int argc = App::Application::GetARGC();
    GUISingleApplication mainApp(argc, App::Application::GetARGV());
    mainApp.setAttribute(Qt::AA_DontShowIconsInMenus, false);

    Application app(true);
    MainWindow mw;
    mw.setProperty("QuitOnClosed", true);

    mainApp.setActiveWindow(&mw);

    mw.show();

    mainApp.exec();
}
