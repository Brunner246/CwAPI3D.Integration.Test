/** @file 
* Copyright (C) 2024 cadwork informatik AG
* 
* This file is part of the CwAPI3D module for cadwork 3d.
* 
* @ingroup       CwAPI3D
* @since         30.0
* @author        Brunner
* @date          2024-04-03
*/


#pragma once

namespace CwAPI3D
{
  namespace Interfaces
  {

    /**
 * \brief IfcPredefinedType Getter/Setters. Please note that you are responsible for ensuring that the correct values are set.
 * 
 * @code
 * const auto lElementController = aFactory->getElementController();
 * const auto lBimController = aFactory->getBimController();
 *
 * const auto lElementIds = lElementController->getActiveIdentifiableElementIDs();
 * for (auto il{0u}; il < lElementIds->count(); il++)
 * {
 *     const auto lElement = lElementIds->at(il);
 *     const auto lPredefinedType = lBimController->getIfcPredefinedType(lElement);
 *     lPredefinedType->isRafter() ? lPredefinedType->setPurlin() : lPredefinedType->setBeam();
 *     lBimController->setIfcPredefinedType(aFactory->createElementIDListFromElement(lElement), lPredefinedType);
 * }
 * @endcode
 */
    struct ICwAPI3DIfcPredefinedType
    {
      virtual ~ICwAPI3DIfcPredefinedType() = default;

      virtual void destroy() = 0;

