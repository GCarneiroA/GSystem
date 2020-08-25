
#include "Application.h"

#include <csignal>
#include <iostream>
#include <sstream>

#include <QString>
#include <QFileInfo>

#include <Build/Version.h>

using namespace App;

Application *Application::m_singleton = nullptr;
AppExport std::map<std::string, std::string> Application::mConfig;

int Application::_argc;
char ** Application::_argv;

static void gSystemNewHandler()
{
    //throw Core::MemoryException();
}

void segmentation_fault_handler(int sig)
{
    (void)sig;
    std::cerr << "Program received signal SIGSEGV, Segmentation fault.\n";
    //printBacktrace(2);
    exit(1);
}

void Application::init(int argc, char ** argv)
{
    try
    {
        // install our own new handler
        std::set_new_handler(gSystemNewHandler); // ANSI new handler
        std::signal(SIGSEGV, segmentation_fault_handler);
        initTypes();
        initConfig(argc, argv);
        initApplication();
    }
    catch (...)
    {
        //destructObserver();
        throw;
    }
}

void Application::initTypes()
{
}

Application::Application(/*std::map<std::string, std::string> &mConfig*/)
{
}

Application::~Application()
{
}

void Application::initConfig(int argc, char **argv)
{
    //mConfig["AppHomePath"] = FindHomePath(argv[0]);
    if (App::Application::Config().find("BuildVersionMajor") == App::Application::Config().end()) {
        std::stringstream str;
        str << GSVersionMajor << "." << GSVersionMinor;
        App::Application::Config()["ExeVersion"         ] = str.str();
        App::Application::Config()["BuildVersionMajor"  ] = GSVersionMajor;
        App::Application::Config()["BuildVersionMinor"  ] = GSVersionMinor;
    }
    _argc = argc;
    _argv = argv;
}

void Application::initApplication()
{
    // Previous initialization code here

    Application::m_singleton = new Application();
}

void Application::runApplication()
{
    //processCmdLineFiles();
    if (mConfig["RunMode"] == "Cmd") {
        //Interpreter().runCommandLine("GSystem Console mode");
    }
    else if (mConfig["RunMode"] == "Internal") {
        //Console().Log("Running internal script:\n");
        //Interpreter().runString(Base::ScriptFactory().ProduceScript(mConfig["ScriptFileName"].c_str()));
    }
    else if (mConfig["RunMode"] == "Exit") {
        //Console().Log("Exiting on purpose\n");
    }
    else {
        //Console().Log("Unknown Run mode (%d) in main()?!?\n\n",mConfig["RunMode"].c_str());
    }
}

void Application::destruct()
{
}
