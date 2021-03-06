// -------------------------------------------------------------------------
//    @FileName			:    NFCHeroPropertyModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2017-02-16
//    @Module           :    NFCHeroPropertyModule
//
// -------------------------------------------------------------------------

#ifndef NFC_HERO_PROPERTY_MODULE_MODULE_H
#define NFC_HERO_PROPERTY_MODULE_MODULE_H

#include "NFComm/NFCore/NFMap.hpp"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIHeroPropertyModule.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFMessageDefine/NFProtocolDefine.hpp"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIEquipPropertyModule.h"
#include "NFComm/NFPluginModule/NFIPropertyModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"

class NFCHeroPropertyModule
    : public NFIHeroPropertyModule
{
public:
	NFCHeroPropertyModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCHeroPropertyModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();

    virtual bool AfterInit();
    virtual bool BeforeShut();


	virtual bool CalFightintHeroProperty(const NFGUID& self);

protected:
	int OnPlayerClassEvent(const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const NFDataList& var);

	virtual int OnObjectHeroRecordEvent(const NFGUID& self, const RECORD_EVENT_DATA& xEventData, const NFData& oldVar, const NFData& newVar);
	virtual bool OnHeroPropertyUpdate(const NFGUID& self, const NFGUID& xHeroGUID);

	virtual bool AddHeroProperty(const NFGUID& self, const NFGUID& xHeroGUID);

	virtual bool CalHeroAllProperty(const NFGUID& self, const NFGUID& xHeroGUID, NFDataList& xDataList);
	virtual bool CalHeroBaseProperty(const NFGUID& self, const NFGUID& xHeroGUID, NFDataList& xDataList);
	virtual bool CalHeroTalentProperty(const NFGUID& self, const NFGUID& xHeroGUID, NFDataList& xDataList);
	virtual bool CalHeroEquipProperty(const NFGUID& self, const NFGUID& xHeroGUID, NFDataList& xDataList);


	int CalHeroDiamond(const int nStar, int& leftStar);
private:

	NFIHeroModule* m_pHeroModule;
	NFIClassModule* m_pLogicClassModule;
    NFIElementModule* m_pElementModule;
	NFIKernelModule* m_pKernelModule;
	NFIGameServerNet_ServerModule* m_pGameServerNet_ServerModule;
	NFIEquipPropertyModule* m_pEquipPropertyModule;
	NFIPropertyModule* m_pPropertyModule;
};

#endif
