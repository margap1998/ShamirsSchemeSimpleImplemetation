//
// Created by mg on 31.10.2020.
//

#ifndef UNTITLED1_MAINPROGRAM_H
#define UNTITLED1_MAINPROGRAM_H

#include <string>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Multiline_Output.H>
#include <Fl/Fl_Button.H>
#include <memory>
#include <Fl/Fl_Scroll.H>
#include "JoiningWindow.h"

class MainProgram: public ILog{
private:
    int width;
    int height;
    int margin;
    std::unique_ptr<Fl_Window> window;
    std::unique_ptr<Fl_Input> inSecret;
    std::unique_ptr<Fl_Multiline_Output> logOutput;
    std::unique_ptr<Fl_Multiline_Output> pointsOutput;
    std::unique_ptr<Fl_Button> button;
    std::unique_ptr<Fl_Button> joinButton;
    Fl_Input *neededShares;
    Fl_Input *allShares;
    Fl_Input *primeIn;
    Fl_Scroll *loScroll;
    Fl_Scroll *poScroll;
    std::string log;
    void draw(int argc, char **argv);
    static void cipherButtonCallback(Fl_Widget *w, void *p);
    static void joinButtonCallback(Fl_Widget *w, void *p);
public:
    void addToLog(const char *text) override;
    void run(int argc, char **argv);
    MainProgram();

    void addPoint(int x, int val);
};


#endif //UNTITLED1_MAINPROGRAM_H
