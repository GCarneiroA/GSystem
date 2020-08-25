
#ifndef APP_APPLICATION_H
#define APP_APPLICATION_H

#include <map>
#include <string>
#include <GSConfig.h>

namespace App
{
    /**
     * Root application system
     */
    class AppExport Application
    {
    public:
        static void init(int argc, char **argv);
        static void initTypes();
        friend Application &GetApplication(void);
        static std::map<std::string, std::string> &Config(void) { return mConfig; }
        static void runApplication();
        static void destruct();
        static int GetARGC(void) { return _argc; }
        static char **GetARGV(void) { return _argv; }

    private:
        Application(/*std::map<std::string, std::string> &mConfig*/);
        virtual ~Application();

        static void initConfig(int argc, char **argv);
        static void initApplication();

        static Application *m_singleton;
        static std::map<std::string, std::string> mConfig;

        static int _argc;
        static char **_argv;
    };

    inline App::Application &GetApplication(void)
    {
        return *App::Application::m_singleton;
    }

} // namespace App

#endif
