/**
 * @file Math.hpp
 * @brief ���w�֘A�N���X
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#pragma once
#include <cmath>
#include <memory>


namespace ezgs
{
    /**
     * @brief 2�����x�N�g���N���X
     */
    class Vec2
    {
    public:
        float x;
        float y;

		// 0�x�N�g��
		static const Vec2 ZERO;

		Vec2()
			:x(0.0f)
			,y(0.0f)
		{}

		explicit Vec2(float x, float y)
			:x(x)
			,y(y)
		{}

		friend Vec2 operator+(const Vec2& a, const Vec2& b)
		{
			return Vec2(a.x + b.x, a.y + b.y);
		}

		friend Vec2 operator-(const Vec2& a, const Vec2& b)
		{
			return Vec2(a.x - b.x, a.y - b.y);
		}

		friend Vec2 operator*(const Vec2& vec, float scalar)
		{
			return Vec2(vec.x * scalar, vec.y * scalar);
		}

		Vec2& operator+=(const Vec2& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		float squared() const
		{
			return (x * x + y * y);
		}
	};

	/**
	 * @brief 3�����x�N�g���N���X
	 */
	class Vec3
	{
	public:
		float x;
		float y;
		float z;

		Vec3()
			:x(0.0f)
			,y(0.0f)
			,z(0.0f)
		{}

		explicit Vec3(float x, float y, float z)
			:x(x)
			,y(y)
			,z(z)
		{}
	};

	/**
	 * @brief 4x4�̍s��N���X
	 */
	class Mat4
	{
	public:
		float mat[4][4];

		// �P�ʍs��
		static const Mat4 Identity;

		/**
		 * @brief �P�ʍs��ŏ�����
		 */
		Mat4() { *this = Mat4::Identity; }

		explicit Mat4(float in_mat[4][4])
		{
			memcpy(mat, in_mat, 16 * sizeof(float));
		}

		friend Mat4 operator*(const Mat4& a, const Mat4& b)
		{
			Mat4 res;
			// Row 0
			res.mat[0][0] =
				a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0] +
				a.mat[0][2] * b.mat[2][0] + a.mat[0][3] * b.mat[3][0];

			res.mat[0][1] =
				a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1] +
				a.mat[0][2] * b.mat[2][1] + a.mat[0][3] * b.mat[3][1];

			res.mat[0][2] =
				a.mat[0][0] * b.mat[0][2] + a.mat[0][1] * b.mat[1][2] +
				a.mat[0][2] * b.mat[2][2] + a.mat[0][3] * b.mat[3][2];

			res.mat[0][3] =
				a.mat[0][0] * b.mat[0][3] + a.mat[0][1] * b.mat[1][3] +
				a.mat[0][2] * b.mat[2][3] + a.mat[0][3] * b.mat[3][3];

			// Row 1
			res.mat[1][0] =
				a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0] +
				a.mat[1][2] * b.mat[2][0] + a.mat[1][3] * b.mat[3][0];

			res.mat[1][1] =
				a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1] +
				a.mat[1][2] * b.mat[2][1] + a.mat[1][3] * b.mat[3][1];

			res.mat[1][2] =
				a.mat[1][0] * b.mat[0][2] + a.mat[1][1] * b.mat[1][2] +
				a.mat[1][2] * b.mat[2][2] + a.mat[1][3] * b.mat[3][2];

			res.mat[1][3] =
				a.mat[1][0] * b.mat[0][3] + a.mat[1][1] * b.mat[1][3] +
				a.mat[1][2] * b.mat[2][3] + a.mat[1][3] * b.mat[3][3];

			// Row 2
			res.mat[2][0] =
				a.mat[2][0] * b.mat[0][0] + a.mat[2][1] * b.mat[1][0] +
				a.mat[2][2] * b.mat[2][0] + a.mat[2][3] * b.mat[3][0];

			res.mat[2][1] =
				a.mat[2][0] * b.mat[0][1] + a.mat[2][1] * b.mat[1][1] +
				a.mat[2][2] * b.mat[2][1] + a.mat[2][3] * b.mat[3][1];

			res.mat[2][2] =
				a.mat[2][0] * b.mat[0][2] + a.mat[2][1] * b.mat[1][2] +
				a.mat[2][2] * b.mat[2][2] + a.mat[2][3] * b.mat[3][2];

			res.mat[2][3] =
				a.mat[2][0] * b.mat[0][3] + a.mat[2][1] * b.mat[1][3] +
				a.mat[2][2] * b.mat[2][3] + a.mat[2][3] * b.mat[3][3];

			// Row 3
			res.mat[3][0] =
				a.mat[3][0] * b.mat[0][0] + a.mat[3][1] * b.mat[1][0] +
				a.mat[3][2] * b.mat[2][0] + a.mat[3][3] * b.mat[3][0];

			res.mat[3][1] =
				a.mat[3][0] * b.mat[0][1] + a.mat[3][1] * b.mat[1][1] +
				a.mat[3][2] * b.mat[2][1] + a.mat[3][3] * b.mat[3][1];

			res.mat[3][2] =
				a.mat[3][0] * b.mat[0][2] + a.mat[3][1] * b.mat[1][2] +
				a.mat[3][2] * b.mat[2][2] + a.mat[3][3] * b.mat[3][2];

			res.mat[3][3] =
				a.mat[3][0] * b.mat[0][3] + a.mat[3][1] * b.mat[1][3] +
				a.mat[3][2] * b.mat[2][3] + a.mat[3][3] * b.mat[3][3];

			return res;
		}

		Mat4& operator*=(const Mat4& right)
		{
			*this = *this * right;
			return *this;
		}

		/**
		 * @brief �s��̃|�C���^�[���擾
		 */
		const float* getPointer() const { return reinterpret_cast<const float*>(&mat[0][0]); }

		/**
		 * @brief �X�P�[���s��쐬
		 */
		static Mat4 createScale(float x_scale, float y_scale, float z_scale);
		static Mat4 createScale(float scale) { return createScale(scale, scale, scale); }

		/**
		 * @brief ��]�s��쐬
		 * @param theta : ��]�p�x
		 */
		static Mat4 rotationZ(float theta);

		/**
		 * @brief ���s�ړ��s��
		 */
		static Mat4 translation(const Vec3& trans);

		/**
		 * @brief 2D�r���[�ˉe�ϊ�
		 * @param width : 2D�r���[�̕�
		 * @param height : 2D�r���[�̍���
		 */
		static Mat4 createSimpleView(float width, float height);

	};
}