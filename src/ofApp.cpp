#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setParticleSize(float &val){
//    float scaled_num = val*PARTICLE_SIZE_MAX;
//    calcSize.init((float)storm.particle_size, scaled_num, TIME_INTERPOLATION);
//    storm.particle_size = (GLfloat)scaled_num;

    calcSize.init((float)storm.particle_size, val, TIME_INTERPOLATION);
//    storm.particle_size = val;
    
    cout << "particle_size: " << storm.particle_size << endl;
    
}

//--------------------------------------------------------------
void ofApp::setParticleNum(float &val){
    
//    float scaled_num = val*CONST_PARTICLE_MAX;
//    storm.setParticleNum((int)scaled_num);
//    cout << "particle_num: " << storm.storm_particle_num << endl;
    cout << "setParticleNum was ignored in circleGenerator" << endl;
    
}

//--------------------------------------------------------------
void ofApp::setFriction(float &val){
    
    float scaled_num = val*ST_FRICTION_MAX;
    storm.storm_friction = scaled_num;
    cout << "friction: " << storm.storm_friction << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setPointX(float &val){
    
    int scaled_num = (int)(val*(float)ofGetWidth());
    pointX = scaled_num;
    cout << "PointX: " << pointX << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setPointY(float &val){
    
    float h = (float)ofGetHeight();
    int scaled_num = (int)( h-(h*val) );
    pointY = scaled_num;
    cout << "PointY: " << pointY << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::setAttract(float &val){
    
    bool flg = (bool)val;
    storm.atraction = flg;
    if(flg){
        cout << "attract_on" << endl;
    }else {
        cout << "attract_off" << endl;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::setCamZ(float &val){
    
    float scaled_num = val*CAM_POSI_Z_MAX;
    cam_posi_z = scaled_num;
    cout << "cam_posi_z: " << cam_posi_z << endl;
    
}

//--------------------------------------------------------------
void ofApp::setCamX(float &val){
    
//    float scaled_num = (val*(float)ofGetWidth()*-1);
    float scaled_num = ofMap(val, 0.0f, 1.0f, (float)ofGetWidth()/2, ((float)ofGetWidth()*-1)/2);
    cam_posi_x = scaled_num;
    cout << "cam_posi_z: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setCamY(float &val){
    
//    float scaled_num = (val*(float)ofGetHeight()*-1);
    float scaled_num = ofMap(val, 0.0f, 1.0f, (float)ofGetHeight()/2, ((float)ofGetHeight()*-1)/2);
    cam_posi_y = scaled_num;
    cout << "cam_posi_y: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setBrightness(float &val){
    
    //    float scaled_num = (val*(float)ofGetHeight()*-1);
    int scaled_num = (int)(val * 255.0f);
    storm.storm_color = scaled_num;
    cout << "brightness: " << cam_posi_x << endl;
    
}

//--------------------------------------------------------------
void ofApp::setBlur(float &val){
    
    int scaled_num = 255-(int)(val * 255.0f);
    blur = scaled_num;
    cout << "blur: " << blur << endl;
    
}

//--------------------------------------------------------------

void ofApp::addParticle(float &val){
    
    storm.incrementParticleNum();
    
}

//--------------------------------------------------------------
void ofApp::setSizeScale(float &val){
    
    float inversed = 1.0-val;
    storm.size_scale = inversed;
    
}




//--------------------------------------------------------------
void ofApp::setup(){

    osc = new OscManager(57112);
    
    cout << "setup" << endl;
    ofSetFrameRate(30);
    ofEnableSmoothing();

    
    //Setup storm
    ofSetCircleResolution(100);
    storm.setup();
    
    //Setup OSC Event Fire
    ofAddListener(osc->chgParticleSize, this, &ofApp::setParticleSize);
    ofAddListener(osc->chgParticleNum, this, &ofApp::setParticleNum);
    ofAddListener(osc->chgFriction, this, &ofApp::setFriction);
    ofAddListener(osc->chgPointX, this, &ofApp::setPointX);
    ofAddListener(osc->chgPointY, this, &ofApp::setPointY);
    ofAddListener(osc->chgAttract, this, &ofApp::setAttract);
    ofAddListener(osc->chgCamZ, this, &ofApp::setCamZ);
    ofAddListener(osc->chgCamX, this, &ofApp::setCamX);
    ofAddListener(osc->chgCamY, this, &ofApp::setCamY);
    ofAddListener(osc->chgBrightness, this, &ofApp::setBrightness);
    ofAddListener(osc->chgBlur, this, &ofApp::setBlur);
    ofAddListener(osc->addParticle, this, &ofApp::addParticle);
    ofAddListener(osc->chgSizeScale, this, &ofApp::setSizeScale);
    
    
    //For Video Capture
    //Capture Setting
    sampleRate = 44100;
    channels = 2;
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    //If you want to use grabber
    
    fileName = "stormDemo";
    fileExt = ".mov"; // ffmpeg uses the extension to determine the container type. run 'ffmpeg -formats' to see supported formats
    
    // override the default codecs if you like
    // run 'ffmpeg -codecs' to find out what your implementation supports (or -formats on some older versions)
    vidRecorder.setVideoCodec("mpeg4");
    vidRecorder.setVideoBitrate("4000k"); //def is 800k
    vidRecorder.setAudioCodec("mp3");
    vidRecorder.setAudioBitrate("192k");
    
    //    soundStream.listDevices();
    //    soundStream.setDeviceID(11);
    soundStream.setup(this, 0, channels, sampleRate, 256, 4);
    
    bRecording = false;
    ofEnableAlphaBlending();
    
    
    
    //Setup FBO
//    cap.allocate(SC_WIDTH,SC_HEIGHT);
    cap.allocate(SC_WIDTH,SC_HEIGHT,GL_RGBA, 512);

    cap.begin();
    ofClear(0, 0, 0);
    cap.end();
    //    img = new ofImage;
    //Set Image time for RGB (without RGBA)
    converted.setImageType(OF_IMAGE_COLOR);

    
}

//--------------------------------------------------------------
void ofApp::update(){

    storm.particle_size = (GLfloat)calcSize.update();
    storm.update(pointX, pointY);
    osc->update();
    
    //VideoCapture
    if(bRecording){
        cap.readToPixels(recordPixels);
        convertPixels();
        vidRecorder.addFrame(converted);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    cap.begin();

    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, blur); //半透明の黒（背景色）
    ofRect(0, 0, ofGetWidth(), ofGetHeight()); //画面と同じ大きさの四角形を描画
    
//    ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
    ofTranslate(cam_posi_x, cam_posi_y, cam_posi_z);
    storm.draw(pointX, pointY);

    cap.end();
    cap.draw(0,0);
    
#ifdef DISP_POINT
    // 重力の点を描く
    if (storm.atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(pointX, pointY, 4);
#endif
    
    if(bRecording){
        ofSetColor(255, 0, 0);
        ofCircle(ofGetWidth() - 20, 20, 5);
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {

        storm.reset();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
 
    if(key=='r'){
        bRecording = !bRecording;
        if(bRecording && !vidRecorder.isInitialized()) {
            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, SC_WIDTH, SC_HEIGHT, 30, sampleRate, channels);
        }
    }
    if(key=='c'){
        bRecording = false;
        vidRecorder.close();
    }
    if(key=='i'){
        
        storm.incrementParticleNum();
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    storm.setAttraction(true);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    storm.setAttraction(false);
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if(bRecording){
        vidRecorder.addAudioSamples(input, bufferSize, nChannels);
    }
}

//--------------------------------------------------------------
void ofApp::convertPixels(){
    
    
    //Make Array for treating each pixcels
    unsigned char * pixels = recordPixels.getPixels();
    unsigned char pixs2[SC_WIDTH*SC_HEIGHT*3];
    
    for(int i = 0; i < SC_WIDTH*SC_HEIGHT; i++)
    {
        pixs2[i*3]   = pixels[i*4];
        pixs2[i*3+1] = pixels[i*4+1];
        pixs2[i*3+2] = pixels[i*4+2];
    }
    
    //Copy the pixels into converted buffer with 3channel
    converted.setFromExternalPixels(pixs2, SC_WIDTH, SC_HEIGHT, 3);
    
}

