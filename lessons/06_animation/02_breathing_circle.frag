uniform float u_time;
uniform vec2 u_resolution;

void main(){
    float base_radius = 100.0;
    float amplitude = 30.0;
    float speed = 3.1415926;

    vec2 center = u_resolution * 0.5;
    vec2 position = gl_FragCoord.xy;
    float d = length(position - center);

    float radius = base_radius + amplitude * sin(speed * u_time);

    vec4 circle_color = vec4(1.0, 0.0, 0.0, 1.0);
    vec4 bg_color = vec4(0.0, 0.0, 0.0, 1.0);

    float mask = step(radius, d);
    vec4 color = mix(circle_color, bg_color, mask);

    gl_FragColor = color;

}