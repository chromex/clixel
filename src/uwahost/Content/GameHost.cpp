#include "pch.h"
#include "GameHost.h"

#include "..\Common\DirectXHelper.h"

using namespace uwahost;

using namespace DirectX;
using namespace Windows::Foundation;

GameHost::GameHost(const std::shared_ptr<DX::DeviceResources>& deviceResources)
    : _deviceResources(deviceResources)
    , _loadingComplete(false)
    , _native(new NativeAbstraction())
{
    _keyboard = (NativeKeyboard*)_native->GetKeyboard();

    this->CreateDeviceDependentResources();
    this->CreateWindowSizeDependentResources();
    ClxG()->Init(_native);
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
    _keyboard->Update();
}

void GameHost::Render()
{
    if (!_loadingComplete)
        return;

    _game.Draw();
}

void GameHost::OnKeyDown(Windows::System::VirtualKey key)
{
    _keyboard->OnKeyDown(key);
}

void GameHost::OnKeyUp(Windows::System::VirtualKey key)
{
    _keyboard->OnKeyUp(key);
}
