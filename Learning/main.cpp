#include <iostream>
#include "math.h"






int main()
{
	math::Vector3 vector(1, 2, 3);
	math::Vector3 vector2(-1, 1, 3);
	math::Vector3 vector3(-1, 2, 3);

	auto result = math::cross(vector, vector2);
	vector = math::normalize(vector);



	std::cout << "Perspective matrix: \n";
	math::Mat4 mat42 = math::perspective(90.0f, 800.0f / 800.0f, 1.0f, 11.0f);
	mat42.print();


	math::Vector3 cameraPos (0.0f, 0.0f, 3.0f);
	math::Vector3 cameraTarget (0.0f, 0.0f, 0.0f);
	math::Vector3 up (0.0f, 1.0f, 0.0f);

	math::Mat4 mat4;
	std::cout << "Transposed\n";
	mat4 = math::rotate(math::Vector3(0.0, 0.0, 1.0), 90.0);
	mat4.print();

	return 0;
}