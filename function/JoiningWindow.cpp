//
// Created by mg on 31.10.2020.
//

#include "JoiningWindow.h"
#include "SchemeJoiner.h"

void JoiningWindow::buttonCallback(Fl_Widget *w, void *p) {
    JoiningWindow *jw;
    jw = (JoiningWindow*) p;
    try {
        int x = std::stoi(jw->inSecret->value());
        int val = std::stoi(jw->inVal->value());
        jw->addPoint(x, val);
    } catch (std::exception &e) {
        jw->addToLog("Conversion error");
        jw->addToLog(e.what());
    }
}

void JoiningWindow::run() {
    this->myDraw();
    this->show();
}
void JoiningWindow::addToLog(const char *text) {
    log.append(text);    log.append("\n");
    this->logOutput->resize(this->logOutput->x(),this->logOutput->y(),this->logOutput->w(),this->logOutput->h()+10);
    this->logOutput->redraw();
    logOutput->clear_output();
    logOutput->value(log.c_str());
}
void JoiningWindow::myDraw(){
    this->label("Shamir Scheme join");
    int x = margin;
    int h = margin*2;
    int w = width/4;
    int y = margin;
    primeIn = new Fl_Input(x+50,y,w,h,"Prime");
    neededShares = new Fl_Input(x+3*w,y,w,h,"Needed");
    y = margin*4;
    inSecret = new Fl_Input(x+50,y,50,h,"Point");
    inVal= new Fl_Input(x+150,y,100,h,"Value");
    button = new Fl_Button(x+50+(width/2),y,(width/2)-50,h, "Add");
    button->callback(buttonCallback,this);
    y+=h+margin;
    joinButton = new Fl_Button(x,y,width,h, "Join secrets");
    joinButton->callback(joinButtonCallback,this);
    y+=h+margin;
    x= 20;
    h = (height- h - margin)*2/5;
    logOutput = new Fl_Multiline_Output(x,y, width,h);
    loScroll = new Fl_Scroll(x,y, width,h);
    loScroll->add(logOutput);
    this->add(loScroll);
    y+=h;
    h=2*margin;
    secretOutput = new Fl_Output(x+50,y, width-50,h,"Secret");
    this->add(secretOutput);
    y+=h+margin;

}

JoiningWindow::JoiningWindow(int w, int h, const char *title) : Fl_Window(w, h, title) {
    width = w;
    height = h;
}

void JoiningWindow::addPoint(int x, long value){
    auto q = std::pair<int,long>();
    q.first = x;
    q.second = value;
    shares.push_back(q);
    char buf[30];
    sprintf(buf,"(%d,%ld)",x,value);
    addToLog(buf);
}

JoiningWindow::JoiningWindow():Fl_Window(480,640,"Shamir Scheme join"){
    width =440;
    margin = 20;
    height = 600;
}

void JoiningWindow::joinButtonCallback(Fl_Widget *w, void *p) {
    JoiningWindow *mp;
    mp = (JoiningWindow*)p;
    mp->logOutput->value("");
    mp->secretOutput->value("");
    mp->log.clear();
    mp->logOutput->resize(mp->logOutput->x(),mp->logOutput->y(),mp->logOutput->w(),mp->height);
    try {
        long prime = std::stol(mp->primeIn->value());
        int t = std::stoi(mp->neededShares->value());
        SchemeJoiner sp(t,prime);
        mp->addToLog("Fine");
        auto res = sp.joinShares(mp->shares,mp);
        auto rString= std::to_string(res);
        mp->secretOutput->value(rString.c_str());
        mp->shares.clear();
        mp->addToLog("Shares cleared");
    } catch(std::exception &e) {
        mp->addToLog("Conversion error");
        mp->addToLog(e.what());
        mp->shares.clear();
        mp->addToLog("Shares cleared");
    }
}
