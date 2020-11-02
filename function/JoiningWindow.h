//
// Created by mg on 31.10.2020.
//

#ifndef UNTITLED1_JOININGWINDOW_H
#define UNTITLED1_JOININGWINDOW_H

#include <string>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Multiline_Output.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl.H>
#include <vector>
#include <Fl/Fl_Scroll.H>
#include "ILog.h"

class JoiningWindow:public Fl_Window, public ILog {
private:
    int width;
    int height;
    int margin{};
    Fl_Input *inSecret{nullptr};
    Fl_Input *inVal{nullptr};
    Fl_Multiline_Output *logOutput{nullptr};
    Fl_Output *secretOutput{nullptr};
    Fl_Button *button{nullptr};
    Fl_Button *joinButton{nullptr};
    std::vector<std::pair<int,long>> shares;
    std::string log;
    void myDraw();
    Fl_Scroll *loScroll{};
    Fl_Input *neededShares{};
    Fl_Input *primeIn{};
    static void buttonCallback(Fl_Widget *w, void *p);
    static void joinButtonCallback(Fl_Widget *w, void *p);
public:
    void run();
    JoiningWindow(int w, int h, const char *title);
    JoiningWindow();

    void addPoint(int x, long value);

    void addToLog(const char *text) override;

};


#endif //UNTITLED1_JOININGWINDOW_H
