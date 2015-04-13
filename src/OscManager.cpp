//
//  OscManager.cpp
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#include "OscManager.h"

OscManager::OscManager(int port) : slOscManager( port ) {
    
       
}

void OscManager::fireMessage(ofxOscMessage *m){
    
    
    if(m->getAddress() == "/particle_size"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgParticleSize, fnum);
    }else if(m->getAddress() == "/particle_num"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgParticleNum, fnum);
        
    }else if(m->getAddress() == "/friction"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgFriction, fnum);
    }else if(m->getAddress() == "/point_x"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgPointX, fnum);
    }else if(m->getAddress() == "/point_y"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgPointY, fnum);
    }else if(m->getAddress() == "/attract"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgAttract, fnum);
    }else if(m->getAddress() == "/cam_z"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamZ, fnum);
    }else if(m->getAddress() == "/cam_x"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamX, fnum);
    }else if(m->getAddress() == "/cam_y"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgCamY, fnum);
    }else if(m->getAddress() == "/brightness"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgBrightness, fnum);
    }else if(m->getAddress() == "/blur"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgBlur, fnum);
    }else if(m->getAddress() == "/add"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(addParticle, fnum);
    }else if(m->getAddress() == "/size_scale"){
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(chgSizeScale, fnum);
    }
    

    
}