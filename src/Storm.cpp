//
//  Storm.cpp
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#include "Storm.h"

void Storm::setup(){
    size_scale=1.0;
    
    //Init Vals
    setParticleNum(ST_PARTICLE_NUM);
    
    // 画面基本設定
    ofBackground(0);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(particle_size);

    
    for (int i = 0; i < PARTICLE_MAX_NUM; i++) {
        Particle p;
        p.friction = storm_friction;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }

    for(int i =0; i<storm_particle_num;i++)generateParticle();
    
    cout<<"setup finished"<<endl;
}

void Storm::update(int mouseX, int mouseY){
    
    //update params
    updateParams();
    
    // パーティクルの数だけ計算
    for (int i = 0; i < storm_particle_num; i++){
        // 力をリセット
        particles[i].resetForce();
        // もし引力がはたらいていたら
        if (atraction) {
            // マウスの位置に引力を加える
            particles[i].addAttractionForce(mouseX, mouseY, ofGetWidth(), 0.1);
        }
        // パーティクル更新
        particles[i].update();
        // 画面の端にきたら反対側へ
        particles[i].throughOfWalls();
    }

    
}


void Storm::draw(int mouseX, int mouseY){

//    //MotionBlur
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
//    ofSetColor(0, 0, 0, 31);
//    ofRect(0, 0, ofGetWidth(), ofGetHeight());
//    ofEnableBlendMode(OF_BLENDMODE_ADD);


    // メッシュを点で描く
    mesh.clear();
    ofSetColor(storm_color);

    for (int i = 0; i < storm_particle_num; i++) {
//        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
        ofCircle(particles[i].position.x, particles[i].position.y, (sizes[i].update()*particle_size*sizes[i].random_scale)*size_scale);
    }
    mesh.draw();
    
    
//    // 重力の点を描く
//    if (atraction) {
//        ofSetColor(255, 0, 0);
//    } else {
//        ofSetColor(0, 255, 255);
//    }
//    ofCircle(mouseX, mouseY, 4);
    
//    //文字の背景
//    ofSetColor(0, 127);
//    ofRect(0, 0, 200, 60);
//    
//    // ログを表示
//    ofSetColor(255);
//    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
//    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);

    
}

void Storm::updateParams(){
    
    //Set Particle_size
    glPointSize(particle_size);
    
    //Set friction
    for (int i = 0; i < PARTICLE_MAX_NUM; i++) {
        particles[i].friction = storm_friction;
    }
 
    
    
}

void Storm::setAttraction(bool val){
    
    atraction = val;
    
}


void Storm::setParticleNum(int inum){

    if(inum > CONST_PARTICLE_MAX) inum = CONST_PARTICLE_MAX;
    if (inum < 0) inum = 0;
    
    for(int i=0; i<inum-storm_particle_num;i++){
        
        generateParticle();
        
    }
    storm_particle_num = inum;

    
}

void Storm::incrementParticleNum(){
    
    setParticleNum(storm_particle_num+1);
}

void Storm::generateParticle(){
    
    Blink i;
    i.init(size_min , PARTICLE_SIZE_MAX, duration_size_change);
//        i.init(0 , 10, 10);
    i.random_scale = 0.5 + ofRandom(0.5);
    sizes.push_back(i);
    
    
}

void Storm::initParticle(){

    sizes.clear();
    particles.clear();
    for (int i = 0; i < PARTICLE_MAX_NUM; i++) {
        Particle p;
        p.friction = storm_friction;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }
    storm_particle_num = ST_PARTICLE_NUM;
    
    
}


void Storm::reset(){
    
    initParticle();
    
}