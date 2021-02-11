/*=====================================================================
  weight.cpp   
  Yota INOUE (2021) 
  関数実装ファイル 
  シミュレーションメインループ
  Last update: Feb 11, 2021
=======================================================================*/
#include "inputs.hpp"
#include "../functions.hpp"

void mainLoopOfSimulation(void)
{
    int iTimeStep = 0;

    writeData_inVtuFormat();
    writeData_inProfFormat();

    while (1)
    {
        calGravity();
        calViscosity();
        moveParticle();
        collision();
        calPressure();
        calPressureGradient();
        moveParticleUsingPressureGradient();
        iTimeStep++;
        Time += DT;
        if ((iTimeStep % OUTPUT_INTERVAL) == 0)
        {
            printf("TimeStepNumber: %4d   Time: %lf(s)   NumberOfParticless: %d\n", iTimeStep, Time, NumberOfParticles);
            writeData_inVtuFormat();
            writeData_inProfFormat();
        }
        if (Time >= FINISH_TIME)
        {
            break;
        }
    }
}