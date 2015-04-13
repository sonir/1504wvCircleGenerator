//
//  OscManager.h
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#ifndef __Vector__OscManager__
#define __Vector__OscManager__

#include <stdio.h>
#include "slOscManager.h"


class OscManager:public slOscManager {

    public:
    OscManager();
    OscManager(int port);
    
    void fireMessage(ofxOscMessage *m);
    //Event Invoking
    ofEvent<float> chgParticleSize; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgParticleNum; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgFriction; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgPointX; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgPointY; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgAttract; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgCamZ; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgCamX; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgCamY; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgBrightness; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgBlur; //Add your own event and invole it in receiveMessage
    ofEvent<float> addParticle; //Add your own event and invole it in receiveMessage
    ofEvent<float> chgSizeScale; //Add your own event and invole it in receiveMessage
    
};

#endif /* defined(__Vector__OscManager__) */
