#ifndef MATH_H
#define MATH_H

#include <array>
namespace math
{
	class Vector3
	{
	private:
		Vector3 operator-(const Vector3& vector);
		Vector3 operator+(const Vector3& vector);
	public:
		float x{};
		float y{};
		float z{};
		Vector3(float var);
		Vector3(float varX, float varY, float  varZ);
		////////// INTERFACE METHODS //////////////
		Vector3 subtract(const Vector3& vector);


	};

	class Vector2
	{
	private:
	public:
		float x{};
		float y{};
		Vector2(float var);
		Vector2(float varX, float varY);
	};

	class Mat4
	{

	private:



	public:
		Mat4();
		void subtract(const Mat4& matrix);
		void add(const Mat4& matrix);
		///////////// Scale, rotate, translate, transpose matrix ///////////////////////////////
		Mat4& rotate(const Vector3& axis, float angle);
		Mat4& scale(const Vector3& factors);
		Mat4& transpose(const Mat4& matrix);

		///////////////// matrix operations ///////////////////
		Mat4& lookAt(const Vector3& eye, Vector3& direction, const Vector3& up);


		Mat4& perspective(float fov, float aspect, float near, float far);

		void print();


		std::array<std::array<float, 4>, 4> mat4;
	};
	class Mat3
	{
	private:
	public:
		Mat3();
		void subtract(const Mat3& matrix);
		void add(const Mat3& matrix);

		void print();


		std::array<std::array<float, 3>, 3> mat3;
	};



	



/////////////// OPERATIONS ON VECTORS //////////////////
	Vector3 add(const Vector3& first, const Vector3& second);


	float dot(const Vector3& first, const Vector3& second);

	Vector3 cross(const Vector3& first, const Vector3& second);

	Vector3 normalize(const Vector3& vector);

////////////////// VECTOR 2 ////////////////////////
	Vector2 add(const Vector2& first, const Vector2& second);


	float dot(const Vector2& first, const Vector2& second);

	Vector2 cross(const Vector2& first, const Vector2& second);

	Vector2 normalize(const Vector2& vector);





//////// ADDITIONAL FUNCTIONS ///////////////
	float toRadians(float fov);
	void roundMatrix(Mat4& matrix);
}

#endif
