// default.vert
void main()
{
    // gl_Vertex is transformed automatically by SFML internally
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}