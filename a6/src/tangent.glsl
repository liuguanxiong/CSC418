// Input:
//   N  3D unit normal vector
// Outputs:
//   T  3D unit tangent vector
//   B  3D unit bitangent vector
void tangent(in vec3 N, out vec3 T, out vec3 B)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  vec3 t1 = cross(N, vec3(0.0, 0.0, 1.0));
  vec3 t2 = cross(N, vec3(0.0, 1.0, 0.0));
  vec3 t;
  if (length(t1) > length(t2)){
    t = t1;
  }
  else{
    t = t2;
  }
  T = normalize(t);
  B = normalize(cross(N, t));
  /////////////////////////////////////////////////////////////////////////////
}
