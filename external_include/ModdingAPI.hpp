#ifndef MODDING_API_H
#define MODDING_API_H

#include <functional>
#include <string>
#include <vector>

#include "TextureManager.hpp"
#include "goManager.hpp"

class modAPI
{
    public:
        TextureManager*                 grtTexm();
        void                            sroTexm(TextureManager* rtexm);
        goManager*                      grtGom();
        void                            sroGom(goManager* rtexm);
        sf::RenderWindow*               grtWindow();
        void                            sroWindow(sf::RenderWindow* window);

        void                            sorControl(std::function<void(modAPI*, sf::Event)> mcorapix);
        std::function<void(modAPI*, sf::Event)>    gorControl();

        void steWorldFileEntry(std::function<void(modAPI*, std::string)> func);
        std::vector<std::function<void(modAPI*, std::string)>> getWorldFileEntryEV();

        modAPI();
        ~modAPI();
    protected:
        
    private:
        
        TextureManager* ptexm;
        goManager*      pgom;
        sf::RenderWindow*      pwindow;

        std::function<void(modAPI*, sf::Event)> overrideControl;

        std::vector<std::function<void(modAPI*, std::string)>> WorldFileEntryEV;

};



#endif // MODDING_API_H