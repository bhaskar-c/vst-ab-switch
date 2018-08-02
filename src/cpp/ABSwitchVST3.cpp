
#include "ABSwitchCIDs.h"

#include <pluginterfaces/vst/ivstcomponent.h>
#include <pluginterfaces/vst/ivstaudioprocessor.h>
#include <public.sdk/source/main/pluginfactoryvst3.h>
#include <pluginterfaces/vst/ivsteditcontroller.h>

#include "version.h"
#include "ABSwitchProcessor.h"
#include "ABSwitchController.h"

using namespace Steinberg::Vst;
using namespace pongasoft::VST::ABSwitch;

#define stringPluginName "ABSwitch VST"

//------------------------------------------------------------------------
//  Module init/exit
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// called after library was loaded
bool InitModule()
{
  return true;
}

//------------------------------------------------------------------------
// called after library is unloaded
bool DeinitModule()
{
  return true;
}


//------------------------------------------------------------------------
//  VST Plug-in Entry
//------------------------------------------------------------------------
BEGIN_FACTORY_DEF ("pongasoft",
                   "https://www.pongasoft.com",
                   "mailto:support@pongasoft.com")

    // ABSwitchProcessor processor
    DEF_CLASS2 (INLINE_UID_FROM_FUID(::pongasoft::VST::ABSwitchProcessorUID),
                PClassInfo::kManyInstances,  // cardinality
                kVstAudioEffectClass,    // the component category (do not changed this)
                stringPluginName,      // here the Plug-in name (to be changed)
                Vst::kDistributable,  // means that component and controller could be distributed on different computers
                "Fx",          // Subcategory for this Plug-in (to be changed)
                FULL_VERSION_STR,    // Plug-in version (to be changed)
                kVstVersionString,    // the VST 3 SDK version (do not changed this, use always this define)
                ABSwitchProcessor::createInstance)  // function pointer called when this component should be instantiated

    // ABSwitchController controller
    DEF_CLASS2 (INLINE_UID_FROM_FUID(::pongasoft::VST::ABSwitchControllerUID),
                PClassInfo::kManyInstances,  // cardinality
                kVstComponentControllerClass,// the Controller category (do not changed this)
                stringPluginName"Controller",  // controller name (could be the same than component name)
                0,            // not used here
                "",            // not used here
                FULL_VERSION_STR,    // Plug-in version (to be changed)
                kVstVersionString,    // the VST 3 SDK version (do not changed this, use always this define)
                ABSwitchController::createInstance)// function pointer called when this component should be instantiated

END_FACTORY