      // getter
      virtual bool isNone() = 0;
      virtual bool isCeiling() = 0;
      virtual bool isCladding() = 0;
      virtual bool isFlooring() = 0;
      virtual bool isInsulation() = 0;
      virtual bool isMembrane() = 0;
      virtual bool isRoofing() = 0;
      virtual bool isSleeving() = 0;
      virtual bool isWrapping() = 0;
      virtual bool isFootingBeam() = 0;
      virtual bool isPadFooting() = 0;
      virtual bool isPileCap() = 0;
      virtual bool isStripFooting() = 0;
      virtual bool isCohesion() = 0;
      virtual bool isFriction() = 0;
      virtual bool isSupport() = 0;
      virtual bool isBalustrade() = 0;
      virtual bool isGuardrail() = 0;
      virtual bool isHandrail() = 0;
      virtual bool isBaseslab() = 0;
      virtual bool isFloor() = 0;
      virtual bool isLanding() = 0;
      virtual bool isRoof() = 0;
      virtual bool isBeam() = 0;
      virtual bool isHollowcore() = 0;
      virtual bool isJoist() = 0;
      virtual bool isLintel() = 0;
      virtual bool isSpandrel() = 0;
      virtual bool isTbeam() = 0;
      virtual bool isComplex() = 0;
      virtual bool isElement() = 0;
      virtual bool isPartial() = 0;
      virtual bool isProvisionForSpace() = 0;
      virtual bool isProvisionForVoid() = 0;
      virtual bool isColumn() = 0;
      virtual bool isPilaster() = 0;
      virtual bool isMolding() = 0;
      virtual bool isSkirtingboard() = 0;
      virtual bool isDoor() = 0;
      virtual bool isGate() = 0;
      virtual bool isTrapDoor() = 0;
      virtual bool isCaissonFoundation() = 0;
      virtual bool isBrace() = 0;
      virtual bool isChord() = 0;
      virtual bool isCollar() = 0;
      virtual bool isMember() = 0;
      virtual bool isMullion() = 0;
      virtual bool isPlate() = 0;
      virtual bool isPost() = 0;
      virtual bool isPurlin() = 0;
      virtual bool isRafter() = 0;
      virtual bool isStringer() = 0;
      virtual bool isStrut() = 0;
      virtual bool isStud() = 0;
      virtual bool isBored() = 0;
      virtual bool isDriven() = 0;
      virtual bool isJetgrouting() = 0;
      virtual bool isCurtainPanel() = 0;
      virtual bool isSheet() = 0;
      virtual bool isHalfTurnRamp() = 0;
      virtual bool isQuarterTurnRamp() = 0;
      virtual bool isSpiralRamp() = 0;
      virtual bool isStraightRunRamp() = 0;
      virtual bool isTwoQuarterTurnRamp() = 0;
      virtual bool isTwoStraightRunRamp() = 0;
      virtual bool isBarrelRoof() = 0;
      virtual bool isButterflyRoof() = 0;
      virtual bool isDomeRoof() = 0;
      virtual bool isFlatRoof() = 0;
      virtual bool isFreeform() = 0;
      virtual bool isGableRoof() = 0;
      virtual bool isGambrelRoof() = 0;
      virtual bool isHippedGableRoof() = 0;
      virtual bool isHipRoof() = 0;
      virtual bool isMansardRoof() = 0;
      virtual bool isPavilionRoof() = 0;
      virtual bool isRainbowRoof() = 0;
      virtual bool isShedRoof() = 0;
      virtual bool isCurvedRunStair() = 0;
      virtual bool isDoubleReturnStair() = 0;
      virtual bool isHalfTurnStair() = 0;
      virtual bool isHalfWindingStair() = 0;
      virtual bool isQuarterTurnStair() = 0;
      virtual bool isQuarterWindingStair() = 0;
      virtual bool isSpiralStair() = 0;
      virtual bool isStraightRunStair() = 0;
      virtual bool isThreeQuarterTurnStair() = 0;
      virtual bool isThreeQuarterWindingStair() = 0;
      virtual bool isTwoCurvedRunStair() = 0;
      virtual bool isTwoQuarterTurnStair() = 0;
      virtual bool isTwoQuarterWindingStair() = 0;
      virtual bool isTwoStraightRunStair() = 0;
      virtual bool isCurved() = 0;
      virtual bool isSpiral() = 0;
      virtual bool isStraight() = 0;
      virtual bool isWinder() = 0;
      virtual bool isElementedWall() = 0;
      virtual bool isMovable() = 0;
      virtual bool isParapet() = 0;
      virtual bool isPartitioning() = 0;
      virtual bool isPlumbingWall() = 0;
      virtual bool isPolygonal() = 0;
      virtual bool isShear() = 0;
      virtual bool isSolidWall() = 0;
      virtual bool isStandard() = 0;
      virtual bool isLightdome() = 0;
      virtual bool isSkylight() = 0;
      virtual bool isWindow() = 0;
      virtual bool isOpening() = 0;
      virtual bool isRecess() = 0;
      virtual bool isAnchorbolt() = 0;
      virtual bool isBolt() = 0;
      virtual bool isDowel() = 0;
      virtual bool isNail() = 0;
      virtual bool isNailPlate() = 0;
      virtual bool isRivet() = 0;
      virtual bool isScrew() = 0;
      virtual bool isShearConnector() = 0;
      virtual bool isStaple() = 0;
      virtual bool isStudShearConnector() = 0;
      virtual bool isGlue() = 0;
      virtual bool isMortar() = 0;
      virtual bool isWeld() = 0;
      virtual bool isExternal() = 0;
      virtual bool isGfa() = 0;
      virtual bool isInternal() = 0;
      virtual bool isParking() = 0;
      virtual bool isSpace() = 0;
      virtual bool isAccessoryAssembly() = 0;
      virtual bool isArch() = 0;
      virtual bool isBeamGrid() = 0;
      virtual bool isBracedFrame() = 0;
      virtual bool isGirder() = 0;
      virtual bool isReinforcementUnit() = 0;
      virtual bool isRigidFrame() = 0;
      virtual bool isSlabField() = 0;
      virtual bool isTruss() = 0;
      virtual bool isCableLadderSegment() = 0;
      virtual bool isCableTraySegment() = 0;
      virtual bool isCableTrunkingSegment() = 0;
      virtual bool isConduitSegment() = 0;
      virtual bool isBusbarSegment() = 0;
      virtual bool isCableSegment() = 0;
      virtual bool isConductorSegment() = 0;
      virtual bool isCoreSegment() = 0;
      virtual bool isFlexibleSegment() = 0;
      virtual bool isRigidSegment() = 0;
      virtual bool isCulvert() = 0;
      virtual bool isGutter() = 0;
      virtual bool isSpool() = 0;
      virtual bool isAudioVisualOutlet() = 0;
      virtual bool isCommunicationsOutlet() = 0;
      virtual bool isPowerOutlet() = 0;
      virtual bool isDataOutlet() = 0;
      virtual bool isTelephoneOutlet() = 0;
      virtual bool isAnchoring() = 0;
      virtual bool isEdge() = 0;
      virtual bool isLigature() = 0;
      virtual bool isMain() = 0;
      virtual bool isPunching() = 0;
      virtual bool isRing() = 0;

