#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include "game\game.h"

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

    private:
        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources> _deviceResources;
        bool _loadingComplete;
        Game _game;
    };
}