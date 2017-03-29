
#include "Core.hpp"
#include <unistd.h>
#include <termios.h>

arcade::GFX::GFX(void) {
    _input[10] = InputT(InputT::KeyPressed, Input::ENTER, InputT::None);
    _input[27] = InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None);
    _input[122] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
    _input[115] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
    _input[65] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
    _input[66] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
}

arcade::GFX::~GFX(void) {}

void arcade::GFX::setTitleWindow(std::string const &title) {
    (void)title;
}

void arcade::GFX::setWindowSize(Vector2u const &size) {
    (void)size;
}

bool arcade::GFX::isOpen(void) const {
    return true;
}

void arcade::GFX::close(void) {}

void arcade::GFX::clear(void) {}

void arcade::GFX::display(void) {}

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

arcade::InputT arcade::GFX::getInput(void)
{
    int input = getch();
    if (_input.find(input) != _input.end())
    {
        InputT in = _input[input];
        in.type = InputT::TextEntered;
        in.unicode = input;
        return (_input[input]);
    }

    return (InputT(InputT::TextEntered, input, input));
}
