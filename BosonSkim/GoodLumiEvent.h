#ifndef GOODLUMIEVENT_H
#define GOODLUMIEVENT_H

class GoodLumiEvent {
    private:
        int isGoodBCID_8(int bcid); //2012+2013
        int isGoodBCID_72(int bcid); //2013
        int isGoodBCID_206(int bcid); //2013
        int isGoodBCID_296(int bcid); // 2013
        int isGoodBCID_254(int bcid); // 2013
        int isGoodBCID_144(int bcid); // 2013
        int isGoodBCID_248(int bcid); // 2013
    public:
        int run;
        int lb;
        int bcid;
        GoodLumiEvent(int prun, int plb, int pbcid):
            run(prun), lb(plb), bcid(pbcid) {};
        ~GoodLumiEvent() {}
        int isGoodEvent();


};
#endif
