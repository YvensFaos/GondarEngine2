#ifndef __GS_GONDAR_ENGINE_2_H__
#define __GS_GONDAR_ENGINE_2_H__

// Arquivo que deve incluir todas as funções da engine
// 
// O intuito deste arquivo é facilitar a integração da engine em jogos desenvolvidos
// em projetos separados

#include "gsConfig.h"

#include "Memory\gsMemory.h"
#include "Memory\gsPoolAllocator.h"

#include "Data\gsArrayList.h"
#include "Data\gsArrayStack.h"
#include "Data\gsLinkedList.h"
#include "Data\gsHashmap.h"

#include "Math\gsVector2.h"
#include "Math\gsColor.h"
#include "Math\gsTextureCoordinates.h"

#include "System\Subsystems\gsLogger.h"
#include "System\Subsystems\gsRandom.h"
#include "System\Subsystems\gsClock.h"
#include "System\Subsystems\gsOpenGL.h"
#include "System\Subsystems\Event\gsEvent.h"
#include "System\Subsystems\Graphics\gsWindow.h"
#include "System\Subsystems\Graphics\gsGraphics.h"
#include "System\Subsystems\Audio\gsAudio.h"
#include "System\Subsystems\Collision\gsCollision.h"
#include "System\Subsystems\Content\gsContent.h"

#include "System\gsGame.h"
#include "System\gsGameObject.h"
#include "System\gsEngine.h"

#include "Objects\gsTransform.h"
#include "Objects\gsTexture.h"
#include "Objects\gsSpriteSheet.h"
#include "Objects\gsGameObjectList.h"

#endif