#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
    public:
        ~InputHandler();

        void updateInputStates();//poll for events and update InputHandler
        void clean();//clean initialised devices

        static InputHandler* getpInputHandler();//create a single instance

    private:
        static InputHandler* pInputHandler;//pointer to the instance

        InputHandler();
        InputHandler(const InputHandler& rhs);
        InputHandler& operator=(const InputHandler& rhs);

};

#endif // INPUTHANDLER_H
