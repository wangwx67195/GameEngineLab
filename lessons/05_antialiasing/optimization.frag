uniform vec2 u_resolution;

void main(){
    vec2 center = u_resolution * 0.5;
    vec2 position = gl_FragCoord.xy;
    float d = length(position - center);
    float radius = 200.0;
    float aa_width = 2.0; 
    float ring_width = 20.0;

    float inner_mask = smoothstep(radius - 0.5*aa_width, radius + 0.5*aa_width, d);
    float outer_mask = smoothstep(radius + ring_width - 0.5*aa_width, radius + ring_width + 0.5*aa_width, d);

    vec4 color;

    vec4 circle = vec4(1.0, 0.0, 0.0, 1.0);
    vec4 ring_color = vec4(0.0, 1.0, 0.0, 1.0);
    vec4 bg = vec4(0.0, 0.0, 0.0, 1.0);

    color = mix(circle, ring_color, inner_mask);
    color = mix(color, bg, outer_mask);

    gl_FragColor = color;
}