uniform vec2 u_resolution;

void main(){
    vec2 uv = gl_FragCoord.xy / u_resolution;
    vec2 p = uv - vec2(0.5, 0.5);
    float d = length(p);
    float radius = 0.2;

    vec4 color;

    //changing center
    vec2 center = vec2(0.8, 0.8);
    p = uv - center;

    //adding aspect
    float aspect = u_resolution.x / u_resolution.y;
    //p.x *= aspect;
    d = length(p);

    //thinking 2
    float scale_x = u_resolution.x / 1000.0;
    float scale_y = u_resolution.y / 1000.0;
    p.x *= aspect_w;
    p.y *= aspect_h;
    d = length(p);

    if (d < radius){
        color = vec4(1.0, 0.0, 0.0, 1.0);
    }
    else{
        color = vec4(0.0, 0.0, 0.0, 1.0);
    }

    gl_FragColor = color;
}