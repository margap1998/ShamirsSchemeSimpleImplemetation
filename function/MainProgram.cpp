//
// Created by mg on 31.10.2020.
//

#include <sstream>
#include "MainProgram.h"
#include "SchemeParter.h"

void MainProgram::run(int argc, char **argv) {
    this->draw(argc,argv);
    window->show(argc, argv);
}

void MainProgram::draw(int argc, char **argv) {
    window = std::make_unique<Fl_Window>(width + 2*margin, height + 2*margin);
    window->label("Shamir's Scheme");
    int x = margin;
    int h = margin*2;
    int w = width/5;
    int y = margin;
    primeIn = new Fl_Input(x+50,y,w,h,"Prime");
    allShares = new Fl_Input(x+2*w+20,y,w,h,"Total");
    neededShares = new Fl_Input(x+4*w,y,w,h,"Needed");
    y = margin*4;
    inSecret = std::make_unique<Fl_Input>(x+50,y,width/2,h,"Secret");
    window->add(inSecret.get());
    button = std::make_unique<Fl_Button>(x+50+(width/2),y,(width/2)-50,h, "Divide");
    button->callback(cipherButtonCallback,this);
    window->add(button.get());
    y+=h+margin;
    h = (height-margin)/3;
    x= 20;
    logOutput =std::make_unique<Fl_Multiline_Output>(x,y, width-margin,height);
    loScroll = new Fl_Scroll(x,y, width,h);
    loScroll->add(logOutput.get());
    window->add(loScroll);
    y+=h+margin;
    pointsOutput =std::make_unique<Fl_Multiline_Output>(x,y, width-margin,height);
    poScroll = new Fl_Scroll(x,y, width,h);
    poScroll->add(pointsOutput.get());
    window->add(poScroll);
    y+=h+margin;
    joinButton = std::make_unique<Fl_Button>(x,y,width,2*margin,"Join secrets");
    joinButton->callback(joinButtonCallback);
    window->add(joinButton.get());
}


MainProgram::MainProgram() {
    margin = 20;
    width = 440;
    height = 600;
}

void MainProgram::addToLog(const char *text) {
    log.append(text);    log.append("\n");
    this->logOutput->resize(this->logOutput->x(),this->logOutput->y(),this->logOutput->w(),this->logOutput->h()+margin*2);
    this->logOutput->redraw();
    logOutput->clear_output();
    logOutput->value(log.c_str());
}

void MainProgram::addPoint(int x, int val){
    std::stringstream point;
    this->pointsOutput->resize(this->pointsOutput->x(),this->pointsOutput->y(),this->pointsOutput->w(),this->pointsOutput->h()+margin*2);
    this->pointsOutput->redraw();
    point<<this->pointsOutput->value();
    point<<"("<<x<<","<<val<<")"<<"\n";
    pointsOutput->clear_output();
    pointsOutput->value(point.str().c_str());

}
void MainProgram::joinButtonCallback(Fl_Widget *w, void *p) {
    JoiningWindow *jw;
    jw = new JoiningWindow();
    jw->run();
}

void MainProgram::cipherButtonCallback(Fl_Widget *w, void *p) {
    MainProgram *mp;
    mp = (MainProgram *) p;
    mp->logOutput->value("");
    mp->pointsOutput->value("");
    mp->log.clear();
    mp->pointsOutput->resize(mp->pointsOutput->x(),mp->pointsOutput->y(),mp->pointsOutput->w(),mp->height);
    mp->logOutput->resize(mp->logOutput->x(),mp->logOutput->y(),mp->logOutput->w(),mp->height);

    try {
        long prime = std::stol(mp->primeIn->value());
        int t = std::stoi(mp->neededShares->value());
        int n = std::stoi(mp->allShares->value());
        SchemeParter sp(n,t);
        int sec = std::stoi(mp->inSecret->value());
        auto res = sp.part(sec, prime,mp);
        for (auto actualPair:res) {
            mp->addPoint(actualPair.first, actualPair.second);
        }
    } catch(std::exception &e) {
        mp->addToLog("Conversion error");
        mp->addToLog(e.what());
    }
}

