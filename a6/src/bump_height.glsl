// Create a bumpy surface by using procedural noise to generate a height (
// displacement in normal direction).
//
// Inputs:
//   is_moon  whether we're looking at the moon or centre planet
//   s  3D position of seed for noise generation
// Returns elevation adjust along normal (values between -0.1 and 0.1 are
//   reasonable.
float bump_height( bool is_moon, vec3 s)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  if (!is_moon){
    float noise = 0.1*(150*improved_perlin_noise(1*s));
    return 0.25*smooth_heaviside(noise, 25);
  }
  float noise = 0.1*(improved_perlin_noise(5*s));
  return 0.05*smooth_heaviside(noise, 50);
  /////////////////////////////////////////////////////////////////////////////
}
