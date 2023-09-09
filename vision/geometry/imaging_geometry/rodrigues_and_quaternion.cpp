// https://darkpgmr.tistory.com/99



R = [](theta, v) {
  V << 0, -v_x, v_y,
    v_z, 0, -v_x,
    -v_y, v_x, 0;
  return cos(theta) * I + sin(theta) * V + (1 - cos(theta))*v*v.transpose();
}


{
  Eigen::Vector3d p, output; // point
  Eigen::Vector3d v; // rotation axis v
  output = R(theta, v) * p;
}
  