uniform float u_time;
uniform vec2 u_resolution;

void main(){
    vec2 center = 0.5 * u_resolution;
    center.x += 100.0 * sin(u_time);
    center.y += 100.0 * cos(u_time);
    vec2 position = gl_FragCoord.xy;

    float radius = 100.0;
    float d = length(position - center);

    float mask = step(radius, d);

    vec4 circle_color = vec4(1.0, 0.0, 0.0, 1.0);
    vec4 bg_color = vec4(0.0, 0.0, 0.0, 1.0);

    vec4 color = mix(circle_color, bg_color, mask);

    gl_FragColor = color;
}