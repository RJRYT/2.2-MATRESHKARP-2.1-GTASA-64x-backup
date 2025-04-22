#pragma once

#include <cstring>
#include "Entity/CVehicleGTA.h"

/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/


class CVehicle
{
public:
	CVehicle(int iType, float fX, float fY, float fZ, float fRotation, bool bPreloaded, bool bSiren);
	virtual ~CVehicle();

	int GetVehicleSubtype();
	void AddComponent(int iComponentID);
	void RemoveComponent(int iComponentID);
	void SetPaintJob(uint8_t bytePaintJobID);
	void SetColor(uint8_t iColor1, uint8_t iColor2);
	void LinkToInterior(int iInterior);
	void SetDamageStatus(uint32_t dwPanelDamageStatus, uint32_t dwDoorDamageStatus, uint8_t byteLightDamageStatus);
	void SetTireDamageStatus(uint8_t byteTireDamageStatus);
	void SetPlateText(const char* szPlateText) { strncpy(m_szPlateText, szPlateText, 32); }
	void SetZAngle(float fAngle);
	void ProcessMarkers();
	bool IsOccupied();

	void AttachTrailer();
	void DetachTrailer();
	void SetTrailer(CVehicle* pTrailer);

	bool IsRCVehicle();
	float GetHealth();
	void SetHealth(float fHealth);
	CVehicle* GetTrailer();
	CVehicle* GetTractor();
	float GetTrainSpeed();
	uint16_t GetHydraThrusters();
	float GetBikeLean();
	bool IsATrainPart();
	bool IsATowTruck();
	bool IsATrailer();
	bool VerifyInstance();
	bool IsDriverLocalPlayer();
	void SetInvulnerable(bool bInv);
	bool HasSunk();
	bool HasADriver();

	int GetEngineState() { return m_iEngineState; }
	int GetLightState() { return m_iLightState; }

	void ApplyEngineState(int iState);
	void ApplyLightState(int state);

	void SetDoorState(int state);
	void SetComponentOpenState(int iDoor, int iComponent, float fDoorOpenRatio);
	void SetAlarmState(uint16_t wAlarmState) { m_pVehicle->m_nVehicleFlags.bSirenOrAlarm = wAlarmState; }
	void OpenWindow(uint8_t component);
	void CloseWindow(uint8_t component);

	void RemoveEveryoneFromVehicle();

	void UpdateColor();
	bool UpdateLastDrivenTime();

public:
    enum eLightsStatus {
        LIGHTS_OFF, LIGHTS_LEFT, LIGHTS_RIGHT, LIGHTS_BOTH
    };

    void DrawTurnlight(CVehicle *vehicle, unsigned int dummyId, bool leftSide);
    void DrawVehicleTurnlights(CVehicle *vehicle, int i);

    enum eTurnState
    {
        TURN_OFF,
        TURN_LEFT,
        TURN_RIGHT,
        TURN_ALL
    };

    // поворотники
    class CObject*		m_pLeftFrontTurnLighter;
    class CObject*		m_pRightFrontTurnLighter;
    class CObject*		m_pLeftRearTurnLighter;
    class CObject*		m_pRightRearTurnLighter;
    eTurnState 		m_iTurnState;
    bool 			m_bIsOnRightTurnLight;
    bool  			m_bIsOnAllurnLight;
    bool 			m_bIsOnLeftTurnLight;
    bool 			m_bIsOnAllTurnLight;

    void GetMoveSpeedVector(PVECTOR Vector);

    // задний ход
    class CObject*		m_pLeftReverseLight;
    class CObject*		m_pRightReverseLight;

    void toggleRightTurnLight(bool toggle);

    int getSampId();

    void toggleLeftTurnLight(bool toggle);

    void toggleAllTurnLight(bool toggle);

    void toggleReverseLight(bool toggle);

    CVehicleGTA* m_pVehicle;
	CVehicle* m_pTrailer;
    uintptr 		m_dwGTAId;
	bool m_bPreloaded;
	int m_iEngineState;
	int m_iLightState;
	bool m_bIsInvulnerable;
	bool m_bIsLocked;
	bool m_bDoorsLocked;
	uint8_t m_byteObjectiveVehicle;
	bool m_bSpecialMarkerEnabled;
	uint8_t m_byteColor1;
	uint8_t m_byteColor2;
	bool m_bHaveColor;
	bool m_bSiren;
	char m_szPlateText[32];
	uint32_t m_dwMarkerID;

	void UpdateDamageStatus(uint32_t dwPanelDamage, uint32_t dwDoorDamage, uint8_t byteLightDamage);
	void SetPanelDamageStatus(uint32_t dwPanelStatus);
	uint32_t GetPanelDamageStatus();
	void SetDoorDamageStatus(uint32_t dwDoorStatus);
	uint32_t GetDoorDamageStatus();
	void SetLightDamageStatus(uint8_t byteLightStatus);
	uint8_t GetLightDamageStatus();
	void SetWheelPoppedStatus(uint8_t byteWheelStatus);
	uint8_t GetWheelPoppedStatus();

    bool SirenEnabled();

	void EnableSiren(bool bState);

	bool IsLandingGearNotUp();

	bool			m_bHasBeenDriven;
	uint32_t		m_dwTimeSinceLastDriven;\


    void DrawVehicleTurnlights(CVehicleGTA *vehicle, int i);

    void DrawTurnlight(CVehicleGTA *vehicle, unsigned int dummyId, bool leftSide);
};


#include "common.h"

// originally made by Den_spb

#define TURN_ON_OFF_DELAY 500
#define MAX_RADIUS 200.0f

class UniversalTurnlights {
public:
    enum eLightsStatus {
        LIGHTS_OFF, LIGHTS_LEFT, LIGHTS_RIGHT, LIGHTS_BOTH
    };

    class VehicleTurnlightsData {
    public:
        eLightsStatus lightsStatus;
        CVehicleGTA* vehicle; // Указатель на транспортное средство

        VehicleTurnlightsData(CVehicleGTA* veh) : vehicle(veh), lightsStatus(LIGHTS_OFF) {}

        // Метод для получения статуса поворотников
        eLightsStatus& GetLightsStatus() {
            return lightsStatus;
        }
    };

    // Статический объект для хранения данных о поворотниках
    static VehicleTurnlightsData turnlightsData;

    // Метод для инициализации данных о поворотниках
    static void Initialize(CVehicleGTA* veh) {
        UniversalTurnlights::turnlightsData = VehicleTurnlightsData(veh);
    }


} ;