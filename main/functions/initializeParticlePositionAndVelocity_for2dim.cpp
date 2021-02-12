/*=====================================================================
  initializeParticlePositionAndVelocity_for2dim.cpp   
  Yota INOUE (2021) 
  関数実装ファイル 
  二次元での計算を始める前の初期化
  Last update: Feb 12, 2021
=======================================================================*/
#include "../inputs.hpp"
#include "../functions.hpp"

void initializeParticlePositionAndVelocity_for2dim(void)
{
    int iX, iY;
    int nX, nY;
    double x, y, z;
    int i = 0; // 粒子数
    int flagOfParticleGeneration;

    nX = (int)(1.0 / PARTICLE_DISTANCE) + 5;
    nY = (int)(0.6 / PARTICLE_DISTANCE) + 5;
    for (iX = -4; iX < nX; iX++)
    {
        for (iY = -4; iY < nY; iY++)
        {
            x = PARTICLE_DISTANCE * (double)(iX);
            y = PARTICLE_DISTANCE * (double)(iY);
            z = 0.0;
            flagOfParticleGeneration = OFF;

            /* dummy wall region */
            if (((x > -4.0 * PARTICLE_DISTANCE + EPS) && (x <= 1.00 + 4.0 * PARTICLE_DISTANCE + EPS)) && ((y > 0.0 - 4.0 * PARTICLE_DISTANCE + EPS) && (y <= 0.6 + EPS)))
            {
                ParticleType[i] = DUMMY_WALL;
                flagOfParticleGeneration = ON;
            }

            /* wall region */
            if (((x > -2.0 * PARTICLE_DISTANCE + EPS) && (x <= 1.00 + 2.0 * PARTICLE_DISTANCE + EPS)) && ((y > 0.0 - 2.0 * PARTICLE_DISTANCE + EPS) && (y <= 0.6 + EPS)))
            {
                ParticleType[i] = WALL;
                flagOfParticleGeneration = ON;
            }

            /* wall region */
            if (((x > -4.0 * PARTICLE_DISTANCE + EPS) && (x <= 1.00 + 4.0 * PARTICLE_DISTANCE + EPS)) && ((y > 0.6 - 2.0 * PARTICLE_DISTANCE + EPS) && (y <= 0.6 + EPS)))
            {
                ParticleType[i] = WALL;
                flagOfParticleGeneration = ON;
            }

            /* empty region */
            if (((x > 0.0 + EPS) && (x <= 1.00 + EPS)) && (y > 0.0 + EPS))
            {
                flagOfParticleGeneration = OFF;
            }

            /* fluid region */
            if (((x > 0.0 + EPS) && (x <= 0.25 + EPS)) && ((y > 0.0 + EPS) && (y <= 0.50 + EPS)))
            {
                ParticleType[i] = FLUID;
                flagOfParticleGeneration = ON;
            }

            if (flagOfParticleGeneration == ON)
            {
                Position[i * 3] = x;
                Position[i * 3 + 1] = y;
                Position[i * 3 + 2] = z;
                i++;
            }
        }
    }
    NumberOfParticles = i;
    for (i = 0; i < NumberOfParticles * 3; i++)
    {
        Velocity[i] = 0.0;
    }
}
