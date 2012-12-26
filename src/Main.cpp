/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

/*
 * http://www.trinitycore.org/f/topic/180-bin-truice-win32/
 * http://www.trinitycore.org/f/topic/7639-bin-truice-win32/
 * http://trac.edgewall.org/demo-0.12/query
 * */

#include <iostream>

#include "Application.hpp"

int main(int argc, char* argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "DaHelpah");

    Application Window;
    int retval = 1;
    
    try
    {
        retval = app->run(Window);
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Runtime error lolz: " << e.what() << std::endl;
    }
    
    return retval;
}
