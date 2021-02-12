/*=====================================================================
  setSourceTerm.cpp   
  Yota INOUE (2021) 
  関数実装ファイル 
  ポアソン方程式のディリクレ境界条件を設定(圧力の固定をするかしないかを設定)
  Last update: Feb 11, 2021
=======================================================================*/
#include "inputs.hpp"
#include "../functions.hpp"

void setSourceTerm(void)
{
    int i;
    double n0 = N0_forNumberDensity;
    double gamma = RELAXATION_COEFFICIENT_FOR_PRESSURE;

    for (i = 0; i < NumberOfParticles; i++)
    {
        SourceTerm[i] = 0.0;
        if (ParticleType[i] == GHOST || ParticleType[i] == DUMMY_WALL)
            continue;
        if (BoundaryCondition[i] == INNER_PARTICLE)
        {
            SourceTerm[i] = gamma * (1.0 / (DT * DT)) * ((NumberDensity[i] - n0) / n0);
        }
        else if (BoundaryCondition[i] == SURFACE_PARTICLE)
        {
            SourceTerm[i] = 0.0;
        }
    }
}
