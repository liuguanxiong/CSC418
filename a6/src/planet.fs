// Generate a procedural planet and orbiting moon. Use layers of (improved)
// Perlin noise to generate planetary features such as vegetation, gaseous
// clouds, mountains, valleys, ice caps, rivers, oceans. Don't forget about the
// moon. Use `animation_seconds` in your noise input to create (periodic)
// temporal effects.
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
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  mat4 model = model(is_moon, animation_seconds);
  float theta = M_PI / 2.0 * animation_seconds;
  vec4 point_light = view * vec4(4 * cos(theta), 2, 4 * sin(theta), 1);
  vec3 point_light_3d = point_light.xyz / point_light.w;
  vec3 b_sphere_fs_in = bump_position(is_moon, sphere_fs_in);
  vec3 vp = view_pos_fs_in.xyz / view_pos_fs_in.w;
  vec3 T, B;
  tangent(normalize(sphere_fs_in), T, B);
  vec3 n = normalize(cross((bump_position(is_moon, sphere_fs_in + T*0.0001) - b_sphere_fs_in)/0.0001, (bump_position(is_moon, sphere_fs_in + B*0.0001) - b_sphere_fs_in)/0.0001));
  if (dot(sphere_fs_in, n) < 0){
    n = -n;
  }
  vec3 normal = (transpose(inverse(view))*transpose(inverse(model))*vec4(n, 1.0)).xyz;

  //cloud
  float alpha = 10*sin(improved_perlin_noise(vec3(2.5*sphere_fs_in.y + sin(animation_seconds*M_PI/8),sphere_fs_in.y + sin(animation_seconds*M_PI/8), sphere_fs_in.z + cos(animation_seconds*M_PI/4))*M_PI/2.0));

  if (is_moon){
    color = blinn_phong(vec3(0.05, 0.05, 0.05),vec3(0.5, 0.5, 0.5),vec3(1, 1, 1),500,normalize(normal),normalize(-vp),normalize(point_light_3d-vp));
  }
  else{
    if (bump_height(is_moon, sphere_fs_in)<0.1){
      color = blinn_phong(vec3(0.05, 0.05, 0.05),vec3(0.2, 0.2, 0.8)*(1-alpha)+alpha*vec3(1,1,1),vec3(1, 1, 1),500,normalize(normal),normalize(-vp),normalize(point_light_3d-vp));
    }
    else{
      color = blinn_phong(vec3(0.05, 0.05, 0.05),vec3(0.2, 0.7, 0.1)*(1-alpha)+alpha*vec3(1,1,1),vec3(1, 1, 1),500,normalize(normal),normalize(-vp),normalize(point_light_3d-vp));
    }
  }
  /////////////////////////////////////////////////////////////////////////////
}
