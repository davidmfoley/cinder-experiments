//
//  ParticleController.h
//  HellCinder
//
//  Created by Dave on 4/26/13.
//
//

#ifndef __HellCinder__ParticleController__
#define __HellCinder__ParticleController__

#include <iostream>
#include "Particle.h"

#endif /* defined(__HellCinder__ParticleController__) */
class ParticleController {
public:
    ParticleController();
    void update(cinder::Channel32f channel);
    void draw();
    void addParticles(int amt);
    void removeParticles(int amt);

    std::list<Particle> particles;
};