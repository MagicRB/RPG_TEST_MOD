#include "goManager.hpp"

#include <SFML/Window.hpp>

class test : public gameObject
{
    public:
        test();
        ~test();    

        virtual void render(sf::RenderWindow* window);
    protected:
        
    private:
        
};