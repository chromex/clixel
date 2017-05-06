#include "pch.h"
#include "ClixelGame.h"

#include "..\Common\DirectXHelper.h"

using namespace uwahost;

using namespace DirectX;
using namespace Windows::Foundation;

ClixelGame::ClixelGame(const std::shared_ptr<DX::DeviceResources>& deviceResources)
    : _deviceResources(deviceResources)
    , _loadingComplete(false)
{
    this->CreateDeviceDependentResources();
    this->CreateWindowSizeDependentResources();
}

void ClixelGame::CreateDeviceDependentResources()
{
    // TODO: Load shaders, meshes, etc.

    _loadingComplete = true;
}

void ClixelGame::CreateWindowSizeDependentResources()
{
    // TODO: Create constant buffers and other static assets that are window size dependant
}

void ClixelGame::ReleaseDeviceDependentResources()
{
    _loadingComplete = false;
    // TODO: Release all native resources including shaders, meshes, constant buffers, etc.
}

void ClixelGame::Update(DX::StepTimer const& timer)
{
    // TODO: Call game update
}

void ClixelGame::Render()
{
    if (!_loadingComplete)
        return;

    // TODO
}
