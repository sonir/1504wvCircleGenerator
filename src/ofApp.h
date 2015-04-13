#pragma once

//#define DISP_POINT


#define SC_WIDTH 1280
#define SC_HEIGHT 720
#define CAM_POSI_X 0.0
#define CAM_POSI_Y 0.0
#define CAM_POSI_Z 0.0
#define CAM_POSI_Z_MAX 1000.0
#define BLUR 255
#define TIME_INTERPOLATION 24

#include "ofMain.h"
#include "slAppManager.h"
#include "Storm.h"
#include "OscManager.h"
//#include "interpolation.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    //Camera Control
    float cam_posi_x = CAM_POSI_X;
    float cam_posi_y = CAM_POSI_Y;
    float cam_posi_z = CAM_POSI_Z;
    //Color Control
    float blur = BLUR;
    
    //OSC Event
    OscManager *osc;
    void setParticleSize(float &val);
    void setParticleNum(float &val);
    void setFriction(float &val);
    void setPointX(float &val);
    void setPointY(float &val);
    void setAttract(float &val);
    void setCamZ(float &val);
    void setCamX(float &val);
    void setCamY(float &val);
    void setBrightness(float &val);
    void setBlur(float &val);
    void addParticle(float &val);
    void setSizeScale(float &val);
    int pointX = 0;
    int pointY = 0;
    Interpolation calcSize;
    
    
    //Model
    Storm storm;
    
    // in ofApp.h :: void test1(float &val);
    // in setup() :: ofAddListener(osc.test1, this, &ofApp::test1);

    //For Capture
    void audioIn(float *input, int bufferSize, int nChannels);
    ofFbo cap;
    ofPixels p;
    ofImage *img;
    // ofVideoGrabber      vidGrabber;
    ofxVideoRecorder    vidRecorder;
    ofSoundStream       soundStream;
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    
    ofFbo recordFbo;
    ofPixels recordPixels;
    ofPixels converted;
    void convertPixels();

    
    
};
