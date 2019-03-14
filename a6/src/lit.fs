// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
out vec3 color;
// expects: PI, blinn_phong
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  float theta = M_PI / 2.0 * animation_seconds;
  vec4 point_light = view * vec4(4 * cos(theta), 2, 4 * sin(theta), 1);
  vec3 point_light_3d = point_light.xyz / point_light.w;
  vec3 vp = view_pos_fs_in.xyz / view_pos_fs_in.w;
  if (is_moon){
    color = blinn_phong(vec3(0.05, 0.05, 0.05),vec3(0.5, 0.5, 0.5),vec3(1, 1, 1),1500,normalize(normal_fs_in),normalize(-vp),normalize(point_light_3d-vp));
  }
  else{
    color = blinn_phong(vec3(0.05, 0.05, 0.05),vec3(0.2, 0.2, 0.8),vec3(1, 1, 1),1500,normalize(normal_fs_in),normalize(-vp),normalize(point_light_3d-vp));
  }
  /////////////////////////////////////////////////////////////////////////////
}
