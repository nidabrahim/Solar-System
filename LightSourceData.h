/******************************************************************************\
*     Copyright (C) 2017 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: LightSourceData.h                                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_LIGHTSOURCE_DATA_H
#define HEADER_LIGHTSOURCE_DATA_H

#include <vector>
#include "RenderingGlobalRoutines.h"
/**
 * Représentation d'une source lumineuse et son comportement
 */
class LightSourceData {
public:
    /** Classe représentant une source lumineuse */
  class PointLightSource{
    int mLightId;
  public:
    int getLightId() const;

    const float *getLightPosition() const;

    const float *getDiffuseIntensity() const;

    const float *getSpecularIntensity() const;

  private:
    // GL_LIGHT0, GL_LIGHT1, etc.
    float mLightPosition[4] = {0.0f,0.0f,10.0f,0.0f};
    float mDiffuseIntensity[4] = {0.6f,0.6f,0.6f,1.0f}; // Intensité diffuse
    float mSpecularIntensity[4] = {0.6f,0.6f,0.6f,1.0f}; // Intensité spéculaire

  public:
    /** Constructeur initialisant toutes les propriétés de la source */
    PointLightSource(int lightId,
                float lightPositionX, float lightPositionY, float lightPositionZ,
                float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
                float specularIntensityR, float specularIntensityG, float specularIntensityB);

    /** Positionner la source dans le repère courant */
    void ApplyPosition() const;

    /** Applique l'intensité de la source et active la source */
    void ApplyIntensity() const;

    /** Désactive la source */
    void Disable() const;
  };

  /** Types de repères supportés (repères du monde et de la caméra) */
  enum class TypeRepere{
    MONDE = 0, CAMERA = 1
  };

  /** Constructeur par défaut (ne crée aucune source lumineuse) */
  LightSourceData();

  /** Destructeur */
  ~LightSourceData() = default;

  /** Ajoute une source lumineuse dans un certain repère
   * @return true en case de succès, false en cas d'ID lightId déjà pris */
  bool AddSource(LightSourceData::TypeRepere typeRepere, int lightId,
	  float lightPositionX, float lightPositionY, float lightPositionZ,
	  float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
	  float specularIntensityR, float specularIntensityG, float specularIntensityB);

  /** Supprime une source lumineuse dans un certain repère
   * La méthode est un peu lourde pour garder des tableaux contigus.
   * @return true en case de succès, false en case d'ID inexistant */
  bool DeleteSource(int lightId);

  /** Positionner les sources qui se trouvent dans un certain repère */
  void ApplyLightPositions(LightSourceData::TypeRepere typeRepere) const;

  /** Applique les intensités de toutes les sources de la scène */
  void ApplyLightIntensities() const;

  /** Applique les intensités de toutes les sources de la scène */
  void DisableLightSources(LightSourceData::TypeRepere typeRepere);

private:
  /** Obtient l'ensemble des sources à placer dans un certain repère
   *
   * @param reverse true pour les sources de l'autre repère que typeRepere **/
  std::vector<LightSourceData::PointLightSource>& GetSourcesByRepere(
                                  LightSourceData::TypeRepere typeRepere,
                                  bool reverse = false);
  const std::vector<LightSourceData::PointLightSource>& GetSourcesByRepere(
                                  LightSourceData::TypeRepere typeRepere,
                                  bool reverse = false) const;

  /** Collection de sources lumineuses dans le repère de la caméra */
  std::vector<PointLightSource> mSourcesRepereCamera;
  /** Collection de sources lumineuses dans le repère du monde */
  std::vector<PointLightSource> mSourcesRepereMonde;
};
#endif //HEADER_LIGHTSOURCEDATA_H
