#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include "game\game.h"
#include "NativeAbstraction.h"

namespace uwahost
{
    class GameHost
    {
    public:
        GameHost(const std::shared_ptr<DX::DeviceResources>& deviceResources);
        void CreateDeviceDependentResources();
        void CreateWindowSizeDependentResources();
        void ReleaseDeviceDependentResources();
        void Update(DX::StepTimer const& timer);
        void Render();
        void OnKeyDown(Windows::System::VirtualKey key);
        void OnKeyUp(Windows::System::VirtualKey key);

    private:
        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources> _deviceResources;
        std::shared_ptr<ClxNativeAbstraction> _native;
        NativeKeyboard* _keyboard;
        bool _loadingComplete;
        Game _game;
    };
}