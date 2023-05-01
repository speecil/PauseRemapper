#include "Installers/PauseRemapperInstaller.hpp"

#include "PauseRemapperController.hpp"
#include "Zenject/ConcreteBinderGeneric_1.hpp"
#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"
#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

DEFINE_TYPE(PauseRemapper::Installers, PauseRemapperInstaller);

using namespace Lapiz::Zenject::ZenjectExtensions;

namespace PauseRemapper::Installers
{
    void PauseRemapperInstaller::InstallBindings()
    {
        get_Container()->BindInterfacesAndSelfTo<PauseRemapper::PauseRemapperController*>()->AsSingle();
    }
}