#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H

#include <dlfcn.h>
#include <map>
#include <string>

class modManager
{
    public:

        std::map<std::string, void*> mods;

        void loadMod(std::string mod_name, std::string path);

        void closeAllMods();

    protected:

        void (*init_mod)(void(*)());

    private:
};
#endif // MOD_MANAGER_H