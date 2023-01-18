#pragma once

#include <ghudvk/core.h>
#include <ghudcpp/ghud.h>
#include <ghudvk/api/buffer.h>

namespace GHUD {
	struct VulkanContextCreateInfo {
		VkDevice m_Device;
		VkPhysicalDevice m_PhysicalDevice;
		VkRenderPass m_RenderPass;
		uint32 m_SubPass;
		VkFormat m_FrameBufferFormat;
		uint32 m_SwapChainImageCount;
	};

	struct VulkanFrameInfo {
		uint32 m_FrameIndex;
		VkCommandBuffer m_CommandBuffer;
	};

	using VulkanFrameInfoStruct = void;

	class VulkanContext : public Context {
	public:
		GHUDVK_API VulkanContext(const VulkanContextCreateInfo& createInfo);
		GHUDVK_API ~VulkanContext();
		GHUDVK_API void SetCommandBuffer(VkCommandBuffer commandBuffer);
		GHUDVK_API virtual void Render(VulkanFrameInfoStruct* frameInfoStruct) override;
		GHUDVK_API ResourceObject CreateTexture(const VkDescriptorImageInfo& imageInfo);
	private:
		GHUDVK_API void CreateGraphicsPipeline(const VulkanContextCreateInfo& createInfo);

		VkDescriptorPool m_DescriptorPool;
		VkDescriptorSetLayout m_TextureDescriptorSetLayout;
		VkDescriptorSetLayout m_BufferDescriptorSetLayout;
		VkPipelineLayout m_PipelineLayout;
		VkPipeline m_GraphicsPipeline;
		VkPhysicalDevice m_PhysicalDevice;
		VkDevice m_Device;

		VkDescriptorSet m_BufferDescriptorSet;

		uint32 m_SwapChainImageCount;
		std::vector<Buffer*> m_GlobalUBO;
		std::vector<Buffer*> m_IDSSBO;
	};
}