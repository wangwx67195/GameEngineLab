uniform vec2 u_resolution;

void main(){
    vec2 center = u_resolution * 0.5;
    vec2 position = gl_FragCoord.xy;
    float d = length(position - center);
    float radius = 200.0;
    float inner_edge_half = 20.0;
    float outer_edge_half = 20.0;   
    float edge = 100.0;

    float mask_1 = smoothstep(radius - inner_edge_half, radius + inner_edge_half, d);
    //float mask_2 = step(radius + inner_edge_half, d);
    //float mask_3 = step(radius + edge - outer_edge_half, d);
    float mask_4 = smoothstep(radius + edge - outer_edge_half, radius + edge + outer_edge_half, d);

    vec4 color;

    vec4 circle = vec4(1.0, 0.0, 0.0, 1.0);
    vec4 edge_color = vec4(0.0, 1.0, 0.0, 1.0);
    vec4 bg = vec4(0.0, 0.0, 0.0, 1.0);

    color = mix(circle, edge_color, mask_1);
    color = mix(color, bg, mask_4);

    gl_FragColor = color;
}