

// 2d : https://darkpgmr.tistory.com/79
// 1. rigid transformation (3dof)
{
  Eigen::Matrix2d R;
  Eigen::Vector2d C;
  Eigen::Vector2d intput, output;
	input << x, y;
  R << cos(theta), -sin(theta),
    	sin(theta), cost(theta)
  C << x_d, y_d;
  output = R * input + C;
}
// or with homogeneous coordinate,
{
  Eigen::Matrix3d R;
  Eigen::Vector3d C;
  Eigen::Vector3d intput, output;
	input << x, y, 1;
	H << cos(theta), -sin(theta), x_d,
			sin(theta), cos(theta), y_d,
			0, 0, 1;
	output = H * input;
}
// 2. similarity transformation (4dof)
{
	// scale factor
}

// 3. affine transformation (6dof)
{
  Eigen::Matrix3d R;
  Eigen::Vector3d C;
  Eigen::Vector3d intput, output;
	float a, b, c, d, e, f;
	input << x, y, 1; // homogeneous coordinate,
	H << a * cos(theta), -b * sin(theta), c * x_d,
			d * sin(theta), e * cos(theta), f * y_d,
			0, 0, 1;
	output = H * input;
}

// solver
// if we have 3 coordinates, can define only one affine matrix
{
	affine_matrix = [](Eigen::Vector6d input) {
		x_1 = input[0];
		y_1 = input[1];
		x_2 = input[2];
		y_2 = input[3];

		before_inverse << x_1, y_1, 0, 0, 1, 0,
					0, 0, x_1, y_1, 0, 1,
					x_2, y_2, 0, 0, 1, 0,
					0, 0, x_2, y_2, 0, 1,
					x_3, y_3, 0, 0, 1, 0,
					0, 0, x_3, y_3, 0, 1;
		inverse = before_inverse.inverse()

		return inverse * output;
	}

	
}
// if more than 3 coordinates, use "pseudo inverse"


// 4. homography (projective transformation) (8dof)
H << h_1_1, h_1_2, h_1_3,
		h_2_1, h_2_2, h_2_3,
		h_3_1, h_3_2, h_3_3;



// 3d : https://darkpgmr.tistory.com/81

R_x << 1, 0, 0,
			0, cos(theta_x), -sin(theta_x),
			0, sin(theta_x), cost(theta_x);

R_y << cos(theta_y), 0, sin(theta_y),
			0, 1, 0,
			-sin(theta_y), 0, cos(theta_y);

R_z << cost(theta_z), -sin(theta_z), 0,
			sin(theta_z), cost(theta_z), 0,
			0, 0, 1;

R = R_z * R_y * R_x;

