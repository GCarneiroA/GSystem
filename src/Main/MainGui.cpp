
#include <QLocale>
#include <QMessageBox>
#include <QApplication>

// GSystem
#include <App/Application.h>
#include <Gui/Application.h>

int main(int argc, char **argv)
{
    (void)QLocale::system();


    // Name and Version of the Application
    App::Application::Config()["ExeName"] = "GSystem";
    App::Application::Config()["ExeVendor"] = "GSystemCompany";
    App::Application::Config()["AppDataSkipVendor"] = "true";
    App::Application::Config()["MaintainerUrl"] = "https://github.com/GCarneiroA/GSystem.git";

    // set the banner (for logging and console)
    //App::Application::Config()["CopyrightInfo"] = sBanner;
    App::Application::Config()["AppIcon"] = "gsystem";
    App::Application::Config()["SplashScreen"] = "gsystemsplash";
    App::Application::Config()["StartWorkbench"] = "StartWorkbench";
    //App::Application::Config()["HiddenDockWindow"] = "Property editor";
    App::Application::Config()["SplashAlignment" ] = "Bottom|Left";
    App::Application::Config()["SplashTextColor" ] = "#ffffff"; // white
    App::Application::Config()["SplashInfoColor" ] = "#c8c8c8"; // light grey

    try
    {
        App::Application::Config()["RunMode"] = "Gui";
        App::Application::Config()["Console"] = "0";
        App::Application::Config()["LoggingConsole"] = "1";

        App::Application::init(argc, argv);

        std::map<std::string, std::string>::iterator it = App::Application::Config().find("NavigationStyle");
        if (it != App::Application::Config().end()) {

        }

        Gui::Application::initApplication();
        
        if (App::Application::Config()["RunMode"] == "Gui") {
            //Base::Interpreter().replaceStdOutput();
        }
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        if (App::Application::Config()["Console"] == "1") {
            App::Application::runApplication();
        }
        if (App::Application::Config()["RunMode"] == "Gui" ||
            App::Application::Config()["RunMode"] == "Internal") {
            Gui::Application::runApplication();
        }
        else {
            App::Application::runApplication();
        }
    }
    catch(const std::exception& e)
    {
    }
    
    App::Application::destruct();

    return 0;
}
