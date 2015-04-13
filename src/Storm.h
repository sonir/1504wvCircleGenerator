//
//  Storm.h
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#ifndef __Vector__Storm__
#define __Vector__Storm__

#define STORM_COLOR 255 //def:255
#define CONST_PARTICLE_MAX 1000 //Def 100000
#define ST_PARTICLE_NUM 0 //
#define ST_FRICTION 0.002 //def 0.002 , Range 0.-0.07
#define ST_FRICTION_MAX 0.01
#define ST_PARTICLE_SIZE .1 //def 1.0 , Range: .1 - 30.
#define PARTICLE_SIZE_MAX 170.0 //170 for soundToy


#include <stdio.h>
#include "slAppManager.h"
#include "Particle.h"
#include "ofxVideoRecorder.h"
#include "interpolation.h"


class Storm : public slAppManager {
    
public:
    
    void setup();
    void update(int mouseX, int mouseY);
    void draw(int mouseX, int mouseY);
    void setAttraction(bool val);
    void setParticleNum(int inum);
    void incrementParticleNum();
    void generateParticle();
    void initParticle();
    void updateParams();
    void reset();
    
    
    //For Video Capture
    //For Capture
    ofFbo cap;
    ofPixels p;
    ofImage *img;
    ofVideoGrabber      vidGrabber;
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

    
    
    // パーティクルクラスをインスタンス化
    vector<Particle> particles;
    vector<Interpolation> sizes;
    // メッシュ
    ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    // パーティクルの最大数
    static const int PARTICLE_MAX_NUM = CONST_PARTICLE_MAX;
    //Number of display particle
    int storm_particle_num;
    //particleの移動抵抗
    float storm_friction = ST_FRICTION;
    //Size of Particle
    GLfloat particle_size = ST_PARTICLE_SIZE;
    int storm_color = STORM_COLOR;
    
    //For AudioVisual
    const float size_min = 0.0f;
    const float size_max = 150.0f;
    const int duration_size_change = 8;
    float size_scale;
    
    
    
};
#endif /* defined(__Vector__Storm__) */
