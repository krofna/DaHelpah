/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */
 
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <gtkmm/window.h>

class Application : public Gtk::Window
{
    public:
        Application();
        virtual ~Application();
        
        void Load();
    
    protected:
};

#endif
