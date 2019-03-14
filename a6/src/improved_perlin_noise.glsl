// Given a 3d position as a seed, compute an even smoother procedural noise
// value. "Improving Noise" [Perlin 2002].
//
// Inputs:
//   st  3D seed
// Values between  -½ and ½ ?
//
// expects: random_direction, improved_smooth_step
float improved_perlin_noise( vec3 st) 
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  vec3 f = fract(st);
  vec3 smooth_f = improved_smooth_step(f);

  vec3 smallest = floor(st);
  vec3 biggest = ceil(st);

  vec3 corner1 = vec3(smallest.x, smallest.y, smallest.z);
  vec3 corner2 = vec3(biggest.x, smallest.y, smallest.z);
  vec3 corner3 = vec3(smallest.x, biggest.y, smallest.z);
  vec3 corner4 = vec3(biggest.x, biggest.y, smallest.z);
  vec3 corner5 = vec3(smallest.x, smallest.y, biggest.z);
  vec3 corner6 = vec3(biggest.x, smallest.y, biggest.z);
  vec3 corner7 = vec3(smallest.x, biggest.y, biggest.z);
  vec3 corner8 = vec3(biggest.x, biggest.y, biggest.z);

  vec3 V1 = st - corner1;
  vec3 V2 = st - corner2;
  vec3 V3 = st - corner3;
  vec3 V4 = st - corner4;
  vec3 V5 = st - corner5;
  vec3 V6 = st - corner6;
  vec3 V7 = st - corner7;
  vec3 V8 = st - corner8;

  vec3 G1 = random_direction(corner1);
  vec3 G2 = random_direction(corner2);
  vec3 G3 = random_direction(corner3);
  vec3 G4 = random_direction(corner4);
  vec3 G5 = random_direction(corner5);
  vec3 G6 = random_direction(corner6);
  vec3 G7 = random_direction(corner7);
  vec3 G8 = random_direction(corner8);

  float proj1 = dot(V1, G1); //range (-sqrt(3), sqrt(3))
  float proj2 = dot(V2, G2);
  float proj3 = dot(V3, G3);
  float proj4 = dot(V4, G4);
  float proj5 = dot(V5, G5);
  float proj6 = dot(V6, G6);
  float proj7 = dot(V7, G7);
  float proj8 = dot(V8, G8);

  float percentage = mix(mix(mix(proj1, proj2, smooth_f.x),mix(proj3, proj4, smooth_f.x), smooth_f.y),mix(mix(proj5, proj6, smooth_f.x),mix(proj7, proj8, smooth_f.x), smooth_f.y), smooth_f.z );
  return 0.5 * percentage/sqrt(3); //since dot(Vx, Gx) is in range of [-sqrt(3), sqrt(3)]
  /////////////////////////////////////////////////////////////////////////////
}

