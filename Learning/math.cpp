#include "math.h"
#include <iostream>
#include <math.h>

constexpr float Pi{ 3.14159f };
constexpr float relEpsilon{ 1e-5 };
namespace math
{

	Vector3::Vector3(float var) : x{ var }, y{ var }, z{ var }
	{

	}

	Vector3::Vector3(float varX, float varY, float  varZ) : x{ varX }, y{ varY }, z{ varZ }
	{

	}
	Vector3 Vector3::operator-(const Vector3& vector)
	{
		return Vector3{ x - vector.x, y - vector.y, z - vector.z };
	}
	Vector3 Vector3::operator+(const Vector3& vector)
	{
		return Vector3{ x + vector.x, y + vector.y, z + vector.z };
	}
	////////// INTERFACE METHODS //////////////
	Vector3 Vector3::subtract(const Vector3& vector)
	{
		return *this - vector;
	}

	////////// VECTOR 2 ///////////////////
	Vector2::Vector2(float var) : x{ var }, y{ var }
	{

	}

	Vector2::Vector2(float varX, float varY) : x{ varX }, y{ varY }
	{

	}

	////////////// MAT4 //////////////////
	Mat4::Mat4()
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat4[i][j] = (i == j) ? 1.0f : 0.0f;
			}
		}
	}

	Mat3::Mat3()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat3[i][j] = (i == j) ? 1.0f : 0.0f;
			}
		}
	}







	/////////////// OPERATIONS ON VECTORS //////////////////
	Vector3 add(const Vector3& first, const Vector3& second)
	{
		return Vector3{ first.x + second.x, first.y + second.y, first.z + second.z };
	}


	float dot(const Vector3& first, const Vector3& second)
	{

		return first.x * second.x + first.y * second.y + first.z * second.z;
	}

	Vector3 cross(const Vector3& first, const Vector3& second)
	{
		return Vector3{ (first.y * second.z) - (first.z * second.y), -((first.x * second.z) - (first.z * second.x)), (first.x * second.y) - (first.y * second.x) };
	}

	Vector3 normalize(const Vector3& vector)
	{
		auto magnitude = std::sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));

		return Vector3{ vector.x / magnitude, vector.y / magnitude, vector.z / magnitude };
	}
	///// VECTOR 2 /////////
	Vector2 add(const Vector2& first, const Vector2& second)
	{
		return Vector2{ first.x + second.x, first.y + second.y };
	}


	float dot(const Vector2& first, const Vector2& second)
	{

		return first.x * second.x + first.y * second.y;
	}

	Vector2 cross(const Vector2& first, const Vector2& second)
	{
		return Vector2{ first.x * second.y, second.x * first.y };
	}

	Vector2 normalize(const Vector2& vector)
	{
		auto magnitude = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

		return Vector2{ vector.x / magnitude, vector.y / magnitude };
	}
	/////////// matrix operations ///////////////
	Mat4& Mat4::lookAt(const Vector3& eye, Vector3& direction, const Vector3& up)
	{
		Vector3 zAxis = normalize(direction.subtract(eye));
		Vector3 xAxis = normalize(cross(up, zAxis));
		Vector3 yAxis = cross(zAxis, xAxis);

		mat4[0][0] = xAxis.x;
		mat4[1][0] = xAxis.y;
		mat4[2][0] = xAxis.z;
		mat4[3][0] = -(dot(xAxis, eye));

		mat4[0][1] = yAxis.x;
		mat4[1][1] = yAxis.y;
		mat4[2][1] = yAxis.z;
		mat4[3][1] = -(dot(yAxis, eye));


		mat4[0][2] = zAxis.x;
		mat4[1][2] = zAxis.y;
		mat4[2][2] = zAxis.z;
		mat4[3][2] = -(dot(zAxis, eye));


		mat4[0][3] = 0.0f;
		mat4[1][3] = 0.0f;
		mat4[2][3] = 0.0f;
		mat4[3][3] = 1.0f;

		return *this;
	}

	void Mat4::add(const Mat4& matrix)
	{

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat4[i][j] += matrix.mat4[i][j];
			}
		}
	}

	void Mat4::subtract(const Mat4& matrix)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat4[i][j] -= matrix.mat4[i][j];
			}
		}
	}


	void Mat3::add(const Mat3& matrix)
	{

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat3[i][j] += matrix.mat3[i][j];
			}
		}
	}

	void Mat3::subtract(const Mat3& matrix)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				mat3[i][j] -= matrix.mat3[i][j];
			}
		}
	}
	/////////// PMV MATRICES /////////////////////////////
	Mat4& Mat4::perspective(float fov, float aspect, float near, float far)
	{

		fov = toRadians(fov);

		mat4[0][0] = 1 / (aspect * tan(fov / 2.0f));

		mat4[1][1] = 1.0f / tan(fov / 2.0f);

		mat4[2][2] = (near + far) / (near - far);

		mat4[2][3] = (2 * near * far) / (near - far);

		mat4[3][2] = -1.0f;

		mat4[3][3] = 0.0f;

		return *this;
	}

	Mat4& Mat4::scale(const Vector3& factors)
	{


		mat4[0][0] *= factors.x;
		mat4[1][1] *= factors.y;
		mat4[2][2] *= factors.z;


		return *this;
	}
	Mat4& Mat4::transpose(const Mat4& matrix)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				mat4[i][j] = matrix.mat4[j][i];
			}
		}
		return *this;
	}

	Mat4& Mat4::rotate(const Vector3& axis, float angle)
	{
		angle = toRadians(angle);
		Vector3 u = normalize(axis);
		float cosA = cos(angle);
		float sinA = sin(angle);

		mat4[0][0] = cosA + u.x * u.x * (1 - cosA); 
		mat4[0][1] = (u.x * u.y * (1 - cosA)) - u.z * sinA;
		mat4[0][2] = ((u.y * sinA) + (u.x * u.z)) * (1 - cosA);
		mat4[0][3] = 0.0f;

		mat4[1][0] = u.y * u.x * (1 - cosA) + u.z * sinA;
		mat4[1][1] = cosA + u.y * u.y * (1 - cosA);
		mat4[1][2] = u.y * u.z * (1 - cosA) - u.x * sinA;
		mat4[1][3] = 0.0f;

		mat4[2][0] = u.z * u.x * (1 - cosA) - u.y * sinA;
		mat4[2][1] = u.z * u.y * (1 - cosA) + u.x * sinA;
		mat4[2][2] = cosA + u.z * u.z * (1 - cosA);
		mat4[2][3] = 0.0f;

		mat4[3][0] = 0.0f;
		mat4[3][1] = 0.0f;
		mat4[3][2] = 0.0f;
		mat4[3][3] = 1.0f;
		roundMatrix(*this);

		return *this;

	}




///////// print matrices ////////////////////
	void Mat4::print()
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::cout << mat4[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
	void Mat3::print()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << mat3[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}

	float toRadians(float fov)
	{
		return fov * (Pi / 180.0f);
	}
	void roundMatrix(Mat4& matrix)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (matrix.mat4[i][j] <= relEpsilon && matrix.mat4[i][j] > 0)
				{
					matrix.mat4[i][j] = 0.0f;
				}
			}
		}
	}


}