      // setter
      virtual void setNone() = 0;
      virtual void setCeiling() = 0;
      virtual void setCladding() = 0;
      virtual void setFlooring() = 0;
      virtual void setInsulation() = 0;
      virtual void setMembrane() = 0;
      virtual void setRoofing() = 0;
      virtual void setSleeving() = 0;
      virtual void setWrapping() = 0;
      virtual void setFootingBeam() = 0;
      virtual void setPadFooting() = 0;
      virtual void setPileCap() = 0;
      virtual void setStripFooting() = 0;
      virtual void setCohesion() = 0;
      virtual void setFriction() = 0;
      virtual void setSupport() = 0;
      virtual void setBalustrade() = 0;
      virtual void setGuardrail() = 0;
      virtual void setHandrail() = 0;
      virtual void setBaseslab() = 0;
      virtual void setFloor() = 0;
      virtual void setLanding() = 0;
      virtual void setRoof() = 0;
      virtual void setBeam() = 0;
      virtual void setHollowcore() = 0;
      virtual void setJoist() = 0;
      virtual void setLintel() = 0;
      virtual void setSpandrel() = 0;
      virtual void setTbeam() = 0;
      virtual void setComplex() = 0;
      virtual void setElement() = 0;
      virtual void setPartial() = 0;
      virtual void setProvisionForSpace() = 0;
      virtual void setProvisionFOrVoid() = 0;
      virtual void setColumn() = 0;
      virtual void setPilaster() = 0;
      virtual void setMolding() = 0;
      virtual void setSkirtingboard() = 0;
      virtual void setDoor() = 0;
      virtual void setGate() = 0;
      virtual void setTrapDoor() = 0;
      virtual void setCaissonFoundation() = 0;
      virtual void setBrace() = 0;
      virtual void setChord() = 0;
      virtual void setCollar() = 0;
      virtual void setMember() = 0;
      virtual void setMullion() = 0;
      virtual void setPlate() = 0;
      virtual void setPost() = 0;
      virtual void setPurlin() = 0;
      virtual void setRafter() = 0;
      virtual void setStringer() = 0;
      virtual void setStrut() = 0;
      virtual void setStud() = 0;
      virtual void setBored() = 0;
      virtual void setDriven() = 0;
      virtual void setJetgrouting() = 0;
      virtual void setCurtainFanel() = 0;
      virtual void setSheet() = 0;
      virtual void setHalfTurnRamp() = 0;
      virtual void setQuarterTurnRamp() = 0;
      virtual void setSpiralRamp() = 0;
      virtual void setStraightRunRamp() = 0;
      virtual void setTwoQuarterTurnRamp() = 0;
      virtual void setTwoStraightRunRamp() = 0;
      virtual void setBarrelRoof() = 0;
      virtual void setButterflyRoof() = 0;
      virtual void setDomeRoof() = 0;
      virtual void setFlatRoof() = 0;
      virtual void setFreeform() = 0;
      virtual void setGableRoof() = 0;
      virtual void setGambrelRoof() = 0;
      virtual void setHippedGableRoof() = 0;
      virtual void setHipRoof() = 0;
      virtual void setMansardRoof() = 0;
      virtual void setPavilionRoof() = 0;
      virtual void setRainbowRoof() = 0;
      virtual void setShedRoof() = 0;
      virtual void setCurvedRunStair() = 0;
      virtual void setDoubleReturnStair() = 0;
      virtual void setHalfTurnStair() = 0;
      virtual void setHalfWindingStair() = 0;
      virtual void setQuarterTurnStair() = 0;
      virtual void setQuarterWindingStair() = 0;
      virtual void setSpiralStair() = 0;
      virtual void setStraightRunStair() = 0;
      virtual void setThreeQuarterturnstair() = 0;
      virtual void setThreeQuarterwindingstair() = 0;
      virtual void setTwoCurvedRunStair() = 0;
      virtual void setTwoQuarterTurnStair() = 0;
      virtual void setTwoQuarterWindingStair() = 0;
      virtual void setTwoStraightRunStair() = 0;
      virtual void setCurved() = 0;
      virtual void setSpiral() = 0;
      virtual void setStraight() = 0;
      virtual void setWinder() = 0;
      virtual void setElementedWall() = 0;
      virtual void setMovable() = 0;
      virtual void setParapet() = 0;
      virtual void setPartitioning() = 0;
      virtual void setPlumbingWall() = 0;
      virtual void setPolygonal() = 0;
      virtual void setShear() = 0;
      virtual void setSolidWall() = 0;
      virtual void setStandard() = 0;
      virtual void setLightdome() = 0;
      virtual void setSkylight() = 0;
      virtual void setWindow() = 0;
      virtual void setOpening() = 0;
      virtual void setRecess() = 0;
      virtual void setAnchorbolt() = 0;
      virtual void setBolt() = 0;
      virtual void setDowel() = 0;
      virtual void setNail() = 0;
      virtual void setNailplate() = 0;
      virtual void setRivet() = 0;
      virtual void setScrew() = 0;
      virtual void setShearconnector() = 0;
      virtual void setStaple() = 0;
      virtual void setStudshearconnector() = 0;
      virtual void setGlue() = 0;
      virtual void setMortar() = 0;
      virtual void setWeld() = 0;
      virtual void setExternal() = 0;
      virtual void setGfa() = 0;
      virtual void setInternal() = 0;
      virtual void setParking() = 0;
      virtual void setSpace() = 0;
      virtual void setAccessoryAssembly() = 0;
      virtual void setArch() = 0;
      virtual void setBeamGrid() = 0;
      virtual void setBracedFrame() = 0;
      virtual void setGirder() = 0;
      virtual void setReinforcementUnit() = 0;
      virtual void setRigidFrame() = 0;
      virtual void setSlabField() = 0;
      virtual void setTruss() = 0;
      virtual void setCableLadderSegment() = 0;
      virtual void setCableTraySegment() = 0;
      virtual void setCableTrunkingSegment() = 0;
      virtual void setConduitSegment() = 0;
      virtual void setBusbarSegment() = 0;
      virtual void setCableSegment() = 0;
      virtual void setConductorSegment() = 0;
      virtual void setCoreSegment() = 0;
      virtual void setFlexibleSegment() = 0;
      virtual void setRigidSegment() = 0;
      virtual void setCulvert() = 0;
      virtual void setGutter() = 0;
      virtual void setSpool() = 0;
      virtual void setAudioVisualOutlet() = 0;
      virtual void setCommunicationsOutlet() = 0;
      virtual void setPowerOutlet() = 0;
      virtual void setDataOutlet() = 0;
      virtual void setTelephoneOutlet() = 0;
      virtual void setAnchoring() = 0;
      virtual void setEdge() = 0;
      virtual void setLigature() = 0;
      virtual void setMain() = 0;
      virtual void setPunching() = 0;
      virtual void setRing() = 0;
    };
  }
}
