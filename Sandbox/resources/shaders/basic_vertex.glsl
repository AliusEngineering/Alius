#version 450 core

layout(location = 0) out vec3 fragColor;

vec2 positions[3] = vec2[](
vec2(0.0, -0.5),
vec2(0.5, 0.5),
vec2(-0.5, 0.5)
);

vec3 colors[3] = vec3[](
vec3(0.533, 0.353, 0.537),
vec3(0.541, 0.659, 0.631),
vec3(0.796, 0.796, 0.831)
);

void main() {
    gl_Position = vec4(positions[gl_VertexIndex], 1.0, 1.0);
    fragColor = colors[gl_VertexIndex];
}