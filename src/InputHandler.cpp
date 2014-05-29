#include "InputHandler.h"

#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
InputHandler* InputHandler::pInputHandler = nullptr;

InputHandler* InputHandler::getpInputHandler()
{
    if(pInputHandler == nullptr)
    {
        pInputHandler = new InputHandler();
        return pInputHandler;
    }

    return pInputHandler;
}

InputHandler::InputHandler()
{
    cout << " 9 C InputHandler" << endl;
}

InputHandler::~InputHandler()
{
    cout << " 9 D InputHandler" << endl;
}

void InputHandler::updateInputStates()
{
    SDL_Event event;//events are placed into this union of structs

    while(SDL_PollEvent(&event))//returns 1 if an event has been placed into the union
    {
        switch(event.type)//check the event type
        {
            case SDL_QUIT:
                Game::getpGame()->setbRunning() = false;
                break;

            //unhandled event
            default:
                break;
        }
    }
}

void InputHandler::clean()
{

}
