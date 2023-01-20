#pragma once

#include <ghudcpp/draw/draw_list.h>
#include <ghudcpp/context.h>

namespace GHUD {
	DrawList::DrawList(Context* ctx_) : ctx(ctx_) {
	
	}

	DrawList::~DrawList() {
		this->Clear();
	}

	void DrawList::FrameStart() {
		assert(m_DrawList.size() == 0 && "Draw List must be cleared before frame start!");
	}

	void DrawList::FrameEnd() {
	}

	void DrawList::Clear() {
		m_PreviousSize = m_DrawList.size();
		m_DrawList.clear();
	}

#define DrawDataLast m_DrawData[m_DrawData.size() - 1]

	const Element::Line DrawList::DrawLine(const Element::Line& line) {
		m_DrawList.emplace(DrawInfo{ line.m_Layer, 0, line.GenerateDrawData(&ctx->GetGlobalContextInfo()) });
		return line;
	}
	const Element::Line DrawList::DrawLine(fvec2 m_PointA, fvec2 m_PointB, RGBAColor m_Color, LayerIndex m_Layer) {
		Element::Line obj{};
		obj.m_PointA = m_PointA;
		obj.m_PointB = m_PointB;
		obj.m_Color = m_Color;
		obj.m_Layer = m_Layer;
		m_DrawList.emplace(DrawInfo{ obj.m_Layer, 0, obj.GenerateDrawData(&ctx->GetGlobalContextInfo()) });
		return obj;
	}

	const Element::Rect DrawList::DrawRect(const Element::Rect& rect) {
		m_DrawList.emplace(DrawInfo{ rect.m_Layer, 0, rect.GenerateDrawData(&ctx->GetGlobalContextInfo()) });
		return rect;
	}

	const Element::Rect DrawList::DrawRect(const Element::Transform& m_Transform, const TextureObject& m_Texture, RGBAColor m_Color, LayerIndex m_Layer) {
		Element::Rect obj{};
		obj.m_Transform = m_Transform;
		obj.m_Color = m_Color;
		obj.m_Layer = m_Layer;
		m_DrawList.emplace(DrawInfo{ obj.m_Layer, 0, obj.GenerateDrawData(&ctx->GetGlobalContextInfo()) });
		return obj;
	}
}