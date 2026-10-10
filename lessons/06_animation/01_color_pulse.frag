uniform float u_time;

void main(){
    float intensity = 0.5 + 0.5 * sin(u_time);
    vec4 color = vec4(intensity, 0.0, 0.0, 1.0);

    gl_FragColor = color;
}