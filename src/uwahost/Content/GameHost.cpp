#include "pch.h"
#include "GameHost.h"

#include "..\Common\DirectXHelper.h"

using namespace uwahost;

using namespace DirectX;
using namespace Windows::Foundation;

GameHost::GameHost(const std::shared_ptr<DX::DeviceResources>& deviceResources)
    : _deviceResources(deviceResources)
    , _loadingComplete(false)
{
    this->CreateDeviceDependentResources();
    this->CreateWindowSizeDependentResources();
}

void GameHost::CreateDeviceDependentResources()
{
    // TODO: Load shaders, meshes, etc.

    _loadingComplete = true;
}

void GameHost::CreateWindowSizeDependentResources()
{
    // TODO: Create constant buffers and other static assets that are window size dependant
}

void GameHost::ReleaseDeviceDependentResources()
{
    _loadingComplete = false;
    // TODO: Release all native resources including shaders, meshes, constant buffers, etc.
}

void GameHost::Update(DX::StepTimer const& timer)
{
    // TODO: Pass dt
    _game.Step();
}

void GameHost::Render()
{
    if (!_loadingComplete)
        return;

    _game.Draw();
}
