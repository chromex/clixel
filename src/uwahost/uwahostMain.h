#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "Content\SampleFpsTextRenderer.h"
#include "Content\GameHost.h"

// Renders Direct2D and 3D content on the screen.
namespace uwahost
{
	class uwahostMain : public DX::IDeviceNotify
	{
	public:
		uwahostMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~uwahostMain();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;
		std::unique_ptr<SampleFpsTextRenderer> m_fpsTextRenderer;
        std::unique_ptr<GameHost> m_clixelGame;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}