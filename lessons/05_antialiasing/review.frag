uniform vec2 u_resolution;

void main(){
    float radius = 200.0;
    vec2 position = gl_FragCoord.xy;
    vec2 center = u_resolution * 0.5;

    float d = length(position - center);

    float ring_width = 50.0;
    float aa_width = 20.0;

    float mask_inner_edge = smoothstep(radius - aa_width*0.5, radius + aa_width*0.5, d);
    float mask_outer_edge = smoothstep(radius + ring_width - aa_width * 0.5, radius + ring_width + aa_width * 0.5, d);

    vec4 circle_color = vec4(1.0, 0.5, 0.2, 1.0);
    vec4 ring_color = vec4(0.2, 0.9, 0.55, 1.0);
    vec4 bg_color = vec4(0.0, 0.0, 0.0, 1.0);
    
    vec4 color = mix(circle_color, ring_color, mask_inner_edge);
    color = mix(color, bg_color, mask_outer_edge);

    gl_FragColor = color;
    
}