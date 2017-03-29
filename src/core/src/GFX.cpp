
#include "Core.hpp"

arcade::GFX::GFX(void) {}

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

arcade::InputT arcade::GFX::getInput(void)
{
    int input = getchar();
    if (_input.find(input) != _input.end())
    {
        InputT in = _input[input];
        in.type = InputT::TextEntered;
        in.unicode = input;
        return (_input[input]);
    }
    return (InputT(InputT::TextEntered, input, input));
}
