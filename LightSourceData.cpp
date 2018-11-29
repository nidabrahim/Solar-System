/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: LightSourceData.cpp                                                * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "LightSourceData.h"

LightSourceData::LightSourceData()
        :mSourcesRepereCamera(),
         mSourcesRepereMonde()
{}

bool LightSourceData::AddSource(LightSourceData::TypeRepere typeRepere, int lightId,
               float lightPositionX, float lightPositionY, float lightPositionZ,
               float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
               float specularIntensityR, float specularIntensityG, float specularIntensityB){
  // Test d'exitence de la source dans l'autre repère que celui spécifié
  auto& sourcesAutre = GetSourcesByRepere(typeRepere, true);
  // Test de doublon pour l'ID de la source
  for (auto it = sourcesAutre.begin() ; it != sourcesAutre.end() ; it++){
    if (it->getLightId() == lightId){
      return false;
    }
  }
  // Test d'exitence de la source dans le même repère que celui spécifié
  auto& sources = GetSourcesByRepere(typeRepere);
  // Test de doublon pour l'ID de la source
  for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
    if (it->getLightId() == lightId){
      return false;
    }
  }
  // Ajout effectif de la source lumineuse dans la bonne collection
  GetSourcesByRepere(typeRepere).push_back(
          PointLightSource(lightId,
                           lightPositionX, lightPositionY, lightPositionZ,
                           diffuseIntensityR, diffuseIntensityG, diffuseIntensityB,
                          specularIntensityR, specularIntensityG, specularIntensityB));
  return true ;
}

std::vector<LightSourceData::PointLightSource>& LightSourceData
                      ::GetSourcesByRepere(LightSourceData::TypeRepere typeRepere,
                                                  bool reverse) {
  if (typeRepere == LightSourceData::TypeRepere::CAMERA){
    return reverse ? mSourcesRepereMonde : mSourcesRepereCamera;
  }
  return reverse ? mSourcesRepereCamera : mSourcesRepereMonde;
}

const std::vector<LightSourceData::PointLightSource>& LightSourceData
                      ::GetSourcesByRepere(LightSourceData::TypeRepere typeRepere,
                                                  bool reverse) const {
  if (typeRepere == LightSourceData::TypeRepere::CAMERA){
    return reverse ? mSourcesRepereMonde : mSourcesRepereCamera;
  }
  return reverse ? mSourcesRepereCamera : mSourcesRepereMonde;
}

bool LightSourceData::DeleteSource(int lightId){
  auto& sourcesCamera = mSourcesRepereCamera;
  // Test de doublon pour l'ID de la source
  for (auto it = sourcesCamera.begin() ; it != sourcesCamera.end() ; ++it){
    if (it->getLightId() == lightId){
      sourcesCamera.erase(it); // suppression de l'élément
      return true;
    }
  }
  auto &sourcesMonde = mSourcesRepereMonde;
  // Test de doublon pour l'ID de la source
  for (auto it = sourcesMonde.begin() ; it != sourcesMonde.end() ; ++it){
    if (it->getLightId() == lightId){
      sourcesMonde.erase(it);
      return true;
    }
  }
  return false;
}

void LightSourceData::ApplyLightPositions(LightSourceData::TypeRepere typeRepere) const {
  auto sources = GetSourcesByRepere(typeRepere);
    for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
    it->ApplyPosition();
  }
}

void LightSourceData::ApplyLightIntensities() const {
  auto& sourcesCamera = mSourcesRepereCamera;
  for (auto it = sourcesCamera.cbegin() ; it != sourcesCamera.cend() ; ++it){
    it->ApplyIntensity();
  }
  auto& sourcesMonde = mSourcesRepereMonde;
  for (auto it = sourcesMonde.cbegin() ; it != sourcesMonde.cend() ; ++it){
    it->ApplyIntensity();
  }
}

void LightSourceData::DisableLightSources(
                          LightSourceData::TypeRepere typeRepere){
  auto &sources = GetSourcesByRepere(typeRepere);
  for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
    it->Disable();
  }
}