uniform vec2 u_resolution;

void main(){
    float radius = 100.0;
    float edge_pixel = 5.0;
    vec2 position = gl_FragCoord.xy;
    vec2 center = u_resolution * 0.5;

    vec4 color;
    float d = length(position - center);
    if (d < radius){
        color = vec4(1.0, 0.0, 0.0, 1.0);
    } 
    else if (d >= radius && d <= radius + edge_pixel){
        color = vec4(0.0, 1.0, 0.0, 1.0);
    }
    else{
        color = vec4(0.05, 0.05, 0.1, 1.0);
    }

    gl_FragColor = color;
}