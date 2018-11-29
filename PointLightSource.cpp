/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: PointLightSource.cpp                                               * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "LightSourceData.h"

LightSourceData::PointLightSource::PointLightSource(int lightId,
                 float lightPositionX, float lightPositionY, float lightPositionZ,
                 float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
                 float specularIntensityR, float specularIntensityG, float specularIntensityB)
        :mLightId(lightId)
{
  mLightPosition[0] = lightPositionX;
  mLightPosition[1] = lightPositionY;
  mLightPosition[2] = lightPositionZ;
  mLightPosition[3] = 1.0;
  mDiffuseIntensity[0] = diffuseIntensityR;
  mDiffuseIntensity[1] = diffuseIntensityG;
  mDiffuseIntensity[2] = diffuseIntensityB;
  mDiffuseIntensity[3] = 1.0;
  mSpecularIntensity[0] = specularIntensityR;
  mSpecularIntensity[1] = specularIntensityG;
  mSpecularIntensity[2] = specularIntensityB;
  mSpecularIntensity[3] = 1.0;
}

void LightSourceData::PointLightSource::ApplyPosition() const {
  RenderingGlobalRoutines::ApplyPointLightPosition(mLightId, mLightPosition);
}

void LightSourceData::PointLightSource::ApplyIntensity() const{
  RenderingGlobalRoutines::ApplyPointLightIntensity(mLightId,
                                           mDiffuseIntensity, mSpecularIntensity);
}

int LightSourceData::PointLightSource::getLightId() const {
  return mLightId;
}

const float *LightSourceData::PointLightSource::getLightPosition() const {
  return mLightPosition;
}

const float *LightSourceData::PointLightSource::getDiffuseIntensity() const {
  return mDiffuseIntensity;
}

const float *LightSourceData::PointLightSource::getSpecularIntensity() const {
  return mSpecularIntensity;
}

void LightSourceData::PointLightSource::Disable() const {
  RenderingGlobalRoutines::DisablePointLight(mLightId);
}