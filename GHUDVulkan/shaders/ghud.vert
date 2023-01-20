#version 450

const vec2 VERTICES[4] = vec2[](
	vec2(-1.0, -1.0),
	vec2(-1.0, 1.0),
	vec2(1.0, -1.0),
	vec2(1.0, 1.0)
);

const uint INDICES[6] = uint[](
	0, 1, 2, 2, 1, 3
);

layout (location = 0) out vec2 fragUV;
layout (set = 0, binding = 0) uniform GlobalUBO {
	vec2 m_CursorCoord;
	vec2 m_ScreenSize;
	float m_AspectRatio;
	float m_InvAspectRatio;
	float m_Gamma;
	float m_InvGamma;
} ubo;

layout (push_constant) uniform Push {
	mat2 m_RotationMatrix;
	vec2 m_Position;
	vec2 m_AnchorOffset;
	vec2 m_UVOffsetA; // min
	vec2 m_UVOffsetB; // max
	vec2 m_SubUVOffsetA; // min atlas
	vec2 m_SubUVOffsetB; // max atlas
	vec4 m_Color;
	uint m_ID;
	uint m_HasTexture;
	uint m_HasInteraction;
} push;

void main() {
	uint ind = INDICES[gl_VertexIndex];
	
	vec2 position = vec2(push.m_RotationMatrix * (VERTICES[ind] + push.m_AnchorOffset) + push.m_Position);
	position.x *= ubo.m_InvAspectRatio;
	
	vec2 texCoords[4] = vec2[](
		vec2(push.m_UVOffsetB.x, push.m_UVOffsetB.y),
		vec2(push.m_UVOffsetB.x, push.m_UVOffsetA.y),
		vec2(push.m_UVOffsetA.x, push.m_UVOffsetB.y),
		vec2(push.m_UVOffsetA.x, push.m_UVOffsetA.y)
	);
	
	fragUV = texCoords[INDICES[ind]];
	gl_Position = vec4(position, 1.0, 1.0); // disabled depth test
}
