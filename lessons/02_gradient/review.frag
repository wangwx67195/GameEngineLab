uniform vec2 u_resolution;

void main(){
    float x = gl_FragCoord.x;
    float y = gl_FragCoord.y;

    float width = u_resolution.x;
    float height = u_resolution.y;

    float t_x = x / width;
    float t_y = y / height;

    vec4 red = vec4(1.0, 0.0, 0.0, 1.0);
    vec4 green = vec4(0.0, 1.0, 0.0, 1.0);

    vec4 color = vec4(red.rgb * (1.0-t_x) + green.rgb * t_x, 1.0);

    gl_FragColor = color;

}