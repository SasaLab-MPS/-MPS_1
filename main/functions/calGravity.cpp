/*=====================================================================
  calGravity.cpp   
  Yota INOUE (2021) 
  関数実装ファイル 
  シミュレーションメインループ
  Last update: Feb 11, 2021
=======================================================================*/
#include "inputs.hpp"
#include "../functions.hpp"

void calGravity( void ){
  int i;

  for(i=0;i<NumberOfParticles;i++){
    if(ParticleType[i] == FLUID){
      Acceleration[i*3  ]=G_X;
      Acceleration[i*3+1]=G_Y;
      Acceleration[i*3+2]=G_Z;
    }else{
      Acceleration[i*3  ]=0.0;
      Acceleration[i*3+1]=0.0;
      Acceleration[i*3+2]=0.0;
    }
  }
}