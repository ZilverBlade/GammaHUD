#include <ghudcpp/draw/element.h>
#include <ghudcpp/context.h>
#include <ghudcpp/utils/helper.h>

namespace GHUD {
	namespace Element {
		const DrawData Line::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			DrawData data{};

			fvec2 ptA = Utils::ConvertScreenCoordToGPUCoord(m_PointA);
			fvec2 ptB = Utils::ConvertScreenCoordToGPUCoord(m_PointB);
			fvec2 v = fvec2(ptB.x - ptA.x, ptB.y - ptA.y);
			float len = sqrt(v.x * v.x + v.y * v.y);
			v = fvec2(v.x / len, v.y / len);

			const float c = v.x;
			const float s = sqrt(1.0f - c * c);

			const float w = m_Width / ctxInfo->m_ScreenSize.x;

			data.m_AnchorOffset = m_AnchorOffset;
			data.m_RotationMatrix[0].x = c * len;
			data.m_RotationMatrix[0].y = s * len;
			data.m_RotationMatrix[1].x = -s * w;
			data.m_RotationMatrix[1].y = c * w;
			data.m_Position = fvec2((ptA.x + ptB.x) * 0.5f, (ptA.y + ptB.y) * 0.5f);

			data.m_HasTexture = 0;
			data.m_HasInteraction = 0;
			data.m_Color = Utils::ConvertHexColorToFloat4Color(m_Color);
			data.m_UVOffsetA = fvec2(0.0f, 0.0f);
			data.m_UVOffsetB = fvec2(1.0f, 1.0f);
			return data;
		}

		 const DrawData Rect::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			DrawData data{};
			data.m_AnchorOffset = m_AnchorOffset;
			data.m_Position = Utils::ConvertScreenCoordToGPUCoord(m_Transform.m_Coord);

			data.m_RotationMatrix[0].x = m_Transform.m_Scale.x;
			data.m_RotationMatrix[1].y = m_Transform.m_Scale.y;

			data.m_HasTexture = 0;
			data.m_HasInteraction = 0;
			data.m_Color = Utils::ConvertHexColorToFloat4Color(m_Color);
			data.m_UVOffsetA = fvec2(0.0f, 0.0f);
			data.m_UVOffsetB = fvec2(1.0f, 1.0f);
			return data;
		}

		const DrawData Rotor::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			DrawData data{};

			const float s = sin(m_Rotation);
			const float c = cos(m_Rotation);

			data.m_AnchorOffset = m_AnchorOffset;
			data.m_Position = m_Transform.m_Coord;
			data.m_RotationMatrix[0].x = c * m_Transform.m_Scale.x;
			data.m_RotationMatrix[0].y = s * m_Transform.m_Scale.x;
			data.m_RotationMatrix[1].x = -s * m_Transform.m_Scale.y;
			data.m_RotationMatrix[1].y = c * m_Transform.m_Scale.y;

			data.m_HasTexture = 0;
			data.m_HasInteraction = 0;
			data.m_Color = Utils::ConvertHexColorToFloat4Color(m_Color);
			data.m_UVOffsetA = fvec2(0.0f, 0.0f);
			data.m_UVOffsetB = fvec2(1.0f, 1.0f);
			return data;
		}
		const DrawData GHUD::Element::Image::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			return DrawData();
		}
		const DrawData GHUD::Element::Button::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			return DrawData();
		}
		const DrawData GHUD::Element::Text::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			return DrawData();
		}
		const DrawData GHUD::Element::TextButton::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			return DrawData();
		}
		const DrawData GHUD::Element::Window::GenerateDrawData(const GlobalContextInfo* ctxInfo) const {
			return DrawData();
		}
	}
}